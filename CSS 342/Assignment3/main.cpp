#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include "ShuntingYard.h"
#include "list_queue.h"
#include "PostFixEval.h"

using namespace std;

int main(int argc, char *argv[]) {
    ShuntingYard expression;
    PostFixEval evaluation;
    ListQueue<char> input;
    ListQueue<char> postFix;
    bool isSuccessful = false;

    do {
        // get user input
        string line;
        cout << "Enter a mathematical expression, using only single positive digits and the +, -, *, and / operators:" << endl;
        getline(cin, line);

        // convert input string to char array
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        char charArray[line.length() + 1];
        charArray[line.length()] = '\0';
        for (int i = 0; i < line.length(); i++) {
            charArray[i] = line[i];
        }

        // populate queue
        for (int i = 0; i < line.length(); i++) {
            input.enqueue(charArray[i]);
        }

        // validate infix to postfix conversion and postfix evaluation
        try {
            postFix = expression.infix2PostFix(input);
            double answer = evaluation.evaluatePostFix(postFix);
            isSuccessful = true;
            cout << "Postfix evaluation of infix expression: " << answer << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;   
            input.clear();
        }
    } while (!isSuccessful);
}