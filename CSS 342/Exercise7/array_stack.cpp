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

// TODO: fix this
template < class ItemType>
bool ArrayStack<ItemType>::paranthesisMatch() {
    ArrayStack<ItemType> oldTemp(this);
    ArrayStack<ItemType> newTemp(MAX_STACK);
    while (!oldTemp.isEmpty()) {
        ItemType element = oldTemp.peek();
        if (element == '(' || element == '[' || element == '{') {
            newTemp.push(element);
        } else if (element == ')' || element == ']' || element == '}') {
            if (newTemp.isEmpty()) {
                return false;
            } else {
                newTemp.pop();
            }
        }
        oldTemp.pop();
    }
    if (newTemp.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

#endif