package x.framework;

public class XLoggerManager
{
    public static native void Printn(String text);

    static {
        System.loadLibrary("x_interface");
    }
}
