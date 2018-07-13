/*************************************************************************
	> File Name: virtual_proxy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 14时44分04秒
 ***********************************************************************/
//代理模式:1.远程代理 2.虚代理 3.保护代理 4.智能引用
//这里只是虚代理
#include<iostream>
using namespace std;

class Image {
public:
    Image(string name):m_imageName(name) {}
    virtual ~Image() {}
    virtual void show() {}
protected:
    string m_imageName;
};

class BigImage:public Image {
public:
    BigImage(string name):Image(name) {}
    ~BigImage() {}
    void show() { cout << "Show big image :" << m_imageName << endl; }
};

class BigImageProxy:public Image {
private:
    BigImage *m_bigImage;
public:
    BigImageProxy(string name):Image(name), m_bigImage(0) {}
    ~BigImageProxy() { delete m_bigImage; }
    void show()
    {
        if(m_bigImage == NULL)
        {
            m_bigImage = new BigImage(m_imageName);
        }
        m_bigImage->show();
    }
};

//智能引用
template<class T>
class auto_ptr {
public:
    explicit auto_ptr(T *p = 0):pointee(p) {}
    auto_ptr(auto_ptr<T> &rhs):pointee(rhs.release()) {}
    ~auto_ptr() { delete pointee; }
    auto_ptr<T>& operator=(auto_ptr<T>& rhs)
    {
        if(this != &rhs) reset(rhs.release());
        return *this;
    }

    T& operator*() const { return *pointee; }
    T* operator->() const { return pointee; }
    T* get() const { return pointee; }
    T* release() {
        T* oldPointee = pointee;
        pointee = 0;
        return oldPointee;
    }
    
    void reset(T* p = 0)
    {
        if(pointee != p)
        {
            delete pointee;
            pointee = p;
        }
    }
private:
    T *pointee;
};


template<typename T>
class smart_ptr{
public:
    smart_ptr(T *p = 0):pointee(p), count(new size_t(1)) {} //初始的计数值为1
    smart_ptr(const smart_ptr &rhs):pointee(rhs.pointee),count(rhs.count)
    {
        ++*count;
    }
    ~smart_ptr() { decr_count(); } //析构,计数减1,减到0时进行垃圾回收,即释放空间
    smart_ptr& operator=(const smart_ptr &rhs) //重载赋值操作符
    {
        //给自身赋值也对,因为如果自身赋值,计数器先减1,再加1,并未发生改变
        ++*(rhs.count);
        decr_count();
        pointee = rhs.pointee;
        count = rhs.count;
        return *this;
    }

    //重载箭头操作符和解引用操作符,未提供指针的检查
    T* operator->() { return pointee; }
    const T* operator->() const { return pointee; }
    T& operator* () { return *pointee; }
    const T& operator* () const { return *pointee; }
    size_t get_refcount() { return *count; } //获得引用计数器值
private:
    T *pointee; //实际指针,被代理
    size_t *count; //引用计数器
    void decr_count() { //计数器减1
        if(--*count == 0)
        {
            delete pointee;
            delete count;
        }
    }
};

int main(int argc, char **argv)
{
    Image *image = new BigImageProxy("proxy.jpg");
    image->show(); //需要时由代理负责打开
    delete image;
    return 0;
}
