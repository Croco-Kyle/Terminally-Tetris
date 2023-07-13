#include "coords.h"
#include <vector>
#include <string>
#include <cstdlib>

// class representing the individual pieces in tetris.
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).

class Piece{
    public:
    int row = 0;    // starting row = 0
    int col = 0;        // starting col to be input. This will be left most corner of the piece.
    Coords* coord;   // coordinates of the piece.
    Piece(){
        this->col = 5;
    }
    Piece(int col){
        this->col = col;    
    }
    // function to update the coordinates of the piece after it has been moved.
    void updateCoords(Coords* newCoords){
        coord = newCoords;
    }

    Coords* rotate(){
        // function to be overridden by each piece.
        return coord;
    }
};

// class representing the square piece.
struct Square: public Piece{

    Square(int col){
        this->col = col;
        this->coord = getSquare(col);
    }
    // function to create square piece.
    Coords* getSquare(int col){
        int w[2] = {col,0};
        int x[2] = {col,1};
        int y[2] = {col+1,0};
        int z[2] = {col+1,1};

        // creating the square piece.
        Coords* coord = new Coords(w,x,y,z);
        return coord;
    }
    // Square piece does not rotate.

};

// // class representing the line piece.
// struct Line: public Piece{
//     Line(int col){
//         this->col = col;
//         this->coord = *getLine(row, col);
//     }

//     // function to create line piece.
//     Coords* getLine(int x, int y){
//         int w[2] = {x,y};
//         int x[2] = {x,y+1};
//         int y[2] = {x,y+2};
//         int z[2] = {x,y+3};

//         // creating the line piece.
//         Coords* coord = new Coords(w,x,y,z);
//         return coord;
//     }

//     Coords rotate(){

//         // line piece rotates.
//         Coords nCoords();

//     }
// };

// // class representing the T piece.
// struct T: public Piece{
//     T(int col){
//         this->col = col;
//         this->coord = *getT(row, col);
//     }
//     // function to create T piece.
//     Coords* getT(int x, int y){
//         // creating the T piece.
//         Coords* coord = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y+1});
//         return coord;
//     }

//     void rotate(){
//         // T piece rotates.
//     }
// };

// // class representing the Ll piece.
// struct Ll: public Piece{
//     Ll(int col){
//         this->col = col;
//         this->coord = *getLl(row, col);
//     }
//     // function to create L piece.
//     Coords* getLl(int x, int y){
//         // creating the Ll piece.
//         Coords* coord = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y});
//         return coord;
//     }

//     void rotate(){
//         // Ll piece rotates.
//     }
// };

// // class representing the Lr piece.
// struct Lr: public Piece{
//     Lr(int col){
//         this->col = col;
//         this->coord = *getLr(row, col);
//     }
    
//     // function to create Lr piece.
//     Coords* getLr(int x, int y){
//         // creating the Lr piece.
//         Coords* coord = new Coords({x, y}, {x, y+1}, {x, y+2}, {x+1, y+2});
//         return coords;
//     }

//     void rotate(){
//         // Lr piece rotates.
//     }
// };

// // class representing the Zl piece.
// struct Zl: public Piece{
//     Zl(int col){
//         this->col = col;
//         this->coord = getZl(row, col);
//     }
//     // function to create Zl piece.
//     Coords* getZl(int x, int y){
//         // creating the Zl piece.
//         Coords* coords = new Coords({x, y}, {x, y+1}, {x+1, y+1}, {x+1, y+2});
//         return coords;
//     }

//     void rotate(){
//         // Zl piece rotates.
//     }
// };

// // class representing the Zr piece.
// struct Zr: public Piece{
//     Zr(int col){
//         this->col = col;
//         this->coord = getZr(row, col);
//     }
//     // function to create Zr piece.
//     Coords* getZr(int x, int y){
//         // creating the Zr piece.
//         Coords* coords = new Coords({x, y+1}, {x, y+2}, {x+1, y}, {x+1, y+1});
//         return coords;
//     }

//     void rotate(){
//         // Zr piece rotates.
//     }
//};
