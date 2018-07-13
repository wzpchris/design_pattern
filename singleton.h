/*************************************************************************
	> File Name: singleton.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时19分23秒
 ************************************************************************/
//单例模式
#ifndef _SINGLETON_H
#define _SINGLETON_H
class Singleton {
public:
    static Singleton *getInstance(const char *name);
    virtual void show() { cout << "Singleton" << endl; }
protected: //必须为保护的,如果是私有属性,子类无法访问父类的构造函数
    Singleton() {}
private:
    static Singleton *singleton;
};
#endif
