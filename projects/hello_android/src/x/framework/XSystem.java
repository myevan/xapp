package x.framework;

import android.content.res.AssetManager;

public class XSystem
{
    public static native String GetABIName();
    public static native void BindAssetManager(AssetManager assetManager);

    static {
        System.loadLibrary("x_interface");
    }
}
