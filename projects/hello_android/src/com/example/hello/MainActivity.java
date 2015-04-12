package com.example.hello;

import x.framework.XBaseConfig;
import x.framework.XAndroidSystem;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        // setContentView(R.layout.main);

        TextView  tv = new TextView(this);
        tv.setText(XBaseConfig.GetTitle() + ":" + XAndroidSystem.GetABIName());
        setContentView(tv);
    }
}
