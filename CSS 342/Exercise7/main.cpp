#include "array_stack.h"
#include <string>
#include <iostream>

using namespace std;

bool paranthesisMatch();

int main() {
    ArrayStack<char> test1 = ArrayStack<char>();
    string line;
    cout << "Enter a mathematical expression:" << endl;
    cin >> line;
    
    for (int i = 0; i < line.length(); i++) {
        test1.push(line[i]);
    }
    /*
    while (!test1.isEmpty()) {
        char element = test1.peek();
        cout << element << " ";
        test1.pop();
    }
    */
   bool balancedMath = test1.paranthesesMatch();
   cout << "Expression is balanced: " << balancedMath << endl;
}