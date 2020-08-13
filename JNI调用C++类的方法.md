使用JNI调用C++函数时，本质上就是在运行java代码的同时为C++代码开辟了一块空间，使两者共存   
其中C++代码段的生命周期应当与java程序相同，因此可以考虑在java程序中存储C++对象的具体地址，来实现对C++类的调用  
而C++代码中所使用的指针，本质上就是使用变量存储数据地址来实现的  
因此，考虑在java代码中使用`long`型变量存储C++对象地址  
## 实现方式
以自定义java类`JNIdemo`以及自定义C++类`CplusDemo`为例  
### JNIdemo类中
定义变量`private long nativeCdemo;`用于存储C++对象地址
定义函数`public native long createNativeObject();`用于调用C++类创建实例并返回C++对象地址
同时在JNIdemo构造函数中调用该函数并获取C++对象地址  
`nativeCdemo = createNativeObject();`  
### C++代码对应的java接口函数中
```
JNIEXPORT jlong JNICALL Java_JNIdemo_createNativeObject  
(JNIEnv*, jobject) {  
  jlong res = NULL;  
  res = (jlong)new CplusDemo();  
  return res;  
}
```
