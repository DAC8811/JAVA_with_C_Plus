
public class JNItest {
    public static void main(String[] args){
        //System.loadLibrary("TestJNI");
        JNIdemo jnIDemo = new JNIdemo();
        jnIDemo.testHello();
        int num = 10;
        System.out.println(jnIDemo.getAge());
        jnIDemo.setAge(num);
        System.out.println(jnIDemo.getAge());
    }
}
