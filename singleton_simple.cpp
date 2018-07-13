/*************************************************************************
	> File Name: singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时04分59秒
 ************************************************************************/
//单例模式
#include <iostream>
using namespace std;
#include "singleton.h"

Singleton *Singleton::singleton = NULL;
Singleton *Singleton::getInstance() {
    if(NULL == singleton)
    {
        singleton = new Singleton();
    }
    return singleton;
}
