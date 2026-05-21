#ifndef _Linked_Stack_Iterator_H_
#define _Linked_Stack_Iterator_H_

#include <iterator>
#include "node.h"

using namespace std;

// a forward declaration of the class LinkedStack to break the "chicken and egg" problem of circular dependencies between an ADT and its iterator
template <typename ItemType>
class LinkedStack;

template <typename ItemType>
class LinkedStackIterator : public iterator<input_iterator_tag, ItemType>{
    private :
        // ADT associated with iterator
        const LinkedStack<ItemType>* containerPtr;
        // Current location in collection
        Node<ItemType>* currentItemPtr;
    public :
        LinkedStackIterator(const LinkedStack<ItemType>* someStack, Node<ItemType>* nodePtr);
        const ItemType operator*();    
        LinkedStackIterator<ItemType> operator ++();
        bool operator ==(const LinkedStackIterator<ItemType>& rightHandSide) const ;
        bool operator !=(const LinkedStackIterator<ItemType>& rightHandSide) const ;
}; // end LinkedStackIterator

#include "LinkedStackIterator.cpp"

#endif
