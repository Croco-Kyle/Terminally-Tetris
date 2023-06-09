#include <vector>
#include <string>


class Board{
    int mode = 0;
    int width;
    int height;
    std::vector<std::vector<std::string>> map = {};
    // creates the board depending on how large we want our board.
    // this allows us to fix any board errors we might encounter.
    public:
    Board():Board(10,20){}   // default board size is 100x200

    Board(int width, int height){   // user defined board size.
        this->width = width;
        this->height = height;
        for (int i = 0; i < height; i++){
            std::vector<std::string> row(width," ");
            map.push_back(row); 
        }
    }
    // This function checks if a line is complete and then deletes it and updates the score/level.
    // void check_line(){
    //     for (int i = 0; i < height; i++){
    //         int count = 0;
    //         for (int j = 0; j < width; j++){
    //             if (map[i][j] != " "){
    //                 count++;
    //             }
    //         }
    //         if (count == width){
    //             map.erase(map.begin()+i);
    //             std::vector<std::string> row(width," ");
    //             map.insert(map.begin(),row);
    //         }
    //     }
    // }
    // Gets the board string.
    std::string getBoard(){
        std::string board ="";
        for (int i = 0; i < height; i++){ // traversing rows
            for (int j = 0; j < width; j++){
                board += map[i][j];
            }
        }
            return board;
    }

    // std::string getRow(int row){
    //     std::string board ="";
    //     board += "|";
    //     for (int j = 0; j < width; j++){
    //         board += map[row][j];
    //     }
    //     board += "|\n";
    //     return board;
    // }
    
    // The idea is that we will check the next line below the current piece.
    // If the next line is empty then we can move the piece down.
    // If the next line is not empty then we can't move the piece down.
    // and if the piece is already at the bottom then we can't move the piece down.
    bool check_map(int wide, int x,int y){
        for (int i = 0; i < height; i++){
            int count = 0;
            for (int j = 0; j < wide; j++){
                if (map[i][j] != " "){
                    count++;
                }
            }
            // troubleshoot this later...
            if (count == wide){
                return true;
            }
        }
        return false;
    }

};


// Testing the board class.
// int main(){
//     Board board(100,200); // creates a board of size 100x200. The tetris board is
//     // is usually 10 x 20 squares.
//     std::cout << board.getBoard();

//     return 0;
//}
