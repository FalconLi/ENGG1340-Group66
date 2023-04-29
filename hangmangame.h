#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include<iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

struct choose_word;
choose_word choose();
void state(int number_of_chances);
int hangmangame();

#endif
