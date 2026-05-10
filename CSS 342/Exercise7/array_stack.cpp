#ifndef _ARRAY_STACK_CPP_
#define _ARRAY_STACK_CPP_

#include <cassert> // For assert
#include "array_stack.h" // Header file

template < class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1){
} // end default constructor

// Copy constructor and destructor are supplied by the compiler

template < class ItemType>
bool ArrayStack<ItemType>::isEmpty() const{
    return top < 0;
} // end isEmpty


template < class ItemType>
bool ArrayStack<ItemType>::push( const ItemType& newEntry){
    bool result = false ;
    // Does stack have room for newEntry?
    if (top < MAX_STACK - 1){
        top++;
        items[top] = newEntry;
        result = true;
    } // end if
    return result;
} // end push


template < class ItemType>
bool ArrayStack<ItemType>::pop(){
    bool result = false;
    if (!isEmpty()){
        top--;
        result = true;
    } // end if
    return result;
} // end pop


template < class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    assert (!isEmpty()); // Enforce precondition
    // Stack is not empty; return top
    return items[top];
} // end peek
// end of implementation file

// TODO: fix this. Maybe use an iterator? For arrays, it can be a for loop, for lists it can be a while loop. 
// push to a new stack and don't need to copy the original one?
template < class ItemType>
bool ArrayStack<ItemType>::paranthesisMatch() {
    ArrayStack<ItemType> comparison = ArrayStack<ItemType>();
    for (int i = 0; i < MAX_STACK; i++) {
        if (items[i] == '(' || items[i] == '[' || items[i] == '{') {
            comparison.push(items[i]);
        } else if (items[i] == ')' || items[i] == ']' || items[i] == '}') {
            if (comparison.isEmpty()) {
                return false;
            } else {
                if (items[i] == ')' && comparison.peek() == '(') {
                    comparison.pop();
                } else if (items[i] == ']' && comparison.peek() == '[') {
                    comparison.pop();
                } else if (items[i] == '}' && comparison.peek() == '{') {
                    comparison.pop();
                }
            }
        }
    }
    if (comparison.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

#endif