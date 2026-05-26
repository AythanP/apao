#ifndef _Linked_Queue_Iterator_H_
#define _Linked_Queue_Iterator_H_

#include <iterator>
#include "node.h"

using namespace std;

// a forward declaration of the class ListQueue to break the "chicken and egg" problem of circular dependencies between an ADT and its iterator
template <typename ItemType>
class ListQueue;

template <typename ItemType>
class LinkedQueueIterator : public iterator<input_iterator_tag, ItemType>{
    private :
        // ADT associated with iterator
        const ListQueue<ItemType>* containerPtr;
        // Current location in collection
        Node<ItemType>* currentItemPtr;
    public :
        LinkedQueueIterator(const ListQueue<ItemType>* someQueue, Node<ItemType>* nodePtr);
        const ItemType operator*();    
        LinkedQueueIterator<ItemType> operator ++();
        bool operator ==(const LinkedQueueIterator<ItemType>& rightHandSide) const ;
        bool operator !=(const LinkedQueueIterator<ItemType>& rightHandSide) const ;
}; // end LinkedStackIterator

#include "LinkedQueueIterator.cpp"

#endif
