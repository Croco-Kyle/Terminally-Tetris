#include <iostream>
#include <vector>


// structure representing the coords of game pieces.
struct Coords{    
    int w[2] = {0,0};
    int x[2] = {0,0};
    int y[2] = {0,0};
    int z[2] = {0,0};   

    // constructor for the piece class.
    Coords(int w[2], int x[2], int y[2], int z[2]){
        this->w[2] = w[2];
        this->x[2] = x[2];
        this->y[2] = y[2];
        this->z[2] = z[2];
    } 
};