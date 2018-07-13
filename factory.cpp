/*************************************************************************
	> File Name: factory.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月12日 星期四 17时21分50秒
 ************************************************************************/
/*工厂模式:
 *简单工厂模式
 *工厂方法模式
 *抽象工厂模式
 */

#include<iostream>
using namespace std;

enum CTYPE {
    COREA,
    COREB
};

class SingleCore {
public:
    virtual void show() = 0;
};

//单核A
class SingleCoreA:public SingleCore {
public:
    void show() { cout << "SingleCore A" << endl; }
};

//单核B
class SingleCoreB:public SingleCore {
public:
    void show() { cout << "SingleCore B" << endl; }
};

//简单工厂模式
//唯一的工厂，可以生产两种型号的处理器核,需要在内部判断
class Factory {
public:
   static SingleCore *createSingleCore(enum CTYPE ctype)
    {
        if(ctype == COREA) //工厂内部去判断
        {
            return new SingleCoreA(); //生产核A
        }else if(ctype == COREB)
        {
            return new SingleCoreB(); //生产核B
        }else 
            return NULL;
    }
};

//简单工厂模式的缺点就是当要增加新的核类型时，需要修改工厂类，违反了设计模式中的开闭原则
//工厂方法模式
class FactoryMethod {
public:
    virtual SingleCore *createSingleCore() = 0;
};

//生产A核的工厂
class FactoryA:public FactoryMethod {
public:
    SingleCore *createSingleCore() {
        return new SingleCoreA();
    }
};

//生产B核的工厂
class FactoryB:public FactoryMethod {
public:
    SingleCore *createSingleCore(){
        return new SingleCoreB();
    }
};

//工厂方法模式的缺点就是没当增加一个新的产品类型，就需要增加一个对应的生产工厂类,这导致实际生产中需要更多的类定义
//工厂方法模式中每个具体工厂类中只有一个接口
//抽象工厂模式
class MultiCore {
public:
    virtual void show() = 0;
};

class MultiCoreA:public MultiCore {
public:
    void show() { cout << "Multi Core A" << endl; }
};

class MultiCoreB:public MultiCore {
public:
    void show() { cout << "Multi Core B" << endl; }
};

//工厂
class CoreFactory {
public:
    virtual SingleCore *createSingleCore() = 0;
    virtual MultiCore *createMultiCore() = 0;
};

//工厂A,专门用来生产A型号的处理器(单核和多核)
class CoreFactoryA:public CoreFactory {
public:
    SingleCore *createSingleCore() {
        return new SingleCoreA();
    }

    MultiCore *createMultiCore() {
        return new MultiCoreA();
    }
};


//工厂B,专门用来生产B型号的处理器(单核和多核)
class CoreFactoryB:public CoreFactory {
public:
    SingleCore *createSingleCore() {
        return new SingleCoreB();
    }

    MultiCore *createMultiCore() {
        return new MultiCoreB();
    }
};



int main(int argc, char **argv)
{
    cout << "简单工厂模式" << endl;
    SingleCore *pBase = Factory::createSingleCore(COREA);
    pBase->show();

    pBase = Factory::createSingleCore(COREB);
    pBase->show();

    cout << "工厂方法模式" << endl;
    FactoryA fa;
    pBase = fa.createSingleCore();
    pBase->show();

    FactoryB fb;
    pBase = fb.createSingleCore();
    pBase->show();

    cout << "抽象工程模式" << endl;
    CoreFactoryA cfa;
    pBase = cfa.createSingleCore();
    MultiCore *pMultiBase = cfa.createMultiCore();
    pBase->show();
    pMultiBase->show();

    CoreFactoryB cfb;
    pBase = cfb.createSingleCore();
    pMultiBase = cfb.createMultiCore();
    pBase->show();
    pMultiBase->show();

    delete pBase;
    delete pMultiBase;
    return 0;
}
