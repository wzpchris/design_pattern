/*************************************************************************
	> File Name: composite.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 14时08分27秒
 ************************************************************************/
//组合模式:将对象组合成树型结构
#include<iostream>
#include <list>
using namespace std;

class Company {
public:
    Company(string name):m_name(name) {}
    virtual ~Company() {}
    virtual void add(Company *pCom) {}
    virtual void show(int depth) {}
protected:
    string m_name;
};

//具体公司
class ConcreteCompany:public Company {
public:
    ConcreteCompany(string name):Company(name) {}
    virtual ~ConcreteCompany() {}
    void add(Company *pCom) {
        //位于树的中间,可以增加子树
        m_listCompany.push_back(pCom);
    }

    void show(int depth)
    {
        for(int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
        list<Company*>::iterator iter = m_listCompany.begin();
        //显示下层结点
        for(; iter != m_listCompany.end(); ++iter)
        {
            (*iter)->show(depth + 2);
        }
    }
private:
    list<Company*> m_listCompany;
};

//具体的部门,财务部
class FinanceDepartment:public Company {
public:
    FinanceDepartment(string name):Company(name) {}
    virtual ~FinanceDepartment() {}
    virtual void show(int depth) //只需显示,无添加函数,因为已是叶结点
    {
        for(int i = 0; i < depth; ++i)
        {
            cout << "-";
        }
        cout << m_name << endl;
    }
};

//具体的部门,人力资源部
class HRDepartment:public Company {
public:
    HRDepartment(string name):Company(name) {}
    virtual ~HRDepartment() {}
    virtual void show(int depth)
    {
        for(int i = 0; i < depth; ++i)
        {
            cout << "-";
        }
        cout << m_name << endl;
    }
};

int main(int argc, char **argv)
{
    Company *root = new ConcreteCompany("总公司");
    Company *leaf1 = new FinanceDepartment("总公司-财务部");
    Company *leaf2 = new HRDepartment("总公司-人力资源部");
    root->add(leaf1);
    root->add(leaf2);

    //分公司A
    Company *mid1 = new ConcreteCompany("分公司A");
    Company *leaf3 = new FinanceDepartment("分公司A-财务部");
    Company *leaf4 = new HRDepartment("分公司A-人力资源部");
    mid1->add(leaf3);
    mid1->add(leaf4);
    root->add(mid1);

    //分公司B
    Company *mid2 = new ConcreteCompany("分公司B");
    Company *leaf5 = new FinanceDepartment("分公司B-财务部");
    Company *leaf6 = new HRDepartment("分公司B-人力资源部");
    mid2->add(leaf5);
    mid2->add(leaf6);
    root->add(mid2);

    //显示
    root->show(0);

    delete leaf1;delete leaf2;
    delete leaf3;delete leaf4;
    delete leaf5;delete leaf6;
    delete mid1;
    delete mid2;
    delete root;
    return 0;
}
