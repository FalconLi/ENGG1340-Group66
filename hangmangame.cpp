#include<iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <unistd.h>
using namespace std;

int number_of_chances, guesses_length, data_trans;
string now, guess;


struct choose_word
{
	string database;
	string randword;
};

string choice[2][7] = { {"apple", "banana", "blueberry", "grape", "lemon", "mango", "orange"}, {"football", "basketball", "bicycling ", "baseball", "volleyball", "yoga", "diving"} };

choose_word choose()
{
	choose_word data;
	cout << "Input wordguess set (1 for fruits, 2 for sports): " << endl;
	cin >> data.database;
	while (data.database != "1" && data.database != "2")
	{
		cout << "Input wordguess set (1 for fruits, 2 for sports): " << endl;
		cin >> data.database;
	}
	//automatically set the seed
	srand(time(NULL));

	if (data.database == "1")
		data_trans = 1;
	else if (data.database == "2")
		data_trans = 2;
	data.randword = choice[data_trans - 1][rand() % 8];
	return data;
}

void state(int number_of_chances) {
	string countdown = { "|O/|\\|/\\" };
	string current;
	current = countdown.substr(0, number_of_chances);
	for (int i = 0; i < 9 - number_of_chances; i++)
	{
		current.insert(current.length() - 1, " ");
	}
	cout << "+--------+" << endl;
	cout << " " << current[0] << "       | |" << endl;
	cout << " " << current[1] << "       | |" << endl;
	cout << current[2] << current[3] << current[4] << "      | |" << endl;
	cout << " " << current[5] << "       | |\n";
	cout << current[6] << " " << current[7] << "      | |" << endl;
	cout << "         | |" << endl;
	cout << " ________|_|___" << endl;
}


int hangmangame() {
	//intro
	system("clear");
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
	cout << "Win the hangman game if you want to pass the trial. " << endl;
	cout << "Guess the character in the word correctly before the hangman dies." << endl;
	cout << "\nPress Enter to continue";
	cin.ignore();
        cin.ignore();
	system("clear");
	// generate the random word
	choose_word target_word = choose();
	//start
	now = "";
	for (int i = 0; i < target_word.randword.length(); i++)
	{
		now.insert(0, "_");
	}



	//initialize all the guesses by the player.
	string guesses[8] = {};
	guesses_length = 0;

	//set the 8 chances of the game;
	while (guesses_length < 8)
	{
		cout << "Guess a character/ hint / exit : " << endl;
		cin >> guess;
		system("clear");

		//change all letters in guess into lowercase.
		if (guess >= "A" && guess <= "Z" && guess.length() == 1)
			guess += 32;

		if (guess == "exit")
		{
			cout << "you quit!";
			return false;
		}

		if (guess == "hint")
		{
			cout << "Hints: start by guessing common letters like vowels, or s, t, and n." << endl;
			continue;
		}

		else if (guess.length() == 1 && guess >= "a" && guess <= "z")
		{
			// if guess is a character in the target_word.
			if (target_word.randword.find(guess) != -1)
			{
				// if the character was guessed before
				if (find(guesses, guesses + guesses_length, guess) != guesses + guesses_length)
				{
					cout << "You have tried " << guess << " before!" << endl;

				}

				else
				{
					cout << "Correct! There is " << guess << " in the word!!!" << endl;
					for (int i = 0; i < target_word.randword.length(); i++)
					{
						if (target_word.randword[i] == guess[0])
							now[i] = guess[0];
					}


				}
			}


			// if the word is already guessed.
			else if (find(guesses, guesses + guesses_length, guess) != guesses + guesses_length)
			{
				cout << "You have tried " << guess << " before!" << endl;

			}

			else
			{
				guesses_length++;
				guesses[guesses_length - 1] = guess;
				cout << "Incorrect!" << endl;
				cout << "You have " << 8 - guesses_length << " chances left!" << endl;
				state(guesses_length + 1);
			}
		}

		//show the invalid input
		else
		{
			cout << "Invalid input" << endl;

		}

		for (int i = 0; i < now.length(); i++)
			cout << now[i];
		cout << endl;

		//show the guessed wrong letters
		cout << "Guessed wrong letters: ";
		for (int i = 0; i < guesses_length; i++)
			cout << guesses[i] << " ";

		cout << endl;

		if (now.find('_') == -1)
		{
			cout << endl;
			cout << "\033[32mYou Win!" << endl;
			cout << endl;
			cout << "\033[0m";
			cout << "Press Enter to return to the map.";
    			cin.ignore();
			cin.ignore();
			return true;
		}

	}
	cout << endl;
	cout << "\033[31mYou Lost TAT" << endl;
	cout << endl;
	cout << "\033[0m";
	cout << "Press Enter to return to the map.";
    	cin.ignore();
	cin.ignore();
	return false;
}
