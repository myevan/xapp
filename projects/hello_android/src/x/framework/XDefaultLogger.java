package x.framework;

import java.lang.Throwable;
import java.lang.StackTraceElement;

public class XDefaultLogger
{
    public static void Debugn(String text) {
        StackTraceElement[] stackTraces = new Throwable().getStackTrace();
        StackTraceElement stackTrace = stackTraces[1];
        Debugn(
            text,
            stackTrace.getClassName(), 
            stackTrace.getLineNumber(), 
            stackTrace.getMethodName());
    }

    public static native void Debugn(String text, String filePath, int lineIndex, String funcName);

    static {
        System.loadLibrary("x_interface");
    }
}
