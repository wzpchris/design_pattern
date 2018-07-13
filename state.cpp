/*************************************************************************
	> File Name: state.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 20时58分01秒
 ************************************************************************/
//状态模式
#include<iostream>
using namespace std;

class War;
class State {
public:
    virtual void prophase() {}
    virtual void metaphase() {}
    virtual void anaphase() {}
    virtual void end() {}
    virtual void currentState(War *war) {}
};

//战争
class War {
private:
    State *m_state; //目前状态
    int m_days; //战争持续持续时间
public:
    War(State *state):m_state(state), m_days(0) {}
    ~War() { delete m_state; }
    int getDays() { return m_days; }
    void setDays(int days) { m_days = days; }
    void setState(State *state) {
        delete m_state;
        m_state = state;
    }
    void getState() 
    {
        m_state->currentState(this);
    }
};

//战争结束
class EndState:public State {
public:
    void End(War *war) //结束阶段的具体行为
    {
        cout << "战争结束" << endl;
    }
    void currentState(War *war) { End(war); }
};

//后期
class AnaphaseState:public State {
public:
    void anaphase(War *war) //后期的具体行为
    {
        if(war->getDays() < 30) {
            cout << "第" << war->getDays() << "天:战争后期,双方拼死一博" << endl;
        }else {
            war->setState(new EndState());
            war->getState();
        }
    }

    void currentState(War *war) {
        anaphase(war);
    }
};

//中期
class MetaphaseState:public State {
public:
    void metaphase(War *war){
        if(war->getDays() < 20)
        {
            cout << "第" <<war->getDays()<<"天:战争中期,进入相持阶段,双方各有损耗" << endl;
        }else {
            war->setState(new AnaphaseState());
            war->getState();
        }
    }

    void currentState(War *war)
    {
        metaphase(war);
    }
};

//前期
class ProphaseState:public State {
public:
    void prophase(War *war)
    {
        if(war->getDays() < 10)
        {
            cout << "第"<<war->getDays() <<"天:战争初期,双方你来我往,互相试探对方" << endl;
        }else {
            war->setState(new MetaphaseState());
            war->getState();
        }
    }

    void currentState(War *war)
    {
        prophase(war);
    }
};


int main(int argc, char **argv)
{
    War *war = new War(new ProphaseState());
    for(int i = 1; i < 40; i += 5)
    {
        war->setDays(i);
        war->getState();
    }

    delete war;
    return 0;
}
