#include <vector>
#include <string>

// class representing the coords of game pieces.
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).
struct Coords{    
    int w[2];
    int x[2];
    int y[2];
    int z[2];

    // constructor for the piece class.
    Coords(int w[2], int x[2], int y[2], int z[2]){
        this->w[0] = w[0];
        this->w[1] = w[1];
        this->x[0] = x[0];
        this->x[1] = x[1];
        this->y[0] = y[0];
        this->y[1] = y[1];
        this->z[0] = z[0];
        this->z[1] = z[1];
    }
    
};