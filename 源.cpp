#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include<ctime>

ifstream fin;
string line;
int ct_map_line=0, pos_colomn, pos_line;
string map_array[25];
char destination, character, move_direction;
string barrier[1] = {"-|"};

void background() {
	//give the background of the game, fin from file
}

void initialize() {
	//initialize the map, maybe getline from file.
	map_array[16] = "--";
	// set destination
	destination = map_array[16][1];
	character = 'X';

	fin.open("initial_map.txt");
	while (getline(fin, line))
	{
		map_array[ct_map_line] = line;
		ct_map_line++;
	}
	fin.close();

	//initial character site
	map_array[16][3] = character;
}

void show_map() {
	//cout the map
	for (int i = 0; i < ct_map_line; i++)
		cout << map_array[i] << endl;
}

void move() {
	//change the place in array.
	cout << "Where you wanna escape?" << endl;
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

	else if (move_direction == 'a' && barrier[0].find(map_array[pos_line][pos_colomn-1]) == -1)
	{
		map_array[pos_line][pos_colomn-1] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 's' && barrier[0].find(map_array[pos_line + 1][pos_colomn]) == -1)
	{
		map_array[pos_line + 1][pos_colomn] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else if (move_direction == 'd' && barrier[0].find(map_array[pos_line][pos_colomn+1]) == -1)
	{
		map_array[pos_line][pos_colomn+1] = character;
		map_array[pos_line][pos_colomn] = ' ';
	}

	else
	{
		cout << "No way to go!" << endl;
		move();
	}
}

void enter_secret() {
	//give site to enter the secret.
}

void last_word() {
	//give the final word to say.
}



int main() {
	background();
	initialize();

	//decide whether the character reaches the destination
	while (character != destination)
	{

		show_map();
		move();
		enter_secret();
	}
	last_word();
}