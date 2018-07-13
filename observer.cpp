/*************************************************************************
	> File Name: observer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 20时24分56秒
 ************************************************************************/
//观察者模式
#include<iostream>
#include <list>
using namespace std;

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void update() {}
};

//博客
class Blog {
public:
    Blog() {}
    virtual ~Blog() {}
    void attach(Observer *observer) {
        m_observers.push_back(observer); //添加观察者
    }
    void remove(Observer *observer)
    {
        m_observers.remove(observer); //移除观察者
    }

    void notify() //通知观察者
    {
        list<Observer*>::iterator iter = m_observers.begin();
        for(; iter != m_observers.end(); ++iter)
        {
            (*iter)->update();
        }
    }

    virtual void setStatus(string s) { m_status = s; } //设置状态
    virtual string getStatus() { return m_status; } //获得状态
private:
    list<Observer*> m_observers;
protected:
    string m_status; //状态
};

//具体博客类
class BlogCSDN:public Blog {
private:
    string m_name; //博主名称
public:
    BlogCSDN(string name):m_name(name) {}
    ~BlogCSDN() {}
    void setStatus(string s) { 
        m_status = "CSDN通知:" + m_name + s; 
    } 
    string getStatus() {
        return m_status;
    }
};

//具体观察者
class ObserverBlog:public Observer {
private:
    string m_name; //观察者名称
    Blog *m_blog; //观察的博客，可以以链表形式更好,就可以观察多个博客
public:
    ObserverBlog(string name, Blog *blog):m_name(name), m_blog(blog) {}
    ~ObserverBlog(){}
    void update() //获得更新状态
    {
        string status = m_blog->getStatus();
        cout << m_name << "------" << status << endl;
    }
};

int main(int argc, char **argv)
{
    Blog *blog = new BlogCSDN("wuzhekai1985");
    Observer *observer1 = new ObserverBlog("tutuping", blog);
    blog->attach(observer1);
    blog->setStatus("发表设计模式--观察者模式");
    blog->notify();

    delete blog;
    delete observer1;

    return 0;
}

