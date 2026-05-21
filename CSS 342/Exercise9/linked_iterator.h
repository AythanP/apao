#ifndef _LINKED_ITERATOR_H_
#define _LINKED_ITERATOR_H_

#include <iterator>
#include "node.h"

using namespace std;

// a forward declaration of the class LinkedList to break the "chicken and egg" problem of circular dependencies between an ADT and its iterator
template <typename ItemType>
class LinkedList;

template <typename ItemType>
class LinkedIterator : public iterator<input_iterator_tag, ItemType>{
    private :
        // ADT associated with iterator
        const LinkedList<ItemType>* containerPtr;
        // Current location in collection
        Node<ItemType>* currentItemPtr;
    public :
        LinkedIterator(const LinkedList<ItemType>* someList, Node<ItemType>* nodePtr);
        const ItemType operator*();    
        LinkedIterator<ItemType> operator ++();
        bool operator ==(const LinkedIterator<ItemType>& rightHandSide) const ;
        bool operator !=(const LinkedIterator<ItemType>& rightHandSide) const ;
}; // end LinkedIterator

#include "linked_iterator.cpp"

#endif
