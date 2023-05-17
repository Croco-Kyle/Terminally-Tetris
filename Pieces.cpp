// class representing the individual board game pieces
// There are 7 different pieces in tetris. Square, Line, T, L (left and right), and Z (left and right).
struct Piece{    
    int x;
    int y;
    int width;
    int height;

    std::vector<std::vector<std::string>> map;
    // constructor for the piece class.
    Piece(int x, int y, int width, int height, std::vector<std::vector<std::string>> map){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->map = map;
    }
    // rotates the piece clockwise.
    void rotate(){
        std::vector<std::vector<std::string>> newMap;
        for (int i = 0; i < width; i++){
            std::vector<std::string> row;
            for (int j = height - 1; j >= 0; j--){
                row.push_back(map[j][i]);
            }
            newMap.push_back(row);
        }
        map = newMap;
        int temp = width;
        width = height;
        height = temp;
    } 

};