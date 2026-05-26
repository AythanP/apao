#ifndef _Linked_Queue_Iterator_CPP_
#define _Linked_Queue_Iterator_CPP_

#include "LinkedQueueIterator.h"

template <typename ItemType>
LinkedQueueIterator<ItemType>::LinkedQueueIterator(const ListQueue<ItemType>* someQueue, Node<ItemType>* nodePtr): containerPtr(someQueue), currentItemPtr(nodePtr){
} // end constructor

template <typename ItemType>
const ItemType LinkedQueueIterator<ItemType>::operator *(){
    return currentItemPtr->getItem();
} // end operator*

// this is specifically a prefix operator
template <typename ItemType>
LinkedQueueIterator<ItemType> LinkedQueueIterator<ItemType>::operator ++()
{
    currentItemPtr = currentItemPtr->getNext();
    return *this ;
} // end prefix operator++

template <typename ItemType>
bool LinkedQueueIterator<ItemType>::operator ==(const LinkedQueueIterator<ItemType>& rightHandSide) const{
    return ((containerPtr == rightHandSide.containerPtr) && (currentItemPtr == rightHandSide.currentItemPtr));
} // end operator==

template <typename ItemType>
bool LinkedQueueIterator<ItemType>::operator !=(const LinkedQueueIterator<ItemType>& rightHandSide) const{
    return ((containerPtr != rightHandSide.containerPtr) || (currentItemPtr != rightHandSide.currentItemPtr));
} // end operator!=

#endif