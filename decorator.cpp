/*************************************************************************
	> File Name: decorator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 16时55分29秒
 ************************************************************************/
//装饰器模式
#include<iostream>
using namespace std;

//公共抽象类
class Phone {
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void showDecorate() {}
};

//具体的手机类
class iPhone:public Phone {
private:
    string m_name; //手机名称
public:
    iPhone(string name):m_name(name) {}
    ~iPhone() {}
    void showDecorate() {
        cout << m_name << "的装饰" << endl;
    }
};

//具体的手机类
class NokiaPhone:public Phone {
private:
    string m_name;
public:
    NokiaPhone(string name):m_name(name) {}
    ~NokiaPhone() {}
    void showDecorate() {
        cout << m_name << "的装饰" << endl;
    }
};

//装饰类
class DecoratorPhone:public Phone {
private:
    Phone *m_phone; //要装饰的手机
public:
    DecoratorPhone(Phone *phone):m_phone(phone) {}
    virtual void showDecorate() {
        m_phone->showDecorate();
    }
};

//具体的装饰类
class DecoratorPhoneA:public DecoratorPhone {
public:
    DecoratorPhoneA(Phone *phone):DecoratorPhone(phone) {}
    void showDecorate() {
        DecoratorPhone::showDecorate();
        addDecorate();
    }
private:
    void addDecorate() {
        cout << "增加挂件" << endl;  //增加装饰
    }
};

//具体的装饰类
class DecoratorPhoneB:public DecoratorPhone {
public:
    DecoratorPhoneB(Phone *phone):DecoratorPhone(phone) {}
    void showDecorate() {
        DecoratorPhone::showDecorate();
        addDecorate();
    }
private:
    void addDecorate() {
        cout << "屏幕贴膜" << endl;
    }
};

int main(int argc, char **argv)
{
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone); //装饰,增加挂件
    Phone *dpb = new DecoratorPhoneB(dpa); //装饰,屏幕贴膜
    dpb->showDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
    return 0;
}
