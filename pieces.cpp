#include <vector>
#include <string>

// class representing the individual board game pieces
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).
struct Piece{    
    int w[2];
    int x[2];
    int y[2];
    int z[2];

    // constructor for the piece class.
    Piece(int w[2], int x[2], int y[2], int z[2]){
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
};