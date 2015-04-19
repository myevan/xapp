package x.framework;

import java.lang.Throwable;
import java.lang.StackTraceElement;

public class XDefaultLogger
{
    public static void Debug(String text) {
        StackTraceElement[] stackTraces = new Throwable().getStackTrace();
        StackTraceElement stackTrace = stackTraces[1];
        Debug(
            text,
            stackTrace.getClassName(), 
            stackTrace.getLineNumber(), 
            stackTrace.getMethodName());
    }

    public static native void Debug(String text, String filePath, int lineIndex, String funcName);

    static {
        System.loadLibrary("x_interface");
    }
}
