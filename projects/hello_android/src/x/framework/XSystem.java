package x.framework;

public class XSystem
{
    public static native String GetABIName();

    static {
        System.loadLibrary("x_interface");
    }
}
