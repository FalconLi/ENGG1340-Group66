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
        if (!isdigit(ch)) {
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
        return "time spent: " + to_string(y) + "sec";
    }
    else {
        return "time spent: " + to_string(x) + "min " + to_string(y) + "sec";
    }
}
