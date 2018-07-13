/*************************************************************************
	> File Name: builder.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 11时48分25秒
 ************************************************************************/
//建造者模式
#include<iostream>
using namespace std;

class Builder {
public:
    virtual void buildHead() {}
    virtual void buildBody() {}
    virtual void buildLeftArm() {}
    virtual void buildRightArm() {}
    virtual void buildLeftLeg() {}
    virtual void buildRightLeg() {}
};

//构造瘦人
class ThinBuilder:public Builder {
public:
    void buildHead() { cout << "build thin head" << endl; }
    void buildBody() { cout << "build thin body" << endl; }
    void buildLeftArm() { cout << "build thin leftarm" << endl; }
    void buildRightArm() { cout << "build thin rightarm" << endl; }
    void buildLeftLeg() { cout << "build thin leftleg" << endl; }
    void buildRightLeg() { cout << "build thin rightleg" << endl; }
};


//构造胖人
class FatBuilder:public Builder {
public:
    void buildHead() { cout << "build fat head" << endl; }
    void buildBody() { cout << "build fat body" << endl; }
    void buildLeftArm() { cout << "build fat leftarm" << endl; }
    void buildRightArm() { cout << "build fat rightarm" << endl; }
    void buildLeftLeg() { cout << "build fat leftleg" << endl; }
    void buildRightLeg() { cout << "build fat rightleg" << endl; }
};

//构造的指挥官
class Director {
private:
    Builder *m_pBuilder;
public:
    Director(Builder *builder):m_pBuilder(builder) {}
    void create(){
        m_pBuilder->buildHead();
        m_pBuilder->buildBody();
        m_pBuilder->buildLeftArm();
        m_pBuilder->buildRightArm();
        m_pBuilder->buildLeftLeg();
        m_pBuilder->buildRightLeg();
    }
};

int main(int argc, char**argv)
{
    FatBuilder fat;
    Director d(&fat);
    d.create();
    return 0;
}

