#ifndef A_H
#define A_H

class A {
	// C98中会报出error，只有静态常量成员才可以在类中初始化
	// C11中可以
     const int a = 5;  
};

#endif
