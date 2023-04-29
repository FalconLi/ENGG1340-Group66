#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


// Check whether the user input only contains digits
bool is_digits(string str) {
    for (char ch : str) {
        if (!isdigit(ch) && ch != '-') {
            return false;
        }
    }
    return true;
}


// Fetch the previous timestamp and continue calculate how much time is used.
string timeuse(time_t time, time_t t1) {
    int x = (time - t1) / 60;
    int y = (time - t1) % 60;
    if (x == 0) {
        return "Time spent: " + to_string(y) + "sec";
    }
    else {
        return "Time spent: " + to_string(x) + "min " + to_string(y) + "sec";
    }
}


// Main function of minigame guess the number, given 't1' as the starting timestamp in the main function
bool guessnumber() {
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
    
    cout << "\033[33mThere is a random number between 1-20 (1 & 20 included). \n" 
        << "If you guess it right, you will pass the trial.\n"
        << "You only have 2 minutes!" << endl;
    cout << "\033[0m";
    cout << "\nPress Enter to continue";
    cin.ignore();
    
    time_t t1 = time(NULL);

    // initialize the random number generator with the current time, so that the seed is different every time
    srand(time(NULL)); 
    int number = rand() % 20 + 1;
    string guess;
    cout << "\n" << "\033[1;31m" << timeuse(time(NULL), t1) << "\033[0m" << "\nGuess(a number 1-20) or exit(e): ";
    cin >> guess;
    while (guess != "e" && guess != to_string(number)) {
        if (time(NULL) - t1 >= 120) {
            cout << endl;
            cout << "\033[1;31m";
            cout << timeuse(time(NULL), t1) << endl;
            cout << "Times up!" << endl;
            cout << "\033[0m";

            // even if the player guessed the number right, but if 2 minutes are over, the player has still lost, therefore set guess = "0" (can't be right, since number is between 1 and 20)
            guess = to_string(0);
            break;
        }
        if (is_digits(guess)) {
            if (stoi(guess) > 20 || stoi(guess) < 1) {
                cout << "\033[33m";
                cout << "Invalid number, please guess again." << endl;
                cout << "\033[1;31m";
                cout << "\n" << timeuse(time(NULL), t1) << "\033[0m" << "\nGuess(a number 1-20) or exit(e): ";
                cin >> guess;
                continue;
            }
            else if (stoi(guess) < number) {
                cout << guess << " is too small." << endl;
            }
            else if (stoi(guess) > number) {
                cout << guess << " is too large." << endl;
            }
            else {
                cout << "\033[1;32mYou've got the right number." << endl;
                cout << "\033[0m";
                break;
            }
        }
        if (is_digits(guess) == false) {
            cout << "\033[33m";
            cout << "Invalid input, please guess again." << endl;
            cout << "\033[1;31m";
            cout << "\n" << timeuse(time(NULL), t1) << "\033[0m" << "\nGuess(a number 1-20) or exit(e): ";
            cin >> guess;
            continue;
        }
        cout << "\033[1;31m";
        cout << "\n" << timeuse(time(NULL), t1) << "\033[0m" << "\nGuess(a number 1-20) or exit(e): ";
        cin >> guess;
    }
    cout << "\033[33m" << "\nPress Enter to return to the map.";
    cin.ignore();
    cout << "\033[0m";
    return guess == to_string(number);
}

