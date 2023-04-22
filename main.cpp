#include<iostream>
#include<fstream>
#include<string>
#include<ctime>   
#include <sstream>
#include <cctype>
#include <vector>

#include "128functions.h"
#include "hangmangame.h"
#include "Stonegame.h"
#include "guessnumber.h"
#include "matchnum.h"
//#include "piggame.h"
using namespace std;

ifstream fin;
string line;
int ct_map_line = 0, pos_colomn, pos_line;
string map_array[27];
char destination, character, move_direction, door = '\\', door_2 = '/', open_door = ' ', site_1, site_1_trigger, site_2, site_2_trigger, site_3, site_3_trigger, site_4, site_4_trigger, site_5, site_5_trigger, site_6, site_6_trigger, play_or_not;
string barrier[1] = { "-|_#/\\HW312Lift" };

void background() {
	//give the background of the game, fin from file
}

void initialize() {
	//initialize the map, maybe getline from file.
	map_array[16] = "--";
	// set destination
	character = char(23);

	fin.open("initial_map.txt");
	while (getline(fin, line))
	{
		map_array[ct_map_line] = line;
		ct_map_line++;
	}
	fin.close();

	//initial character site
	map_array[20][82] = character;
}

void show_map() {
	//cout the map
	for (int i = 0; i < ct_map_line; i++)
		cout << map_array[i] << endl;
}

void move() {
	//change the place in array.
	cout << "Where do you wanna escape?" << endl;
	cout << "Your movement: ";
	cin >> move_direction;

	//find current location
	for (int i = 0; i <= ct_map_line; i++)
	{
		//if cannot find character on the line, go to next line
		if (map_array[i].find(character) == -1)
		{
			continue;
		}

		else {
			pos_colomn = map_array[i].find(character);
			pos_line = i;
		}
	}

	if (move_direction == 'w' && barrier[0].find(map_array[pos_line - 1][pos_colomn]) == -1)
	{
		map_array[pos_line - 1][pos_colomn] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 'a' && barrier[0].find(map_array[pos_line][pos_colomn - 1]) == -1)
	{
		map_array[pos_line][pos_colomn - 1] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 's' && barrier[0].find(map_array[pos_line + 1][pos_colomn]) == -1)
	{
		map_array[pos_line + 1][pos_colomn] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 'd' && barrier[0].find(map_array[pos_line][pos_colomn + 1]) == -1)
	{
		map_array[pos_line][pos_colomn + 1] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 't')
	{
		int li, col;
		cout << "where to transport" << endl;

		cin >> li >> col;
		map_array[li][col] = character;
		map_array[pos_line][pos_colomn] = ' ';

	}

	else
	{
		cout << "No way to go!" << endl;
	}
}

void enter_secret() {
	//update the site status.
	site_1 = map_array[7][81];
	site_1_trigger = map_array[8][81];
	site_2 = map_array[10][43];
	site_2_trigger = map_array[9][43];
	site_3 = map_array[18][67];
	site_3_trigger = map_array[18][66];
	site_4 = map_array[17][44];
	site_4_trigger = map_array[17][43];
	site_5 = map_array[7][88];
	site_5_trigger = map_array[6][88];
	site_6 = map_array[0][0];
	site_6_trigger = map_array[0][0];

	//give site to enter the secret.
	if (site_1_trigger == character && site_1 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		if (play_or_not == 'y')
		{
			if (hangmangame())
			{
				site_1 = open_door;
				map_array[7][81] = site_1;
			}
		}

	}

	else if (site_2_trigger == character && site_2 == door_2)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		if (play_or_not == 'y')
		{
			if (Stonegame())
			{
				site_2 = open_door;
				map_array[10][43] = site_2;
			}
		}

	}
	
	else if (site_3_trigger == character && site_3 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		if (play_or_not == 'y')
		{
			if (matchnum())
			{
				site_3 = open_door;
				map_array[18][67] = site_3;
			}
		}

	}

	
	else if (site_4_trigger == character && site_4 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		if (play_or_not == 'y')
		{
			if (guessnumber())
			{
				site_4 = open_door;
				map_array[17][44] = site_4;
			}
		}
	}
	
	else if (site_5_trigger == character && site_5 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		if (play_or_not == 'y')
		{
			if (main_128())
			{
				site_5 = open_door;
				map_array[7][88] = site_5;
			}

		}

	}

	/*
	else if (site_6_trigger == character && site_6 == door)
	{
		if (game())
		{
			site_6 = open_door;
			map_array[0][0] = site_6;
		}

	}
	*/

}

void last_word() {
	//give the final word to say.
}



int main() {
	background();
	initialize();

	//fixed places
	destination = map_array[21][84];



	//decide whether the character reaches the destination
	while (character != destination)
	{
		system("CLS");
		show_map();
		move();
		enter_secret();
	}
	last_word();
}
