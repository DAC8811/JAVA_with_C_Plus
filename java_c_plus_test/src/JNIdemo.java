
public class JNIdemo {
    private long nativeCdemo;
    public JNIdemo(){
        System.loadLibrary("javaCdll");
        nativeCdemo = createNativeObject();
    }
    public void setAge(int age){
        nativeSetAge(nativeCdemo,age);
    }
    public int getAge(){
        return nativeGetAge(nativeCdemo);
    }
    public native void testHello();
    public native int testPrint(int num);
    public native long createNativeObject();
    public native void nativeSetAge(long addr,int age);
    public native int nativeGetAge(long addr);
}
