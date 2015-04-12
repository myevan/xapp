package x.framework;

import java.lang.Throwable;
import java.lang.StackTraceElement;

public class XDefaultLogger
{
    public static void Debugn(String text) {
        StackTraceElement[] stackTraces = new Throwable().getStackTrace();
        StackTraceElement stackTrace = stackTraces[1];
        Debugn(
            stackTrace.getClassName(), 
            stackTrace.getLineNumber(), 
            stackTrace.getMethodName(),
            text);
    }

    public static native void Debugn(String filePath, int lineIndex, String funcName, String text);

    static {
        System.loadLibrary("x_interface");
    }
}
