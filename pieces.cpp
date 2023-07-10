#include "coords.h"
#include <vector>
#include <string>

// class representing the individual pieces in tetris.
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).

class Piece{
    int mode;       // 0 = square, 1 = line, 2 = T, 3 = LL, 4 = LR, 5 = ZL, 6 = ZR
    int row = 0;    // staring row = 0
    int col;        // starting col to be input. This will be left most corner of the piece.

    class Piece(int mode, int col){
        this->mode = mode;
        this->col = col;
        
    }



};