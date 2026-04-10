#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Enter a file to read:" << endl;
    string file;
    cin >> file;

    // check if file was opened successfully
    ifstream input(file);
    string line;
    if(input.is_open()) {
        while(getline(input, line)) {
            cout << line << endl;
        }
    }
    input.close();

    // check if file was closed
    if (input.is_open()) {
        cout << "File did not close properly" << endl;
    }
    
    return 0;
}