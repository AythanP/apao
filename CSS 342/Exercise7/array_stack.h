#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

const int MAX_STACK = 1000;

template < class ItemType>
class ArrayStack{
    private:
        ItemType items[MAX_STACK]; // Array of stack items
        int top; // Index to top of stack

    public:
        ArrayStack(); // Default constructor
        bool isEmpty() const ;
        bool push(const ItemType& newEntry);
        bool pop();
        ItemType peek() const ;
        bool paranthesesMatch();
}; // end ArrayStack

#include "array_stack.cpp"

#endif