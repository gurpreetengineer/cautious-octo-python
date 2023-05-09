import android.app.Activity;
import android.content.Intent;
import android.net.VpnService;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

  private TextView statusText;
  private Button connectButton;

  private boolean isConnected = false;

  private static final int VPN_REQUEST_CODE = 0x0F;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    statusText = findViewById(R.id.status_text);
    connectButton = findViewById(R.id.connect_button);

    connectButton.setOnClickListener(
      new View.OnClickListener() {
        @Override
        public void onClick(View v) {
          if (!isConnected) {
            startVPN();
          } else {
            stopVPN();
          }
        }
      }
    );
  }

  private void startVPN() {
    Intent intent = VpnService.prepare(MainActivity.this);
    if (intent != null) {
      startActivityForResult(intent, VPN_REQUEST_CODE);
    } else {
      onActivityResult(VPN_REQUEST_CODE, RESULT_OK, null);
    }
  }

  private void stopVPN() {
    // Disconnect from VPN
    // ...

    isConnected = false;
    statusText.setText("Disconnected");
    connectButton.setText("Connect");
  }

  @Override
  protected void onActivityResult(
    int requestCode,
    int resultCode,
    Intent data
  ) {
    if (requestCode == VPN_REQUEST_CODE && resultCode == RESULT_OK) {
      // Start VPN
      // ...

      isConnected = true;
      statusText.setText("Connected");
      connectButton.setText("Disconnect");
    }
  }
}
