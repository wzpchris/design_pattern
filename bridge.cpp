/*************************************************************************
	> File Name: bridge.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 16时27分00秒
 ************************************************************************/
//桥接模式
#include<iostream>
using namespace std;

//操作系统
class OS {
public:
    virtual void installOS_Imp() {};
};

class WindowOS:public OS{
public:
    void installOS_Imp() {
        cout << "安装Window操作系统" << endl;
    }
};

class LinuxOS:public OS{
public:
    void installOS_Imp() {
        cout << "安装Linux操作系统" << endl;
    }
};

class UnixOS:public OS {
public:
    void installOS_Imp() {
        cout << "安装Unix操作系统" << endl;
    }
};

//计算机
class Computer {
public:
    virtual void installOS(OS *os) {}
};

class DellComputer:public Computer {
public:
    void installOS(OS *os)
    {
        os->installOS_Imp();
    }
};

class AppleComputer:public Computer {
public:
    void installOS(OS *os)
    {
        os->installOS_Imp();
    }
};

class HPComputer:public Computer {
public:
    void installOS(OS *os)
    {
        os->installOS_Imp();
    }
};

int main(int argc, char **argv)
{
    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();

    Computer *c = new AppleComputer();
    c->installOS(os1);
    c->installOS(os2);
    return 0;
}
