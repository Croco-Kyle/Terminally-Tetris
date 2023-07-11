// handles the inputs, outputs, and displays the board
#include <iostream>
#include "board.cpp"   
#include "pieces.cpp"
#include <ncurses.h>

using namespace std;

/*
The gameplay loop is as follows:
1. The game starts with a random piece.
2. The player can move the piece left, right, or down.
3. The player can rotate the piece clockwise.
4. The player can drop the piece.
5. If the piece is dropped, the player gets a new piece.
6. If the piece is dropped, and the piece is at the top of the board, the game ends.
7. If the piece is dropped, and the piece is on top of another piece, the game continues.
8. If a line is complete, the line is deleted and the score is updated.
9. If the score is updated, the level is updated.
10. If the level is updated, the speed is updated.
11. If the speed is updated, the game continues.
12. If the game continues, the player gets a new piece.
*/ 
void gameLoop(){

}

int main(){
    
    initscr();              // initializes the screen, and sets up memory and clears the screen
    raw();                  // disables line buffering
    keypad(stdscr, TRUE);   // enables the keypad
    noecho();               // disables echo

    // print the board to the virtual screen
    printw(board.getBoard().c_str()); // prints the board to the virtual screen.
    refresh();              // prints it to the real screen
    // Do keypad(stdscr, TRUE); to enable the keypad.
    getch();                // wait for user input
    endwin();               // restore the original terminal

    return 0;
}

