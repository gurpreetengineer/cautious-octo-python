public class MyVpnService extends VpnService {

    private static final String VPN_ADDRESS = "10.0.0.2";
    private static final String VPN_ROUTE = "0.0.0.0";
    private static final int VPN_MTU = 1500;

    private ParcelFileDescriptor mInterface;
    private ExecutorService mExecutor;

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        mExecutor = Executors.newSingleThreadExecutor();
        mExecutor.submit(this::run);
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        mExecutor.shutdown();
        super.onDestroy();
    }

    private void run() {
        try {
            mInterface = establishVpn();
            while (mInterface != null) {
                // read and filter traffic
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeVpn();
        }
    }

    private ParcelFileDescriptor establishVpn() throws Exception {
        Builder builder = new Builder();
        builder.setSession(getString(R.string.app_name));
        builder.addAddress(VPN_ADDRESS, 24);
        builder.addRoute(VPN_ROUTE, 0);
        builder.setMtu(VPN_MTU);
        builder.addDnsServer("8.8.8.8");
        builder.addDnsServer("8.8.4.4");
        builder.setBlocking(true);
        builder.setConfigureIntent(PendingIntent.getActivity(this, 0, new Intent(this, MainActivity.class), 0));
        return builder.establish();
    }

    private void closeVpn() {
        try {
            if (mInterface != null) {
                mInterface.close();
                mInterface = null;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
