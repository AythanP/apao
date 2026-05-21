#ifndef _SHUNTING_YARD_H_
#define _SHUNTING_YARD_H_

#include "list_queue.h"
#include "linked_stack.h"

using namespace std;

class ShuntingYard {
    public:
        ShuntingYard();
        ~ShuntingYard();
        ListQueue<char> infix2PostFix(ListQueue<char> infix);
        void isValidInfix(ListQueue<char> infix);
        static bool isOperator(char token);
        static bool isOpenParen(char token);
        static bool isCloseParen(char token);
    private:
        int getPrecedence(char token);
};

#endif