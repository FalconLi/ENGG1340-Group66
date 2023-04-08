#include<iostream>
#include <cstdlib>
using namespace std;

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
	while (data.database != 1 && data.database != 2)
	{
		cout << "Input wordguess set (1 for fruits, 2 for sports): " << endl;
		cin >> data.database;
	}
	//automatically set the seed
	srand(time(NULL));
	data.randword = choice[data.database - 1][rand() % 8];

	return data;
}

int main() {
	// generate the random word
	choose_word target_word = choose();
}