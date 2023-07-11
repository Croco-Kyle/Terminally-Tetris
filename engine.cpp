#include <chrono>
#include "board.cpp"
#include "pieces.cpp"
// Macro definitions for the board size.
#define ROW 100
#define COL 200


class Engine{
    
    int score = 0;
    int level = 1;
    int speed = 1;
    int row = ROW;
    int col = COL;
    int delay;

    // objects for the game.
    Board board;
    Piece piece;

    Engine(){
        delay = 1000;
        board = Board(row,col);
    }

    int getDelay(){
        return delay;
    }
    void setDelay(int delay){
        this->delay = delay;
    }
    void setSpeed(int speed){
        this->speed = speed;
    }

    void setLevel(int level){
        this->level = level;
    }

    void getPiece(){
        // 0 = square, 1 = line, 2 = T, 3 = LL, 4 = LR, 5 = ZL, 6 = ZR
        int temp = rand() % 7;
        if (temp == 0){
            piece = Square(col / 2);
        }
        else if (temp == 1){
            piece = Line(col / 2);
        }
        else if (temp == 2){
            piece = T(col / 2);
        }
        else if (temp == 3){
            piece = Ll(col / 2);
        }
        else if (temp == 4){
            piece = Lr(col / 2);
        }
        else if (temp == 5){
            piece = Zl(col / 2);
        }
        else{
            piece = Zr(col / 2);
        }

    }



}