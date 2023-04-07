#include <iostream>
#include <cstdlib>   // include random
#include <ctime>     
#include <vector>

using namespace std;


void show() {

    cout << "**************************************************" << endl;
    cout << "  __        __   _                          " << endl;
    cout << "  \\ \\      / /__| | ___ ___  _ __ ___   ___ " << endl;
    cout << "   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
    cout << "    \\ V  V /  __/ | (_| (_) | | | | | |  __/" << endl;
    cout << "     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl;
    cout << endl;
    cout << "**************************************************" << endl;
    cout << endl;

    //Show the rule of the Stone Game.
    cout << "Here is a game introduction for the game of Stones:" << endl;
    cout << "The game of Stones is a simple yet entertaining mathematical game." << endl << endl;
    cout << "The rules are straightforward : " << endl;
    cout << "there is a pile of stones, and two players (one is computer) take turns to remove 1 to 3 stones from the pile, " << endl;
    cout << "until there are no stones left." << endl;
    cout << "The player who takes the last stone loses." << endl;

    cout << "***************************************************" << endl;
    cout << "After you input the number of the total stones." << endl;
    cout << "You can see that wheather there is a win strategy for you." << endl;
    cout << "Then you can try to beat the computer if there exist a stratery for you." << endl;

    cout << "**********Wish you have fun playing the game!!!!**********" << endl;
    cout << endl;

    std::cout << "             ____            \n"
        << "          .-'    `-.         \n"
        << "       __/          \\__      \n"
        << "    .-'   o      o     `-.   \n"
        << "   /      _.--._       a \\  \n"
        << "  /  .   /       \\   =   /  \n"
        << "  |   \\_|         |     /   \n"
        << "  \\    / `\\_     _/    /    \n"
        << "   `._'     `---'     .'     \n"
        << "      `-.         .-'        \n"
        << "         `-------'           \n"
        << std::endl;

}

bool canWin(int n) {

    //This function uses dynamic management to judge Whether the player has a winning strategy.

    if (n == 1) {
        return false;
    }
    if (n <= 4) {
        return true;
    }

    vector<bool> dp(n + 1);
  
    dp[2] = true;
    dp[3] = true;
    dp[4] = true;

    //Recursionand memorization are adopted
    for (int i = 4; i <= n; i++) {
        dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
    }

    return dp[n];
}


int play() {
    //Show the rule first.
    show();

    int numStones;
    cout << "Enter the number of stones(10~100)(0 to exit): ";
    cin >> numStones;

    //0 to exit game.
    if (numStones == 0) {
        cout << "Bye Bye!!!" << endl;
        return 0;
    }

    while (!(numStones <= 100 && numStones >= 10)) {
        cout << "Invalide input, please try again" << endl;
        cin >> numStones;
    }

    if (canWin(numStones)) {
        cout << endl << "----->The current player has a win strategy.<-----" << endl << endl;
    }

    else {
        cout << endl << "----->The current player doesn't have a win strategy.<-----" << endl << endl;
    }

    bool isPlayerTurn = true;
    while (numStones > 0) {
        cout << "There are " << numStones << " stones left." << endl;

        if (isPlayerTurn) {
            int playerMove;
            cout << "Enter your move (1-3)(0 to exit): ";
            cin >> playerMove;

            while (playerMove != 0 && playerMove != 1 && playerMove != 2 && playerMove != 3) {
                cout << "Invalid input, please try again." << endl;
                cout << "Enter your move (1-3)(0 to exit): ";
                cin >> playerMove;
            }

            if (playerMove == 0) {
                cout << endl;
                cout << "Bye Bye!!!" << endl;
                return 0;
            }

            numStones -= playerMove;
            cout << "You take " << playerMove << " stones." << endl;
            cout << endl;
        }
        else {
            // 电脑玩家随机选择 1 到 3 个石头
            int computerMove = rand() % 3 + 1;
            numStones -= computerMove;
            cout << "The computer takes " << computerMove << " stones." << endl;
            cout << endl;
        }
        isPlayerTurn = !isPlayerTurn;
    }

    if (isPlayerTurn) {
        cout << "**********" << endl;
        cout << " You win! " << endl;
        cout << "**********" << endl;

        return 1;
    }
    else {
        cout << "********************" << endl;
        cout << " The computer wins! " << endl;
        cout << "********************" << endl;

        return 0;
    }

    return 0;
}

int main() {

    play();

    return 0;
}