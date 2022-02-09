用法（例如要运行Dinic.cpp)
	make FILE=Dinic run
开启DEBUG
	make FILE=Dinic DEBUG=ON run
	然后在源代码中使用预处理语句 #ifdef __DEBUG__ON
	默认定义了 __DEBUG__OFF
