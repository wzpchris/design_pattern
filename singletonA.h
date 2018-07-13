/*************************************************************************
	> File Name: SingletonA.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时21分47秒
 ************************************************************************/

#ifndef _SINGLETONA_H
#define _SINGLETONA_H
#include "singleton.h"
class SingletonA:public Singleton {
    //必须为友元类,否则父类方法中无法访问子类的构造函数
    friend class Singleton; 
public:
    void show() { cout << "SingletonA" << endl; }
private: //为保护属性,这样外界无法通过构造函数进行实例化
    SingletonA() {}
};
#endif
