#include "coords.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <board.cpp>

// class representing the individual pieces in tetris.
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).

struct Piece{
    int row = 0;    // starting row = 0
    int col;        // starting col to be input. This will be left most corner of the piece.
    Coords coord;   // coordinates of the piece.
    
    Piece(){
        mode = 0;
        col = 0;
    }
    Piece(int col){
        this->col = col;    
    }

    void rotate(){
        // function to be overridden by each piece.
    }
};

// class representing the square piece.
struct Square: public Piece{
    Square(int col){
        this->col = col;
        this->coord = getSquare(row, col);
    }
    // function to create square piece.
    Coords* getSquare(int x, int y){
        // creating the square piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x+1, y}, {x+1, y+1});
        return coords;
    }
    void rotate(){
        // square piece does not rotate.
    }

};

// class representing the line piece.
struct Line: public Piece{
    Line(int col){
        this->col = col;
        this->coord = getLine(row, col);
    }

    // function to create line piece.
    Coords* getLine(int x, int y){
        // creating the line piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x, y+2}, {x, y+3});
        return coords;
    }

    void rotate(){
        // line piece rotates.

    }
};

// class representing the T piece.
struct T: public Piece{
    T(int col){
        this->col = col;
        this->coord = getT(row, col);
    }
    // function to create T piece.
    Coords* getT(int x, int y){
        // creating the T piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y+1});
        return coords;
    }

    void rotate(){
        // T piece rotates.
    }
};

// class representing the Ll piece.
struct Ll: public Piece{
    Ll(int col){
        this->col = col;
        this->coord = getLl(row, col);
    }
    // function to create L piece.
    Coords* getLl(int x, int y){
        // creating the Ll piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y});
        return coords;
    }

    void rotate(){
        // Ll piece rotates.
    }
};

// class representing the Lr piece.
struct Lr: public Piece{
    Lr(int col){
        this->col = col;
        this->coord = getLr(row, col);
    }
    
    // function to create Lr piece.
    Coords* getLr(int x, int y){
        // creating the Lr piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y+2});
        return coords;
    }

    void rotate(){
        // Lr piece rotates.
    }
};

// class representing the Zl piece.
struct Zl: public Piece{
    Zl(int col){
        this->col = col;
        this->coord = getZl(row, col);
    }
    // function to create Zl piece.
    Coords* getZl(int x, int y){
        // creating the Zl piece.
        Coords* coords = new Coords({x, y}, {x, y+1}, {x+1, y+1}, {x+1, y+2});
        return coords;
    }

    void rotate(){
        // Zl piece rotates.
    }
};

// class representing the Zr piece.
struct Zr: public Piece{
    Zr(int col){
        this->col = col;
        this->coord = getZr(row, col);
    }
    // function to create Zr piece.
    Coords* getZr(int x, int y){
        // creating the Zr piece.
        Coords* coords = new Coords({x, y+1}, {x, y+2}, {x+1, y}, {x+1, y+1});
        return coords;
    }

    void rotate(){
        // Zr piece rotates.
    }
};
