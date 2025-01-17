#include<iostream>
#include<fstream>
#include<string>
#include<ctime>   
#include <sstream>
#include <cctype>
#include <vector>
#include <unistd.h>
#include "128functions.h"
#include "hangmangame.h"
#include "Stonegame.h"
#include "guessnumber.h"
#include "matchnum.h"
#include "choice.h"
//#include "piggame.h"
using namespace std;

//declare all the variables first
ifstream fin, finin;
string line;
int ct_map_line = 0, pos_colomn, pos_line, score=0, final_count=0;
string map_array[27];
char destination, character, move_direction, door = '\\', door_2 = '/', open_door = ' ', site_1, site_1_trigger, site_2, site_2_trigger, site_3, site_3_trigger, site_4, site_4_trigger, site_5, site_5_trigger, site_6, site_6_trigger, play_or_not;
string barrier[1] = { "-|_#/\\HW1234567890.Lift" };

//initialize the map, download the map to a 2D array from draft_map.txt line by line
void initialize() {
	//initialize the map, maybe getline from file.
	map_array[16] = "--";
	// set destination
	character = char(38);

	fin.open("draft_map.txt");
	while (getline(fin, line))
	{
		map_array[ct_map_line] = line;
		ct_map_line++;
	}
	fin.close();

	//initial character site
	map_array[20][82] = character;
	map_array[21][85] = '+';
}

//cout the map from the array
void show_map() {
	//cout the map
	for (int i = 0; i < ct_map_line; i++)
		cout << map_array[i] << endl;
}

// function to get the input from users to make the movement command.
void move() {
	//change the place in array.
	cout << "Where do you wanna rush?" << endl;
	cout << "Your movement: ";
	cin.clear();
	//give the direction to move
	cin >> move_direction;
	//find current location
	for (int i = 0; i < ct_map_line; i++)
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
		cout << "Where to transport (<First coordinate (Range: 1-25)> <Second coordinate (Range: 1-97)>): ";
		//give the coordinate for transport
		cin >> li >> col;
		while (!(li >= 1 && li <= 25) || !(col >= 1 && col <= 97)) {
			if (!(li >= 1 && li <= 25) && !(col >= 1 && col <= 97)) {
				cout << "Invalid line-number and column-number, please input coordinate again." << endl;
			}	
			else if (!(li >= 1 && li <= 25)) {
				cout << "Invalid line-number, please input coordinate again." << endl;
			}
			else if (!(col >= 1 && col <= 97)) {
				cout << "Invalid column-number, please input coordinate again." << endl;
			}
			cout << endl;
			cout << "Where to transport (<First coordinate (Range: 1-25)> <Second coordinate (Range: 1-97)>): ";
			cin >> li >> col;
		}	
		map_array[li][col] = character;
		map_array[pos_line][pos_colomn] = ' ';

	}

	else
	{
		cout << "No way to go!" << endl;
	}
}

//function to decide wheather the player is at the "door", to trigger the trials.
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
	site_6 = map_array[7][78];
	site_6_trigger = map_array[8][78];

	//give site to enter the secret.
	if (site_1_trigger == character && site_1 == door)
	{
		cout << "Enter? y/n: ";
		//confirm to play the game or not
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (hangmangame())
			{
				site_1 = open_door;
				map_array[7][81] = site_1;
				score++;
			}
		}

	}

	else if (site_2_trigger == character && site_2 == door_2)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (matchnum())
			{
				site_2 = open_door;
				map_array[10][43] = site_2;
				score++;
			}
		}

	}

	else if (site_3_trigger == character && site_3 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (choice())
			{
				site_3 = open_door;
				map_array[18][67] = site_3;
				score++;
			}
		}

	}


	else if (site_4_trigger == character && site_4 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (guessnumber())
			{
				site_4 = open_door;
				map_array[17][44] = site_4;
				score++;
			}
		}
	}

	else if (site_5_trigger == character && site_5 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (main_128())
			{
				site_5 = open_door;
				map_array[7][88] = site_5;
				score++;
			}

		}

	}
	else if (site_6_trigger == character && site_6 == door)
	{
		cout << "Enter? y/n: ";
		cin >> play_or_not;
		system("clear");
		if (play_or_not == 'y')
		{
			if (Stonegame())
			{
				site_6 = open_door;
				map_array[7][78] = site_6;
				score++;
			}



		}
	}
}

//function to show the story in the beginning.
void open_word() {
	system("clear");
	finin.open("story_2.txt");
	string line_2;
	cout<<"\033[1;36m";
	while (getline(finin, line_2))
	{
		cout<<line_2<<endl;
		sleep(2);
	}
	cout<<"\033[0m";
	finin.close();
}


// the drive function
int main() {
	open_word();
	cout << endl;
	cout << "To win the game, pass 5 out of 6 trials and return to the \"+\" sign in the lift." << endl;
	cout<<"\nPress Enter to continue";
	//act as system("pause") in linux environment
	cin.ignore();
	initialize();

	//fixed places
	destination = map_array[21][84];



	//decide whether the character reaches the destination
	while (character != destination){
		system("clear");
		show_map();
		
		//trigger the tips once the character is at '?'.
		if (map_array[13][81]==character){
			cout<<"\033[1;36m";
                        cout<<"Tips: input multiple directions at one time can move faster! e.g. aaaaa."<<endl;
			cout<<"\033[0m";
                }
		
		//trigger the skill once the charater is at '!'.
		if (map_array[10][78]==character){
			cout<<"\033[1;36m";
			cout<<"Congratulations! After passing through the hardest trial in HKU, you learnt a SKILL!"<<endl;
			cout<<"SKILL: Transport."<<endl;
			cout<<"While choosing direction, input 't', and then input the coordinate of the place you wanna go!"<<endl;
			cout << "Format of inputting coordinate: <First coordinate (Range: 1-25)> <Second coordinate (Range: 1-97)>." << endl;
			cout<<"\033[0m";
		}
		
		move();
		enter_secret();
		
		//decide if the condition for success is achieved.
		if (score >= 5 && final_count == 0)
		{
			cout<<"Major requirement achieved!"<<endl;
			cout<<"Please collect your major offer at the elevator!"<<endl;
			map_array[19][83] = ' ';
			map_array[20][83] = ' ';
			map_array[21][83] = ' ';
			final_count++;
		}
		if (map_array[21][85] == character)
		{
			cout<<endl<<"\033[5;32mFanfan has successfully passed "<<score<<" out of 6 trials!"<<endl<<"He got his desired major!!!"<<endl<<endl;
			cout<<"\033[0m";
			cin.ignore();			
			break;
		}
	}
}
