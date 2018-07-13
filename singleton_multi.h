/*************************************************************************
	> File Name: singleton_multi.h
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 10时44分23秒
 ************************************************************************/

#ifndef _SINGLETON_MULTI_H
#define _SINGLETON_MULTI_H
template<typename T>
class Singleton {
public:
    static T& instance() {
        if(m_pInstance == NULL)
        {
            Lock lock;
            if(m_pInstance == NULL)
            {
                m_pInstance = new T();
                atexit(destroy);
            }
            return *m_pInstance;
        }
        return *m_pInstance;
    }
protected:
    Singleton(void) {}
    ~Singleton(void) {}
private:
    Singleton(const Singleton &rhs);
    Singleton &operator(const Singleton &rhs);

    static void destroy()
    {
        if(m_pInstance != NULL)
        {
            delete m_pInstance;
        }
        m_pInstance = NULL;
    }

    static T* volatile m_pInstance;
};
 
template<typename T> T* Singleton<T>::m_pInstance = NULL;
#endif
