/*************************************************************************
	> File Name: template_method.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 11时31分27秒
 ************************************************************************/
//模板方法模式
#include<iostream>
using namespace std;

class Resume {
protected: //保护成员
    virtual void setPersonalInfo() {}
    virtual void setEducation() {}
    virtual void setWorkExp() {}
public:
    void fillResume()
    {
        setPersonalInfo();
        setEducation();
        setWorkExp();
    }
};

class ResumeA:public Resume {
protected:
    void setPersonalInfo() { cout << "A's PersonalInfo" << endl; }
    void setEducation() { cout << "A's Education" << endl; }
    void setWorkExp() { cout << "A's WorkExp" << endl; }
};

class ResumeB:public Resume {
protected:
    void setPersonalInfo() { cout << "B's PersonalInfo" << endl; }
    void setEducation() { cout << "B's Education" << endl; }
    void setWorkExp() { cout << "B's WorkExp" << endl; }
};

int main(int argc, char ** argv)
{
    Resume *r1 = new ResumeA();
    r1->fillResume();
    delete r1;
    r1 = NULL;
    Resume *r2 = new ResumeB();
    r2->fillResume();
    delete r2;
    r2 = NULL;
    return 0;
}
