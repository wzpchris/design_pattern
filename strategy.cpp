/*************************************************************************
	> File Name: strategy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月12日 星期四 18时09分29秒
 ************************************************************************/
/**
 *策略模式
 */

#include<iostream>
using namespace std;

//抽象接口
class ReplaceAlgorithm {
public:
    virtual void replace() = 0;
};

//三种具体的替换算法
class LRU_ReplaceAlgorithm:public ReplaceAlgorithm {
public:
    void replace() {
        cout << "Least Recently Used replace algorithm" << endl;
    }
};

class FIFO_ReplaceAlgorithm:public ReplaceAlgorithm {
public:
    void replace() {
        cout << "First in First out replace algorithm" << endl;
    }
};

class Random_ReplaceAlgorithm:public ReplaceAlgorithm {
public:
    void replace() {
        cout << "Random replace algorithm" << endl;
    }
};

//方式一:直接通过参数指定,传入一个特定算法的指针
//Cache需要用到替换算法
class Cache {
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(ReplaceAlgorithm *ra):m_ra(ra) {}
    ~Cache() { delete m_ra; }
    void replace() {
        m_ra->replace();
    }
};

//方式二:直接通过参数指定,传入标签
enum RA {
    LRU,
    FIFO,
    RANDOM
};

class Cache1 {
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache1(enum RA ra)
    {
        if(ra == LRU) {
            m_ra = new LRU_ReplaceAlgorithm();
        }else if(ra == FIFO) {
            m_ra = new FIFO_ReplaceAlgorithm();
        }else if(ra == RANDOM) {
            m_ra = new Random_ReplaceAlgorithm();
        }else {
            m_ra = NULL;
        }
    }

    ~Cache1() { delete m_ra; }
    void replace() {
        if(m_ra)
        {
            m_ra->replace();
        }
    }
};

//方式三:模板形式
//必须在编译时选择对应的Strategy和运行时不能改变
template <class RA>
class Cache2 {
private:
    RA m_ra;
public:
    Cache2() {}
    ~Cache2() {}
    void replace() {
        m_ra.replace();
    }
};


int main(int argc, char **argv)
{
    cout << "传指针形式" << endl;
    Cache cache(new LRU_ReplaceAlgorithm()); //暴露了算法的定义
    cache.replace();

    cout << "传标签形式" << endl;
    Cache1 cache1(FIFO);
    cache1.replace();

    cout << "模板形式" << endl;
    Cache2<Random_ReplaceAlgorithm> cache2;
    cache2.replace();

    return 0;
}
