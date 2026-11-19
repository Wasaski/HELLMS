package com.hellms.game;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view-ColoredWindowManager;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Set fullscreen
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
        // Set content to nothing - will be replaced by native code
        setContentView(R.layout.activity_main);
    }
}
