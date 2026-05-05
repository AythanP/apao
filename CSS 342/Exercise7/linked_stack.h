#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "node.h"

template < class ItemType>
class LinkedStack{
    private:
        Node<ItemType>* topPtr; // Pointer to first node in the chain;
        //  this node contains the stack’s top

    public:
        // Constructors and destructor:
        LinkedStack(); // Default constructor
        LinkedStack( const LinkedStack<ItemType>& aStack); // Copy constructor
        ~LinkedStack(); // Destructor
        // Stack operations:
        bool isEmpty() const;
        bool push( const ItemType& newItem);
        bool pop();
        ItemType peek() const;
}; // end LinkedStack

#include "linked_stack.cpp"

#endif
