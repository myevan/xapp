package com.example.hello;

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
        setContentView(R.layout.main);

        TextView  tv = new TextView(this);
        tv.setText(XInformationGetTitle() + ":" + XAndroidSystemGetABIName());
        setContentView(tv);
    }

    public static native String XAndroidSystemGetABIName();
    public static native String XInformationGetTitle();

    static {
        System.loadLibrary("x_interface");
    }
}