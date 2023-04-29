//128functions.h
#ifndef 128FUNCTIONS_H
#define 128FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

void Welcome();
void printboard(int board[4][4]);
void createRandom(int board[4][4], int randomarr[]);
char chooseDirection();
void randomNumberCell(int board[4][4], int randomarr[]);
string check_game_status(int board[4][4]);

struct compress_combine_slide {
    int b[4][4];
    bool val;
};

compress_combine_slide compress_left(int board[4][4]);
compress_combine_slide combine_left(int board[4][4]);
compress_combine_slide slide_left(int board[4][4]);

compress_combine_slide compress_right(int board[4][4]);
compress_combine_slide combine_right(int board[4][4]);
compress_combine_slide slide_right(int board[4][4]);

compress_combine_slide compress_up(int board[4][4]);
compress_combine_slide combine_up(int board[4][4]);
compress_combine_slide slide_up(int board[4][4]);

compress_combine_slide compress_down(int board[4][4]);
compress_combine_slide combine_down(int board[4][4]);
compress_combine_slide slide_down(int board[4][4]);

bool main_128();

#endif

