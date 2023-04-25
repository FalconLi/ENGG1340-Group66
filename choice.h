#ifndef CHOICE_H
#define CHOICE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

struct player;
struct boss;
struct event;
void showtime(string w);
void changearmynum(player &a, double factor);
void roadbonus(player &a, string oper, int by);
void seekbest(int &a,string oper,int by);
void showinfo(player &a);
void showbossinfo(boss &a);
int getVal(int defaultValue);
int chooseroad(player &a);
void sbpart(player &a,string b,event eventlist[],int &best);
void idiotpart(player &a,boss bosslist[]);
bool choice();

#endif