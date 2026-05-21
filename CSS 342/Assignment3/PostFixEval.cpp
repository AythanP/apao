#include "PostFixEval.h"

PostFixEval::PostFixEval() {

}
PostFixEval::~PostFixEval() {

}

// function to evaluate a postfix expression
double PostFixEval::evaluatePostFix(ListQueue<char> postfix) {
    LinkedStack<double> output;

    while (!postfix.isEmpty()) {
        char token = postfix.peekFront();
        postfix.dequeue();
        if (isdigit(token)) {
            int num = token - '0';
            output.push(num);
        } else if (ShuntingYard::isOperator(token)) {
            double right;
            double left;
            try {
                right = output.peek();
                output.pop();
                left = output.peek();
                output.pop();
            } catch (const exception& e) {
                throw invalid_argument("Not a valid expression in postfix notation: not enough operands for an operator");
            }
            double result = 0.0;
            switch (token) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    if (right == 0) {
                        throw invalid_argument("Not a valid expression in postfix notation: division by zero");
                    }
                    result = left / right;
                    break;
                default:
                    break;
            }
            output.push(result);
        } else {
            throw invalid_argument("Not a valid expression in postfix notation: invalid character that's not a positive single digit number or accepted operator");
        }
    }

    if (output.isEmpty()) {
        throw invalid_argument("Not a valid expression in postfix notation: no operands or not enough operands");
    }

    double answer = output.peek();
    output.pop();

    if (!output.isEmpty()) {
        throw invalid_argument("Not a valid expression in postfix notation: too many operands");
    }

    return answer;
}