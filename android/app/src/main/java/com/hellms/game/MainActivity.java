package com.hellms.game;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.TextView;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("hellms");
    }

    /** Returns the native build description (ABI, version). */
    private native String nativeVersion();

    /** Starts the native game core and returns its status message. */
    private native String nativeStart();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Fullscreen, keep the screen awake while the game is running
        getWindow().setFlags(
                WindowManager.LayoutParams.FLAG_FULLSCREEN
                        | WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
                WindowManager.LayoutParams.FLAG_FULLSCREEN
                        | WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        // Hide the navigation bar decorations where available
        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                        | View.SYSTEM_UI_FLAG_FULLSCREEN
                        | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_LAYOUT_STABLE);

        setContentView(R.layout.activity_main);

        TextView version = findViewById(R.id.version_text);
        TextView status = findViewById(R.id.status_text);

        try {
            version.setText(nativeVersion());
            status.setText(nativeStart());
        } catch (UnsatisfiedLinkError error) {
            version.setText("native library not loaded");
            status.setText(error.toString());
        }
    }
}
