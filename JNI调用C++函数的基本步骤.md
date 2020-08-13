## 编写java程序
在java程序中使用 __native__ 关键字来描述调用C++函数的java方法，例如  
`public native void testHello();`  
同时，因为本文采用加载dll动态库的方式引入C++程序，所以在调用C++函数前必须首先导入dll库  
`System.loadLibrary("XXX")`其中`XXX`为dll文件名称，不需要加后缀  
并且需要在IDE或直接在JDK中添加dll文件所在路径  
