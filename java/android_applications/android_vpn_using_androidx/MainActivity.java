public class MainActivity extends AppCompatActivity {

  private static final int
  private static final int REQUEST_CODE_AUTHENTICATE = 100;
  private static final String KEY_ALIAS = "my_key_alias";

  @Override
  protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.activity_main);

      Button button = findViewById(R.id.button);
      button.setOnClickListener(view -> authenticate());
  }

  private void authenticate() {
      BiometricManager biometricManager = BiometricManager.from(this);
      if (biometricManager.canAuthenticate() != BiometricManager.BIOMETRIC_SUCCESS) {
          Toast.makeText(this, "Biometric authentication not available", Toast.LENGTH_SHORT).show();
          return;
      }

      KeyguardManager keyguardManager = getSystemService(KeyguardManager.class);
      if (!keyguardManager.isKeyguardSecure()) {
          Toast.makeText(this, "Device lock screen not enabled", Toast.LENGTH_SHORT).show();
          return;
      }

      KeyStore keyStore = getKeyStore();
      if (keyStore == null) {
          Toast.makeText(this, "Key store not available", Toast.LENGTH_SHORT).show();
          return;
      }

      Cipher cipher = getCipher();
      if (cipher == null) {
          Toast.makeText(this, "Cipher not available", Toast.LENGTH_SHORT).show();
          return;
      }

      BiometricPrompt.PromptInfo promptInfo = new BiometricPrompt.PromptInfo.Builder()
              .setTitle("Authentication required")
              .setSubtitle("Confirm biometric authentication to connect to VPN")
              .setAllowedAuthenticators(BiometricManager.Authenticators.BIOMETRIC_STRONG)
              .build();

      BiometricPrompt biometricPrompt = new BiometricPrompt(this, new BiometricPrompt.AuthenticationCallback() {
          @Override
          public void onAuthenticationSucceeded(BiometricPrompt.AuthenticationResult result) {
              connectToVpn();
          }

          @Override
          public void onAuthenticationError(int errorCode, CharSequence errString) {
              super.onAuthenticationError(errorCode, errString);
              Toast.makeText(MainActivity.this, "Authentication error: " + errString, Toast.LENGTH_SHORT).show();
          }
      });

      biometricPrompt.authenticate(promptInfo, new BiometricPrompt.CryptoObject(cipher));
  }

  private KeyStore getKeyStore() {
      try {
          KeyStore keyStore = KeyStore.getInstance("AndroidKeyStore");
          keyStore.load(null);
          if (!keyStore.containsAlias(KEY_ALIAS)) {
              KeyGenerator keyGenerator = KeyGenerator.getInstance(KeyProperties.KEY_ALGORITHM_AES, "AndroidKeyStore");
              KeyGenParameterSpec keyGenParameterSpec = new KeyGenParameterSpec.Builder(KEY_ALIAS, KeyProperties.PURPOSE_ENCRYPT | KeyProperties.PURPOSE_DECRYPT)
                      .setBlockModes(KeyProperties.BLOCK_MODE_CBC)
                      .setEncryptionPaddings(KeyProperties.ENCRYPTION_PADDING_PKCS7)
                      .setUserAuthenticationRequired(true)
                      .build();
              keyGenerator.init(keyGenParameterSpec);
              keyGenerator.generateKey();
          }
          return keyStore;
      } catch (Exception e) {
          e.printStackTrace();
          return null;
      }
  }

  private Cipher getCipher() {
      try {
          KeyStore keyStore = getKeyStore();
          if (keyStore == null) {
              return null;
          }

          SecretKey secretKey = (SecretKey) keyStore.getKey(KEY_ALIAS, null);
          Cipher cipher = Cipher.getInstance(KeyProperties.KEY_ALGORITHM_AES + "/" + KeyProperties.BLOCK_MODE_CBC + "/" + KeyProperties.ENCRYPTION_PADDING_PKCS7);
          cipher.init(Cipher.ENCRYPT_MODE, secretKey);
          return cipher;
      } catch (Exception e) {
          e.printStackTrace();
          return null;
      }
  }

  private void connectToVpn() {
      Intent intent = VpnService.prepare(this);
          if (intent != null) {
          startActivityForResult(intent, REQUEST_CODE_PREPARE);
      } else {
          onActivityResult(REQUEST_CODE_PREPARE, RESULT_OK, null);
      }
  }

  @Override
  protected void onActivityResult(int requestCode, int resultCode, Intent data) {
      if (requestCode == REQUEST_CODE_PREPARE) {
          if (resultCode == RESULT_OK) {
              startService(new Intent(this, VpnService.class));
          } else {
              Toast.makeText(this, "VPN connection canceled", Toast.LENGTH_SHORT).show();
          }
      } else if (requestCode == REQUEST_CODE_AUTHENTICATE) {
          if (resultCode == RESULT_OK) {
              connectToVpn();
          } else {
              Toast.makeText(this, "Authentication failed", Toast.LENGTH_SHORT).show();
          }
      }
  }

  public static class VpnService extends android.net.VpnService implements Handler.Callback, Runnable {
    private static final String VPN_ADDRESS = "10.0.0.2";
    private static final String VPN_ROUTE = "0.0.0.0";
    private static final String VPN_DNS_SERVER = "8.8.8.8";
    private static final int VPN_MTU = 1500;
    private static final String VPN_USERNAME = "user";
    private static final String VPN_PASSWORD = "password";

    private Handler handler;
    private DatagramChannel vpnChannel;
    private Selector selector;
    private boolean isRunning;

    @Override
    public void onCreate() {
        super.onCreate();
        handler = new Handler(this);
        new Thread(this).start();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        isRunning = false;
        if (vpnChannel != null) {
            try {
                vpnChannel.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (selector != null) {
            try {
                selector.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        Toast.makeText(this, "VPN disconnected", Toast.LENGTH_SHORT).show();
    }

    @Override
    public boolean handleMessage(@NonNull Message message) {
        if (message.what == 1) {
            Toast.makeText(this, "VPN connected", Toast.LENGTH_SHORT).show();
        }
        return true;
    }

    @Override
    public synchronized void run() {
      try {
          isRunning = true;
          setupVpn();
          while (isRunning) {
              int readyChannels = selector.select();
              if (readyChannels == 0) {
                  continue;
              }

              Iterator<SelectionKey> keyIterator = selector.selectedKeys().iterator();
              while (keyIterator.hasNext()) {
                  SelectionKey key = keyIterator.next();
                  if (key.isValid() && key.isReadable()) {
                      handleInput(key);
                  }
                  keyIterator.remove();
              }
          }
      } catch (Exception e) {
          e.printStackTrace();
      } finally {
          if (vpnChannel != null) {
              try {
                  vpnChannel.close();
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          if (selector != null) {
              try {
                  selector.close();
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
      }
    }

    private void setupVpn() throws Exception {
      vpnChannel = DatagramChannel.open();
      vpnChannel.configureBlocking(false);

      builder.setSession(VPN_USERNAME)
              .addAddress(VPN_ADDRESS, 32)
              .addRoute(VPN_ROUTE, 0)
              .addDnsServer(VPN_DNS_SERVER)
              .setMtu(VPN_MTU);

      List<String> allowedApps = new ArrayList<>();
      allowedApps.add(getPackageName());
      builder.addAllowedApplication(getPackageName());

      if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
          builder.addAllowedApplication("com.android.vending");
      }

      builder.addDisallowedApplication("com.android.chrome");

      builder.setConfigureIntent(PendingIntent.getActivity(this, 0, new Intent(this, MainActivity.class),
              PendingIntent.FLAG_UPDATE_CURRENT));

      builder.setPermission(Manifest.permission.BIND_VPN_SERVICE);

      builder.setBlocking(true);

      builder.setUnderlyingNetworks(null);

      builder.setAlwaysOn(true);

      builder.allowBypass();

      builder.setMetered(false);

      builder.setProxy(null);

      builder.setTransportInfo(TRANSPORT_WIFI);

      builder.setTunnelingAllowed(true);

      builder.setNamespace(new NetworkNamespace() {
          @Override
          public boolean isPrivateDnsQueryAllowed() {
              return true;
          }

          @Override
          public boolean protectFromVpn(VpnInfo vpnInfo) {
              return true;
          }
      });

      builder.setUserAuthenticationRequired(true);
      builder.setCredential(new BasicCredential(VPN_USERNAME, VPN_PASSWORD.toCharArray()));

      setProfileName("My VPN Profile");
      setProfile(builder.build());

      selector = Selector.open();
      vpnChannel.register(selector, SelectionKey.OP_READ);

      handler.sendEmptyMessage(1);
    }

    private void handleInput(SelectionKey key) throws IOException {
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        DatagramChannel channel = (DatagramChannel) key.channel();

        int readBytes = channel.read(buffer);
        if (readBytes > 0) {
            buffer.flip();
            byte[] data = new byte[buffer.remaining()];
            buffer.get(data);

            Log.d("VPN", "Received: " + new String(data));

            InetSocketAddress destinationAddress = (InetSocketAddress) key.attachment();
            if (destinationAddress != null) {
                Log.d("VPN", "Sending: " + new String(data));
                ByteBuffer outputBuffer = ByteBuffer.wrap(data);
                vpnChannel.send(outputBuffer, destinationAddress);
            }
        }
    }

    public void sendPacket(InetSocketAddress destinationAddress, byte[] data) {
      ByteBuffer buffer = ByteBuffer.allocate(data.length);
      buffer.put(data);
      buffer.flip();

      try {
          selector.wakeup();
          vpnChannel.send(buffer, destinationAddress);
          vpnChannel.register(selector, SelectionKey.OP_READ, destinationAddress);
      } catch (IOException e) {
          e.printStackTrace();
      }
    }
  }
}
