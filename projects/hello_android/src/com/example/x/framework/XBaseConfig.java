package com.example.x.framework;

public class XBaseConfig
{
    public static native String GetTitle();

    static {
        System.loadLibrary("x_interface");
    }
}
