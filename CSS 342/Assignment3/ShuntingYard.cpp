#include <cctype>
#include <stdexcept>
#include "ShuntingYard.h"

using namespace std;

ShuntingYard::ShuntingYard() {

}

ShuntingYard::~ShuntingYard() {

}

// function to convert infix to postfix using the shunting yard algorithm
// Assume that infix expressions consist of only single digitis and the +, -, *, and / operators
// infix is intended to be a queue of chars, taking a string as input in main
ListQueue<char> ShuntingYard::infix2PostFix(ListQueue<char> infix) {
    LinkedStack<char> operators;
    ListQueue<char> output;
    char prevToken = '\0';

    while (!infix.isEmpty()) {
        char token = infix.peekFront();
        infix.dequeue(); 

        // if token is a number
        if (isdigit(token)) {
            // check for multidigit numbers
            if (prevToken != '\0' && isdigit(prevToken)) {
                throw invalid_argument("Invalid character in expression: detected multiple digits in a row, only single digits are accepted");
            }
            output.enqueue(token);
        // if token is an operator
        } else if (isOperator(token)) {
            // check for consecutive operators, an operator at the start of an expression, or an operator after an open parentheses
            if (prevToken == '\0' || isOperator(prevToken) || isOpenParen(prevToken)) {
                throw invalid_argument("Invalid character in expression: detected an operator at start of the expression, consecutive operators, or an operator after an open parentheses");
            }
            while (!operators.isEmpty() && isOperator(operators.peek()) && getPrecedence(operators.peek()) >= getPrecedence(token)) {
                output.enqueue(operators.peek());
                operators.pop();
            }
            operators.push(token);
        // if token is an open parentheses
        } else if (isOpenParen(token)) {
            // check for parantheses multiplication
            if (prevToken != '\0' && isCloseParen(prevToken)) {
                operators.push('*');
            }
            operators.push(token);
        // if token is a closed parentheses
        } else if (isCloseParen(token)) {
            // check for an operator before closed parentheses
            if (prevToken != '\0' && isOperator(prevToken)) {
                throw invalid_argument("Invalid character in expression: detected an operator before a closed parentheses");
            // check for empty parenthesis statements
            } else if (prevToken != '\0' && isOpenParen(prevToken)) {
                throw invalid_argument("Invalid character in expression: detected an open and closed parantheses with nothing inside");
            }
            while (!operators.isEmpty() && !isOpenParen(operators.peek())) {
                output.enqueue(operators.peek());
                operators.pop();
            }
            if (!operators.isEmpty() && ((operators.peek() == '(' && token == ')') || (operators.peek() == '[' && token == ']') || (operators.peek() == '{' && token == '}'))) {
                operators.pop();
            } else {
                throw invalid_argument("Mismatched parentheses in expression");
            } 
        } else {
            throw invalid_argument("Invalid character in expression: detected a character that is not a single digit, accepted operator, or parentheses");
        }

        prevToken = token;
    }

    while (!operators.isEmpty()) {
        char symbol = operators.peek();
        operators.pop();
        if (isOperator(symbol)) {
            output.enqueue(symbol);
        } else if (isOpenParen(symbol) || isCloseParen(symbol)) {
            throw invalid_argument("Mismatched parentheses in expression");
        }
    }

    return output;
}

// function to determine operator precedence from a character
int ShuntingYard::getPrecedence(char token) {
    switch(token) {
        case '-':
        case '+':
            return 1;
        case '/':
        case '*':
            return 2;
        default:
            return 0;
    }
}

// function to determine if a character is an accepted operator symbol
bool ShuntingYard::isOperator(char token) {
    return (token == '*' || token == '/' || token == '+' || token == '-') ? true : false;
}

// function to determine if a character is an accepted open parentheses symbol
bool ShuntingYard::isOpenParen(char token) {
    return (token == '(' || token == '[' || token == '{') ? true : false;
}

// function to determine if a character is an accepted closed parantheses symbol
bool ShuntingYard::isCloseParen(char token) {
    return (token == ')' || token == ']' || token == '}') ? true : false;
}