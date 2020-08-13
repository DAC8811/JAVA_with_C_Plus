## JAVA调用C++
基本原理就是用java平台自带的JNI（Java Native Interface）  
实现起来并不复杂但是坑比较多，同时原生的JNI仅支持对于C/C++函数的调用而不支持对C++类的直接调用，因此还需要进一步实现java对C++自定义类的调用
