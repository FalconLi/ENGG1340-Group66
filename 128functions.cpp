#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;
string status;

//This is the welcome function to start the game 128
void Welcome() {

    // to change color of text
    cout << "\033[5;36m**************************************************" << endl;
    cout << "  __        __   _                          " << endl;
    cout << "  \\ \\      / /__| | ___ ___  _ __ ___   ___ " << endl;
    cout << "   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
    cout << "    \\ V  V /  __/ | (_| (_) | | | | | |  __/" << endl;
    cout << "     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl;
    cout << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << "\033[0m";
   

    cout << "*****************************************************************" << endl;
    cout << "***************     Welcome to the 128-Game      ****************" << endl;
    cout << "**                                                             **" << endl;
    cout << "** 1. Similar to 2048, the aim of the game is to slide cells   **" << endl;
    cout << "**    containing numbers on a 4*4 board to combine them to     **" << endl;
    cout << "**    create the number 128                                    **" << endl;
    cout << "** 2. Once you create the number 128, you will win             **" << endl;
    cout << "** 3. If you fail to create 128 with all cells occupied and no **" << endl;
    cout << "**    chance of combining cells, you will fail                 **" << endl;
    cout << "**                                                             **" << endl;
    cout << "***************           GOOD LUCK!!!           ****************" << endl;
    cout << "*****************************************************************" << endl;
    cout << "\nPress enter to proceed to the commands ";
    cin.ignore();
    cin.ignore();
    cout << "\033[33mCommand are as follows: " << endl;
    cout << "\tSlide Left:  a" << endl;
    cout << "\tSlide Right: d" << endl;
    cout << "\tSlide Up:    w" << endl;
    cout << "\tSlide Down:  s" << endl;
    cout << "\tExit:        e" << endl;
    cout << "\033[0m";
    cout << "\nPress enter to continue ";
    cin.ignore();
    cout << endl;
}


void printboard(int board[4][4]) {
    // we use nested for-loops to print the 2D array board 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                cout << "\033[0m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 2)
                cout << "\033[1;32m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 4)
                cout << "\033[1;36m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 8)
                cout << "\033[1;31m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 16)
                cout << "\033[1;35m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 32)
                cout << "\033[1;33m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 64)
                cout << "\033[1;34m" << setw(3) << board[i][j] << " ";
            else if (board[i][j] == 128)
                cout << "\033[33m" << setw(3) << board[i][j] << " ";
        }
        if (board[i][3] == 0)
            cout << "\033[0m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 2)
            cout << "\033[1;32m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 4)
            cout << "\033[1;36m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 8)
            cout << "\033[1;31m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 16)
            cout << "\033[1;35m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 32)
            cout << "\033[1;33m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 64)
            cout << "\033[1;34m" << setw(3) << board[i][3] << endl;
        else if (board[i][3] == 128)
            cout << "\033[33m" << board[i][3] << endl;
    }
    cout << "\033[0m" ;
}

// This function chooses two random cells to change them to 2 or 4 randomly to create the starting board.
void createRandom(int board[4][4], int randomarr[]) {
    srand(time(NULL)); // initialize the random number generator with the current time, so that the seed is different every time

    for (int i = 0; i < 2; i++) {
        int x = rand() % 4; // choose a random line in the array
        int y = rand() % 4; // choose a random cell in the line

        // check if the cell is already occupied
        while (board[x][y] != 0) {
            y = rand() % 4; // choose another random cell
        }

        board[x][y] = randomarr[rand() % 10]; // choose a random value from randomarr assign it to the cell
    }
    printboard(board);
}


// For the player to choose the direction
char chooseDirection() {
    char x;
    cout << "Choose the direction to slide (a/w/s/d/e):";
    cin >> x;
    return x;
}


// This function is used to randomly put 2 or 4 to a randomly chosen cell after each step.
void randomNumberCell(int board[4][4], int randomarr[]) {
    srand(time(NULL));
    bool b = true;
    int x;
    while (b) {
        x = rand() % 4; // choose a random line in the array

        // check if the four cells of the line are already occupied
        for (int i = 0; i < 4; i++) {
            if (board[x][i] == 0) {
                b = false;
                break;
            }
        }
    }
    int y = rand() % 4; // choose a random cell in the line

    // check if the cell is already occupied
    while (board[x][y] != 0) {
        y = rand() % 4; // choose another random cell
    }

    board[x][y] = randomarr[rand() % 10]; // choose a random value from randarr and assign it to the cell

    printboard(board);
}


// check game status
string check_game_status(int board[4][4]) {
    // Once there is 128 in the board, the player wins immediately.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 128) {
                return "CONGRATULATIONS!!!";
            }
        }
    }

    // If the player has not won, and there are still 0s (empty cells) in the board, the game continues
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                return "Continue";
            }
        }
    }

    //If there are no 0s (empty cells), but two same numbers are next to each other (can be combined), the game continues
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) {
                return "Continue";
            }
        }
    }

    // The next two blocks are used to check the last line and the last column for numbers that can be combined
    // It is separated from the block above two avoid out of index error
    for (int i = 0; i < 3; i++) {
        if (board[3][i] == board[3][i + 1]) {
            return "Continue";
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[i][3] == board[i + 1][3]) {
            return "Continue";
        }
    }

    // If all the conditions above are not met, then the player has lost
    return "GAME OVER!!!";
}



// The following functions are used to slide to left, right, up or down.
// define a structure for the returned result of the compress, combine and slide functions
struct compress_combine_slide {
    int b[4][4];
    bool val;
};


// to compress all cells to the left side without combining them
compress_combine_slide compress_left(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    int new_board[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {

        // If there is an occupied cell (!=0）in this line, then this cell should be compressed to the first cell (board[i][0]) of this line -> position - 0
        int position = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                new_board[i][position] = board[i][j];

                // when something has changed, validity becomes true
                if (j != position) {
                    validity = true;
                }

                // when board[i][0] (the first cell of this line) is occupied, position becomes 1 (the second cell of this line)
                position++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = new_board[i][j];
    }
    result.val = validity;
    return result;
}


// to combine two same numbers
compress_combine_slide combine_left(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0) {

                // the number of the left cell becomes twice the original number
                board[i][j] = board[i][j] * 2;

                // the right cell becomes 0 (empty)
                board[i][j + 1] = 0;
                validity = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = board[i][j];
    }
    result.val = validity;
    return result;
}


// realizing sliding to the left
compress_combine_slide slide_left(int board[4][4]) {
    compress_combine_slide result1, result2, result3, result;
    result1 = compress_left(board);
    result2 = combine_left(result1.b);
    result.val = result1.val || result2.val;
    result3 = compress_left(result2.b);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = result3.b[i][j];
    }
    return result;
}


// The following functions have the same logic as sliding to the left.
// Only small changes need to be made, since sliding left combines from the left to the right, and vice versa.
// Sliding up combines from up to down, and vice versa.
compress_combine_slide compress_right(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    int new_board[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {

        // If there is an occupied cell (!=0）in this line, then this cell should be compressed to the last cell (board[i][3]) of this line -> position - 3
        int position = 3;
        for (int j = 3; j > -1; j--) {
            if (board[i][j] != 0) {
                new_board[i][position] = board[i][j];

                // when something has changed, validity becomes true
                if (j != position) {
                    validity = true;
                }

                // when board[i][3] (the first cell of this line) is occupied, position becomes 2 (the penultimate cell of this line)
                position--;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = new_board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide combine_right(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (board[i][j] == board[i][j - 1] && board[i][j] != 0) {

                // the number of the right cell becomes twice the original number
                board[i][j] = board[i][j] * 2;

                // the left cell becomes 0 (empty)
                board[i][j - 1] = 0;
                validity = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide slide_right(int board[4][4]) {
    compress_combine_slide result1, result2, result3, result;
    result1 = compress_right(board);
    result2 = combine_right(result1.b);
    result.val = result1.val || result2.val;
    result3 = compress_right(result2.b);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = result3.b[i][j];
    }
    return result;
}


compress_combine_slide compress_up(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    int new_board[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {
        int position = 0;
        for (int j = 0; j < 4; j++) {
            if (board[j][i] != 0) {
                new_board[position][i] = board[j][i];
                if (j != position) {
                    validity = true;
                }
                position++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = new_board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide combine_up(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == board[j + 1][i] && board[j][i] != 0) {
                board[j][i] = board[j][i] * 2;
                board[j + 1][i] = 0;
                validity = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide slide_up(int board[4][4]) {
    compress_combine_slide result1, result2, result3, result;
    result1 = compress_up(board);
    result2 = combine_up(result1.b);
    result.val = result1.val || result2.val;
    result3 = compress_up(result2.b);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = result3.b[i][j];
    }
    return result;
}


compress_combine_slide compress_down(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    int new_board[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {
        int position = 3;
        for (int j = 3; j > -1; j--) {
            if (board[j][i] != 0) {
                new_board[position][i] = board[j][i];
                if (j != position) {
                    validity = true;
                }
                position--;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = new_board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide combine_down(int board[4][4]) {
    compress_combine_slide result;
    bool validity = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (board[j][i] == board[j - 1][i] && board[j][i] != 0) {
                board[j][i] = board[j][i] * 2;
                board[j - 1][i] = 0;
                validity = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = board[i][j];
    }
    result.val = validity;
    return result;
}


compress_combine_slide slide_down(int board[4][4]) {
    compress_combine_slide result1, result2, result3, result;
    result1 = compress_down(board);
    result2 = combine_down(result1.b);
    result.val = result1.val || result2.val;
    result3 = compress_down(result2.b);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            result.b[i][j] = result3.b[i][j];
    }
    return result;
}


bool main_128() {

    // to store the game status
    string status;

    int board[4][4] = { 0 };

    // list for generating random numbers in the board
    int randomarr[10] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 4 };

    // list to check whether the player's input is valid
    char validarr[5] = { 'a', 'w', 's', 'd', 'e' };

    Welcome();

    // creates and prints the random starting board
    createRandom(board, randomarr);
    while (true) {
        char direction = chooseDirection();
        compress_combine_slide result;

        // check whether the input is valid
        if (find(begin(validarr), end(validarr), direction) == end(validarr)) {
            cout << "\033[33m";
            cout << "Invalid input, please choose direction again." << endl;
            cout << "\033[0m";
            printboard(board);
            cout << "Continue" << endl;
            cout << endl;
            continue;
        }

        // exit
        if (direction == 'e') {
            cout << "\033[31m";
            cout << "GAME OVER!!!" << endl;
            cout << "\033[0m";
            cout << endl;
            break;
        }

        // slide left
        else if (direction == 'a')
            result = slide_left(board);

        // slide right
        else if (direction == 'd')
            result = slide_right(board);

        // slide up
        else if (direction == 'w')
            result = slide_up(board);

        // slide down
        else if (direction == 's')
            result = slide_down(board);

        // When nothing in the board has changed, neither compressed nor combined -> slide direction invalid
        if (result.val == false) {
            cout << "\033[33m";
            cout << "Invalid direction, please choose direction again." << endl;
            cout << "\033[0m";
            printboard(board);
            cout << "Continue" << endl;
            cout << endl;
            continue;
        }

        // silde direction valid
        else if (result.val = true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++)
                    board[i][j] = result.b[i][j];
            }

            // add randomly 2 or 4 to an empty cell
            randomNumberCell(board, randomarr);

            // check whether win or lose or continue
            status = check_game_status(board);

            if (status == "Continue") {
                cout << status << endl;
                cout << endl;
                continue;
            }

            if (status == "CONGRATULATIONS!!!") {
                cout << endl;
                cout << "\033[32m";
                cout << status << endl;
                cout << "\033[0m";
                cout << endl;
                break;
            }

            if (status == "GAME OVER!!!") {
                cout << endl;
                cout << "\033[31m";
                cout << status << endl;
                cout << "\033[0m";
                cout << endl;
                break;
            }

        }
    }
    cout << "\033[33mPress Enter to return to the map.";
    cin.ignore();
    cout << "\033[0m";
    return (status == "CONGRATULATIONS!!!");
}

