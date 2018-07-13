/*************************************************************************
	> File Name: memento.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 17时55分07秒
 ************************************************************************/
//备忘录模式
#include<iostream>
#include <vector>
using namespace std;

//需要保存的信息
class Memento {
public:
    int m_vitality; //生命值
    int m_attack;   //进攻值
    int m_defense;  //防守值
public:
    Memento(int vitality, int attack, int defense):
        m_vitality(vitality), m_attack(attack), m_defense(defense) {}
    Memento& operator= (const Memento &memento)
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;

        return *this;
    }
};

//游戏角色
class GameRole {
private:
    int m_vitality;
    int m_attack;
    int m_defense;
public:
    GameRole():m_vitality(100), m_attack(100), m_defense(100) {}
    Memento save() //保存进度,只与Memento对象交互,并不牵涉到Caretake
    {
        Memento memento(m_vitality, m_attack, m_defense);
        return memento;
    }

    void load(Memento memento) //载入进度,只与Memento对象交互,并不牵涉到Caretake 
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;
    }

    void show() {
        cout << "vitality:" << m_vitality << ",attack:"<< m_attack<<",defense:" << m_defense << endl;
    }

    void attack() {
        m_vitality -= 10;
        m_attack -= 10;
        m_defense -= 10;
    }
};

//保存进度库
class Caretake {
public:
    Caretake() {}
    void save(Memento memento)
    {
        m_vecMemento.push_back(memento);
    }
    Memento load(int state)
    {
        return m_vecMemento[state];
    }
private:
    vector<Memento> m_vecMemento;
};

int main(int argc, char **argv)
{
    Caretake caretake;
    GameRole role;
    role.show(); //初始值
    caretake.save(role.save()); //保存状态

    role.attack();
    role.show(); //进攻后

    role.load(caretake.load(0)); //载入状态
    role.show(); //恢复到状态0
    return 0;
}
