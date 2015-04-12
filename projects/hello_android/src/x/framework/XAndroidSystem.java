package x.framework;

public class XAndroidSystem
{
    public static native String GetABIName();

    static {
        System.loadLibrary("x_interface");
    }
}
