/*************************************************************************
	> File Name: singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时27分33秒
 ************************************************************************/
//单例模式
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "singleton.h"
#include "singletonA.h"
#include "singletonB.h"

Singleton *Singleton::singleton = NULL;
Singleton *Singleton::getInstance(const char *name)
{
    if(NULL == singleton)
    {
        if(strcmp(name, "SingletonA") == 0)
        {
            singleton = new SingletonA();
        }else if(strcmp(name, "SingletonB") == 0)
        {
            singleton = new SingletonB();
        }else {
            singleton = new Singleton();
        }
    }

    return singleton;
}

int main(int argc, char** argv)
{
    Singleton *st = Singleton::getInstance("SingletonA");
    st->show();

    Singleton st_copy(*st);
    st_copy.show();
    return 0;
}

//1.需要注意的是这里的父类方法调用子类的构造函数，是通过将父类声明为子类的友元
//2.这种方式实现的单例模式，当需要多个单例时，可能需要修改代码，违反了开闭原则
