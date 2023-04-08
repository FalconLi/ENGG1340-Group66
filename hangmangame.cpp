#include<iostream>
#include <cstdlib>
using namespace std;

int number_of_chances;

struct choose_word
{
	int database;
	string randword;
};

string choice[2][7] = { {"apple", "banana", "blueberry", "grape", "lemon", "mango", "orange"}, {"football", "basketball", "bicycling ", "baseball", "volleyball", "yoga", "diving"} };

choose_word choose()
{
	choose_word data;
	cout << "Input wordguess set (1 for fruits, 2 for sports): " << endl;
	cin >> data.database;
	while (data.database != 1 && data.database!=2)
	{
		cout << "Input wordguess set (1 for fruits, 2 for sports): " << endl;
		cin >> data.database;
	}
	//automatically set the seed
	srand(time(NULL));
	data.randword = choice[data.database-1][rand() % 8];

	return data;
}

void state(int number_of_chances) {
	string countdown = { "|O/|\\|/\\"};
	string current;
	current = countdown.substr(0, n);
	for (int i = 0; i < 9 - n; i++)
	{
		current.insert(current.length() - 1, " ");
	}
	cout << "+--------+" << endl;
	cout <<" " << current[0] << "       | |"<<endl;
	cout << " " << current[1] << "       | |" << endl;
	cout << current[2] << current[3] << current[4] << "      | |"<<endl;
	cout <<" " <<current[5] << "       | |\n";
	cout << current[6] << " " << current[7] << "      | |" << endl;
	cout << "         | |" << endl;
	cout << " ________|_|___" << endl;
}


int main() {
	// generate the random word
	choose_word target_word = choose();
}
