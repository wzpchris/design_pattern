/*************************************************************************
	> File Name: singleton_template.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 10时12分16秒
 ************************************************************************/

#ifndef _SINGLETON_TEMPLATE_H
#define _SINGLETON_TEMPLATE_H
template<typename T>
class Singleton {
public:
    static T& instance()
    {
        static T s_instance;
        return s_instance;
    }
protected:
    Singleton(void) {}
    ~Singleton(void) {}
private:
    Singleton(const Singleton &rhs);
    Singleton &operator=(const Singleton &rhs);
};
#endif
