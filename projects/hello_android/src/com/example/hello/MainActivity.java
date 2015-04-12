package com.example.hello;

import x.framework.XSystem;
import x.framework.XBaseConfig;
import x.framework.XDefaultLogger;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import android.content.res.AssetManager;

public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        XDefaultLogger.Debugn("test");

        XDefaultLogger.Debugn("bind");

        AssetManager assetManager = getAssets();
        XSystem.BindAssetManager(assetManager);

        XDefaultLogger.Debugn("show");

        TextView  tv = new TextView(this);
        tv.setText(XBaseConfig.GetTitle() + ":" + XSystem.GetABIName());
        setContentView(tv);
    }
}
