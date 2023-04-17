#include <iostream>  
#include <string>
#include <sstream>
#include <cctype>

using namespace std;


// This is a math game to compute the correct number to get marks.

void show_rule() {
    //show the rules of the game.
    cout << "                                      I LOVE MATH\nINSTRUCTION:\n"
        "This game may involve calculus\nQ1-20 carry 1 marks each\n"
        "Q21-40 carry 3 marks each\nQ41-50 carry 5 marks each\nGet 11 marks to have a key\n"
        "You cannot choose the same question more than one time\n"
        "If you cannot handle the game, type e to leave the game after the game start but you will lost a key=_=\n"
        "For calculus question, the answer should be the same sequence"
        " and format as the question e.g. d/dx(-2x+3x^3)=-2+9x^2\n"
        "You Are NOT ALLOW To Use CALCULATOR";
    string x;
    cout << "TYPE --ok-- TO CONTINUE: ";
    cin >> x;
    system("CLS");
    while (x != "ok") {
        cout << "TYPE --ok-- TO CONTINUE: ";
        cin >> x;
        system("CLS");
    }
    int count = 0;
}

bool Isinteger(string s) {
    //This function tries to avoid the input error(not an integer)
    try {
        stoi(s);
        // try to transfer s to an interger
        return true;
        // true
    }
    catch (const invalid_argument& e) {
        // if it is not an integer, return false.
        return false;
    }
}

// Core of game
int mathgame() {

    int count = 0;
    // Stores answered questions
    string questions[50][3] = {
        {"1+1*2 = ", "3", "1"},
        {"2+5*3 = ", "17", "1"},
        {"4*(6+2) = ", "32", "1"},
        {"7*(6+5) = ", "77", "1"},
        {"3*2*5 = ", "30", "1"},
        {"9*6+2 = ", "56", "1"},
        {"5*(9+2) = ", "55", "1"},
        {"6*(11+2) = ", "78", "1"},
        {"5*5+4 = ", "29", "1"},
        {"8*(3+3) = ", "48", "1"},
        {"5*(6+10) = ", "80", "1"},
        {"7*(6+1) = ", "49", "1"},
        {"9*(9+2) = ", "99", "1"},
        {"2+2+15 = ", "19", "1"},
        {"8+3*4 = ", "20", "1"},
        {"5*(6+7) = ", "65", "1"},
        {"6*6 = ", "36", "1"},
        {"8*8 = ", "64", "1"},
        {"5*5+1 = ", "26", "1"},
        {"4*4+3 = ", "19", "1"},
        {"4*4*4 = ", "64", "3"},
        {"3!(!=factorial) = ", "6", "3"},
        {"4!(!=factorial) = ", "24", "3"},
        {"6*6*3 = ", "108", "3"},
        {"7^3 = ", "343", "3"},
        {"45*4 = ", "180", "3"},
        {"50*11 = ", "550", "3" },
        {"10*(8+3*3) = ", "170", "3"},
        {"7*5*(2+4)= ", "210", "3"},
        {"8+8*3^2 = ", "80", "3"},
        {"(9 + 6) * 4 * 2 = ", "120", "3"},
        {"(7 + 5) * 4 * 3 = ", "144", "3"},
        {"5*6*7*2 = ", "420", "3"},
        {"7*2*4*(2+3) = ", "280", "3"},
        {"5*4*3*2*(4+3) = ", "840", "3"},
        {"6*4*3! = ", "144", "3"},
        {"7*4*3*10 = ", "840", "3"},
        {"4!*5 = ", "120", "3"},
        {"5*4*3!(!=factorial) = ", "120", "3"},
        {"7*4*10 = ", "280", "3"},
        {"d / dx(8x + 2x ^ 3) = ", "8+6x^2", "5"},
        {"d / dx(sinx + cosx + tanx) = ", "cosx-sinx+(secx) ^ 2", "5"},
        {"d / dx(4 - 9x + 6x ^ 3) = ", " - 9+18x^2", "5" },
        {"d / dx(-secx + cosx) = ", " - secxtanx-sinx", "5" },
        {"Integrate(5 + 2x) = ", "5x+x^2+C", "5"},
        {"Integrate(sinx - cosx + 4x) = ", "- cosx-sinx+2x^2+C", "5"},
        {"Integrate((secx) ^ 2 + cosx) = ", "tanx+sinx+C", "5"},
        {"Integrate(10 - (cscx) ^ 2) = ", "10x+cotx+C", "5"},
        {"d / dx(3 + 4 + 6x ^ 2) = ", "12x", "5"},
        {"d / dx((7x + 3x + 10x) - sinx) = ", "20-cosx", "5"} };
    while (count < 11) {
        string n;
        cout << "Question number? (1-50)/exit(0): ";
        cin >> n;
        while (!Isinteger(n)) {
            cout << "Invalide input, please try again" << endl;
            cin >> n;
            if (n == "0") {
                cout << "Bye Bye!!!" << endl;
                return 0;
            }
        }
        int num;
        num = stoi(n);
        while (!(num >= 0 && num <= 50)) {
            cout << "Invalid input!try again!" << endl;
            cin >> n;
            num = stoi(n);
        }
        if (num == 0) {
            cout << "BYE!!NO KEY\nBACK TO YOUR ASSIGNMENTS!!" << endl;
            break;
        }
        cout << questions[num - 1][0] << endl;
        string ans;
        cout << "Your answer is: (no need to input a space)" << endl;
        cin >> ans;
        if (ans == questions[num - 1][1]) {
            int x;
            stringstream ss;
            ss << questions[num - 1][2];
            ss >> x;
            count += x;
            cout << "-->Correct<--" << endl;
            system("pause");
            system("CLS");
        }
        else {
            cout << "-->Wrong<--" << endl;
            cout << "The correct answer is: " << questions[num - 1][1] << endl;
            system("pause");
            system("CLS");

        }
        cout << "Total marks : " << count << endl;
        system("pause");
        system("CLS");
    }

    if (count >= 11) {
        cout << "Congratulations!!!!" << endl;
        system("pause");
        system("CLS");

    }

    return count;
}


int matchnum() {
    system("CLS");
    show_rule();
    int mark = mathgame();
    if (mark >= 11)
        return 1;
    else return 0;

}
