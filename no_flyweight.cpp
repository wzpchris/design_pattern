/*************************************************************************
	> File Name: no_flyweight.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 15时43分06秒
 ************************************************************************/
//非共享模式实现简单棋盘,这种方式占用的内存消耗大
#include<iostream>
#include <vector>
using namespace std;

enum PieceColor { BLACK, WHITE };

//棋子位置
struct PiecePos
{
    int x;
    int y;
    PiecePos(int a, int b):x(a),y(b) {}
};

//棋子定义
class Piece {
protected:
    PieceColor m_color; //颜色
    PiecePos m_pos; //位置
public:
    Piece(PieceColor color, PiecePos pos):m_color(color),m_pos(pos) {}
    ~Piece() {}
    virtual void draw() {}
};

class BlackPiece:public Piece {
public:
    BlackPiece(PieceColor color, PiecePos pos):Piece(color, pos) {}
    ~BlackPiece() {}
    void draw() { cout << "绘制一颗黑棋" << endl;}
};

class WhitePiece:public Piece {
public:
    WhitePiece(PieceColor color, PiecePos pos):Piece(color, pos) {}
    ~WhitePiece() {}
    void draw() {
        cout << "绘制一颗白棋" << endl;
    }
};

//棋盘
class PieceBoard {
private:
    vector<Piece*> m_vecPiece; //已有的棋子
    string m_blackName; //黑方名称
    string m_whiteName; //白方名称
public:
    PieceBoard(string black, string white):m_blackName(black), m_whiteName(white) {}
    ~PieceBoard() { clear(); }
    void setPiece(PieceColor color, PiecePos pos) //一步棋,在棋盘上放一颗棋子
    {
        Piece *piece = NULL;
        if(color == BLACK){
            piece = new BlackPiece(color, pos); //获得一颗黑棋
            cout << m_blackName << "在位置(" << pos.x << "," << pos.y << ")";
            piece->draw(); //绘制
        }else {
            piece = new WhitePiece(color, pos);
            cout << m_whiteName << "在位置(" << pos.x << "," << pos.y << ")";
            piece->draw();
        }
        m_vecPiece.push_back(piece); //加入容器中
    }

    void clear() { //释放内存
        int size = m_vecPiece.size();
        for(int i = 0; i < size; ++i)
        {
            delete m_vecPiece[i]; 
        }
    }
};

int main(int argc, char** argv)
{
    PieceBoard pb("A", "B");
    pb.setPiece(BLACK, PiecePos(4,4));
    pb.setPiece(WHITE, PiecePos(4,16));
    pb.setPiece(BLACK, PiecePos(16,4));
    pb.setPiece(WHITE, PiecePos(16,16));
    return 0;
}
