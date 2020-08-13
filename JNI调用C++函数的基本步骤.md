## 1.编写java代码
在java程序中使用 __native__ 关键字来描述调用C++函数的java方法，例如  
`public native void testHello();`  
同时，因为本文采用加载dll动态库的方式引入C++程序，所以在调用C++函数前必须首先导入dll库  
### 写法1
`System.loadLibrary("XXX")`其中`XXX`为dll文件名称，不需要加后缀  
并且需要在IDE或直接在JDK中添加dll文件所在路径  
### 写法2
`System.loadLibrary("XX/XXX.dll")`写入完整路径
## 2.使用java代码生成C++头文件
生成指令如下  
`javah -classpath . -jni XXX`其中`XXX`为完整的java类名（包括包名）  
这一步将会生成.h头文件
## 3.新建dll工程
将第二步中生成的头文件加入工程中，同时还需要加入jdk/include目录下的jni.h文件以及jdk/include/win32目录下的jni_md.h文件    
同时将第二步生成的.h文件中的`#include <jni.h>`改为`#include "jni.h"`，此时dll工程报错应该消失了  
## 4.编写C++代码
新建cpp文件编写头文件中函数的函数体  
值得注意的是以第一步中的`testhello()`函数为例，则生成头文件中对应函数名应为  
`JNIEXPORT void JNICALL Java_JNIdemo_testHello(JNIEnv *, jobject);`  
其中两个参数为自动生成和传入的参数，不需要在函数体中修改  
如果在java代码中的函数有传入和传出的参数，则C++头文件中将会将对应参数类型转换为C++类型，如  
java中的`int`转换为C++中的`jint`  
## 5.编译dll动态库
需要注意的是编译的dll动态库的位数必须和jdk匹配，否则将报错  
## 6.编译进行java程序
若一切正常，则可以看到程序命令行打印C++代码中对应内容
