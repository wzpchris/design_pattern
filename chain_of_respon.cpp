/*************************************************************************
	> File Name: chain_of_respon.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 19时49分40秒
 ************************************************************************/
//职责连模式
#include<iostream>
using namespace std;

class Manager {
protected:
    Manager *m_manager;
    string m_name;
public:
    Manager(Manager *manager, string name):m_manager(manager), m_name(name) {}
    virtual void dealWithRequest(string name, int num) {}
};

//经理
class CommonManager:public Manager {
public:
    CommonManager(Manager *manager, string name):Manager(manager,name){}
    void dealWithRequest(string name, int num) {
        if(num < 500) //经理职权之内
        {
            cout << "经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<< endl << endl;;
        }else {
            cout << "经理"<<m_name<<"无法处理,交由总监处理"<<endl;
            m_manager->dealWithRequest(name,num);
        }
    }
};

//总监
class Majordomo:public Manager {
public:
    Majordomo(Manager *manager,string name):Manager(manager,name) {}
    void dealWithRequest(string name, int num)
    {
        if(num < 1000) //总监职权之内
        {
            cout<<"总监"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl << endl;
        }else {
            cout<<"总监"<<m_name<<"无法处理,交由经理处理"<<endl;
            m_manager->dealWithRequest(name,num);
        }
    }
};

//总经理
class GeneralManager:public Manager {
public:
    GeneralManager(Manager *manager,string name):Manager(manager,name){}
    void dealWithRequest(string name, int num)
    {
        cout<<"总经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl << endl;
    }
};

int main(int argc, char **argv)
{
    Manager *general = new GeneralManager(NULL, "A"); //设置上级,总经理没有上级
    Manager *majordomo = new Majordomo(general, "B"); //设置上级
    Manager *common = new CommonManager(majordomo, "C"); //设置上级
    common->dealWithRequest("D", 300);
    common->dealWithRequest("E", 600);
    common->dealWithRequest("F", 1000);
    delete common;
    delete majordomo;
    delete general;
    return 0;
}


