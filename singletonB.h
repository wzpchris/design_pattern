/*************************************************************************
	> File Name: singletonB.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时24分58秒
 ************************************************************************/

#ifndef _SINGLETONB_H
#define _SINGLETONB_H
#include "singleton.h"
class SingletonB:public Singleton {
    //必须为友元类,否则父类无法访问子类的构造函数
    friend class Singleton;
public:
    void show() { cout << "SingletonB" << endl; }
private: //为保护属性,这样外界无法通过构造函数进行实例化
    SingletonB() {}
};
#endif
