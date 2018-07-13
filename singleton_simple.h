/*************************************************************************
	> File Name: singleton.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 08时06分33秒
 ************************************************************************/
//单例模式
#ifndef _SINGLETON_H
#define _SINGLETON_H
class Singleton {
public:
    static Singleton *getInstance();
private:
    Singleton() {}
    static Singleton *singleton;
};
#endif
