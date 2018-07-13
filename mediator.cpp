/*************************************************************************
	> File Name: mediator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 18时27分58秒
 ************************************************************************/
//中介者模式:
#include<iostream>
using namespace std;

class Mediator;

//抽象人
class Person {
protected:
    Mediator *m_mediator; //中介
public:
    virtual void setMediator(Mediator *mediator){}
    virtual void sendMessage(string msg) {}
    virtual void getMessage(string msg) {}
};

//抽象中介结构
class Mediator {
public:
    virtual void send(string msg, Person *person) {}
    virtual void setA(Person *A) {} //设置其中一方
    virtual void setB(Person *B) {}
};

//租房者
class Renter:public Person {
public:
    void setMediator(Mediator *mediator) {
        m_mediator = mediator;
    }
    void sendMessage(string msg) {
        m_mediator->send(msg, this);
    }
    void getMessage(string msg)
    {
        cout << "租房者收到信息:" << msg; 
    }
};

//房东
class Landlord:public Person {
public:
    void setMediator(Mediator *mediator) 
    {
        m_mediator = mediator;
    }

    void sendMessage(string msg)
    {
        m_mediator->send(msg, this);
    }

    void getMessage(string msg)
    {
        cout << "房东收到信息:" << msg; 
    }
};

//房屋中介
class HouseMediator:public Mediator {
private:
    Person *m_a; //租房者
    Person *m_b; //房东
public:
    HouseMediator():m_a(0),m_b(0) {}
    void setA(Person *A) { m_a = A; }
    void setB(Person *B) { m_b = B; }
    void send(string msg, Person *person)
    {
        if(person == m_a)
        {
            m_b->getMessage(msg);
        }else 
        {
            m_a->getMessage(msg);
        }
    }
};

int main(int argc, char** argv)
{
    Mediator *mediator = new HouseMediator();
    Person *person1 = new Renter(); //租房者
    Person *person2 = new Landlord(); //房东
    mediator->setA(person1);
    mediator->setB(person2);
    person1->setMediator(mediator);
    person2->setMediator(mediator);

    person1->sendMessage("我想在南京路附近租套房子,价格800元一个月\n");
    person2->sendMessage("出租房子:南京路100号,70平米,1000元一个月\n");
    delete person1;
    delete person2;
    delete mediator;
    return 0;
}
