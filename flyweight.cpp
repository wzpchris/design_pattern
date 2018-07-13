/*************************************************************************
	> File Name: flyweight.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 15时59分46秒
 ************************************************************************/
//共享模式
//分离出外部状态:位置,只保留内部状态
#include<iostream>
#include <vector>
using namespace std;

//棋子颜色
enum PieceColor {BLACK, WHITE};

//棋子位置
struct PiecePos {
    int x;
    int y;
    PiecePos(int a, int b):x(a),y(b) {}
};

//棋子定义
class Piece {
protected:
    PieceColor m_color; //颜色
public:
    Piece(PieceColor color):m_color(color) {}
    ~Piece() {}
    virtual void draw() {}
};

class BlackPiece:public Piece {
public:
    BlackPiece(PieceColor color):Piece(color) {}
    ~BlackPiece() {}
    void draw() {
        cout << "绘制一颗黑棋" << endl;
    }
};

class WhitePiece:public Piece {
public:
    WhitePiece(PieceColor color):Piece(color) {}
    ~WhitePiece() {}
    void draw() {
        cout << "绘制一颗白棋" << endl;
    }
};

//棋盘
class PieceBoard {
private:
    vector<PiecePos> m_vecPos; //存放棋子的位置
    Piece *m_blackPiece; //黑棋棋子
    Piece *m_whitePiece; //白棋棋子
    string m_blackName; 
    string m_whiteName;
public:
    PieceBoard(string black, string white):m_blackName(black),m_whiteName(white) {
        m_blackPiece = NULL;
        m_whitePiece = NULL;
    }
    
    ~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }
    void setPiece(PieceColor color, PiecePos pos)
    {
        if(color == BLACK)
        {
            if(m_blackPiece == NULL) //只有一颗黑棋
            {
                m_blackPiece = new BlackPiece(color);
            }
            cout << m_blackName << "在位置(" << pos.x << "," << pos.y << ")";
            m_blackPiece->draw();
        }else 
        {
            if(m_whitePiece == NULL)
            {
                m_whitePiece = new WhitePiece(color);
            }
            cout << m_whiteName << "在位置(" << pos.x << "," << pos.y << ")";
            m_whitePiece->draw();
        }

        m_vecPos.push_back(pos);
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
