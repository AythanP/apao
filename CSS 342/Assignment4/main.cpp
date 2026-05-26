#include "HotPotatoGameListQueue.h"
#include <limits>

using namespace std;

bool playAgain(string input);
void getPlayers(ListQueue<string>& players);
void playHotPotato(ListQueue<string> players, int passes);
int getPasses();

int main(int argc, char *argv[]) {
    ListQueue<string> players;
    getPlayers(players);

    try {
        int passes = getPasses();
        // find the winner
        playHotPotato(players, passes);

        string again;
        do {
            do {
                cout << "Play again? Y/N" << endl;
                cin >> again;
                if (playAgain(again)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again." << endl;
                }
            } while (cin.fail() || playAgain(again));

            string samePlayers;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (again.compare("Y") == 0 || again.compare("y") == 0) {
                do {
                    cout << "Do you want to play with the same players? Y/N" << endl;
                    cin >> samePlayers;
                    if (playAgain(samePlayers)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please try again." << endl;
                    }
                } while (cin.fail() || playAgain(samePlayers));
                if (samePlayers.compare("Y") == 0 || samePlayers.compare("y") == 0) {
                    playHotPotato(players, passes);
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getPlayers(players);
                    playHotPotato(players, passes);
                }
            }
        } while (again.compare("N") != 0 && again.compare("n") != 0);
    }
    catch (const exception &e){
        cout << e.what() << endl;
    }
}

// helper function to determine if the player wants to play again
bool playAgain(string input) {
    return input != "Y" && input != "y" && input != "N" && input != "n";
}

// function that prompts the user for player names and populates a queue with the inputted names
void getPlayers(ListQueue<string>& players) {
    bool isSuccessful = false;
    do {
        try {
            if (!players.empty()) {
                players.clear();
            }
            string line;
            string delimitor = " ";
            cout << "Enter a list of names:" << endl;
            getline(cin, line);
            if (line.empty()) {
                throw std::invalid_argument("Error: No player names entered. Please try again.");
            }
            size_t delimitorPosition = line.find(delimitor);
            while (delimitorPosition != string::npos) {
                players.enqueue(line.substr(0, delimitorPosition));
                line.erase(0, delimitorPosition + delimitor.length());
                delimitorPosition = line.find(delimitor);
            }
            players.enqueue(line.substr(0, delimitorPosition));
            line.erase(0, delimitorPosition + delimitor.length());
            isSuccessful = true;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
    } while (!isSuccessful);
}

// function that prompts the user for a number of passes and returns an integer
int getPasses() {
    int passes;
    do {
        cout << "Enter the maximum number of passes per round: " << endl;
        cin >> passes;
        if (passes < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        }
    } while (cin.fail() || passes < 1);
    return passes;
}

// function that plays the hot potato game and prints out the results, given a queue of players and a number of passes
void playHotPotato(ListQueue<string> players, int passes) {
    HotPotatoGameListQueue game;
    string winner = game.playgame(players, passes);
    cout << "Winner: " << winner << endl;
    cout << "Current players queue: ";
    game.printCurrentPlayers();
    cout << "Eliminated players: ";
    game.printEliminatedPlayers();
}