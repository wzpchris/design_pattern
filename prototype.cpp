/*************************************************************************
	> File Name: prototype.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 11时00分07秒
 ************************************************************************/
//原型模式
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//父类
class Resume {
protected:
    char *name;
public:
    Resume() {}
    virtual ~Resume() {}
    virtual Resume* clone() { return NULL; }
    virtual void set(char *n) {}
    virtual void show() {}
};

class ResumeA:public Resume {
public:
    ResumeA(const char *str); //构造函数
    ResumeA(const ResumeA &r); //拷贝构造函数
    ~ResumeA(); //析构函数
    ResumeA* clone(); //克隆,关键所在
    void show(); //显式内容
};

ResumeA::ResumeA(const char *str)
{
    if(NULL == str)
    {
        name = new char[1];
        name[0] = '\0';
    }else {
        name = new char(strlen(str) + 1);
        strcpy(name, str);
    }
}

ResumeA::~ResumeA() { delete[] name; }
ResumeA::ResumeA(const ResumeA &r) {
    name = new char[strlen(r.name) + 1];
    strcpy(name, r.name);
}

ResumeA* ResumeA::clone()
{
    return new ResumeA(*this);
}

void ResumeA::show(){
    cout << "ResumeA name:" << name << endl;
}

class ResumeB:public Resume {
public:
    ResumeB(const char *str); //构造函数
    ResumeB(const ResumeB &r); //拷贝构造函数
    ~ResumeB(); //析构函数
    ResumeB* clone(); //克隆,关键所在
    void show(); //显式内容
};

ResumeB::ResumeB(const char *str)
{
    if(NULL == str)
    {
        name = new char[1];
        name[0] = '\0';
    }else {
        name = new char(strlen(str) + 1);
        strcpy(name, str);
    }
}

ResumeB::~ResumeB() { delete[] name; }
ResumeB::ResumeB(const ResumeB &r) {
    name = new char[strlen(r.name) + 1];
    strcpy(name, r.name);
}

ResumeB* ResumeB::clone()
{
    return new ResumeB(*this);
}

void ResumeB::show(){
    cout << "ResumeB name:" << name << endl;
}


int main(int argc, char** argv)
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->clone();
    Resume *r4 = r2->clone();
    r1->show();
    r2->show();
    //删除r1,r2
    delete r1;
    delete r2;
    r1 = r2 = NULL;

    //深拷贝所以对r3,r4无影响
    r3->show();
    r4->show();
    delete r3;
    delete r4;
    r3 = r4 = NULL;
    return 0;
}
