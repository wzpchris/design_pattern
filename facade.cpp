/*************************************************************************
	> File Name: facade.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 13时46分11秒
 ************************************************************************/
//外观模式
#include<iostream>
using namespace std;

class Scanner {
public:
    void scan() { cout << "词法分析" << endl; }
};

class Parser {
public:
    void parse() { cout << "语法分析" << endl; }
};

class GenMidCode {
public:
    void genCode() { cout << "产生中间代码" << endl; }
};

class GenMachineCode {
public:
    void genCode() { cout << "产生机器码" << endl; }
};

//高层接口
class Compiler {
public:
    void run() {
        Scanner scanner;
        Parser parser;
        GenMidCode genMideCode;
        GenMachineCode genMacCode;
        scanner.scan();
        parser.parse();
        genMideCode.genCode();
        genMacCode.genCode();
    }
};

int main(int argc, char** argv)
{
    Compiler compiler;
    compiler.run();
    return 0;
}
