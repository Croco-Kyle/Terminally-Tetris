#include <iostream>
#include <vector>


// The tetris game board represented by a vector of vectors.

struct Board{
    int mode = 0;
    int width;
    int height;

    std::vector<std::vector<std::string>> map;
    // creates the board depending on how large we want our board.
    // this allows us to fix any board errors we might encounter.
    Board(int width, int height){
        this->width = width;
        this->height = height;
        for (int i = 0; i < height){
            std::vector<std::string> row(width," ");
            map.push_back(row); 
        }
    }
    // prints the board to the console.
    void printBoard(){
        std::string board = "";
        for (int i = 0; i < height; i++){
            board += "|";
            for (int j = 0; j < width; j++){
                board += map[i][j];
            }
            board += "|\n";
        }
    std::cout << board;
    }
    // checks if the piece can be placed on the board.


};

