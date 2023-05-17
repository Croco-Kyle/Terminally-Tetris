#include <iostream>
#include <vector>
#include "Board.h"

// There are 10 different squares in a line. 
// If 
// Before we add a piece we need to check if the board is valid
Board::Board(int width, int height){
    this->width = width;
    this->height = height;
    for (int i = 0; i < height; i++){
        std::vector<std::string> row(width," ");
        map.push_back(row); 
    }
    // The idea is that we will check the next line below the current piece.
    // If the next line is empty then we can move the piece down.
    // If the next line is not empty then we can't move the piece down.
    // and if the piece is already at the bottom then we can't move the piece down.
    bool Board::check_line(width, x,y){
        for (int i = 0; i < height; i++){
            int count = 0;
            for (int j = 0; j < width; j++){
                if (map[i][j] != " "){
                    count++;
                }
            }
            if (count == width){
                return i;
            }
        }
        return ;
    }
};

// Testing the board class.
int main(){
    Board board(100,200); // creates a board of size 100x200. The tetris board is
    // is usually 10 x 20 squares.
    std::cout << board.getBoard();

    return 0;
}
