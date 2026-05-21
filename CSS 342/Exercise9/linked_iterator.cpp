#ifndef _LINKED_ITERATOR_CPP_
#define _LINKED_ITERATOR_CPP_

#include "linked_iterator.h"

template <typename ItemType>
LinkedIterator<ItemType>::LinkedIterator(const LinkedList<ItemType>* someList, Node<ItemType>* nodePtr): containerPtr(someList), currentItemPtr(nodePtr){
} // end constructor

template <typename ItemType>
const ItemType LinkedIterator<ItemType>::operator *(){
    return currentItemPtr->getItem();
} // end operator*

// this is specifically a prefix operator
template <typename ItemType>
LinkedIterator<ItemType> LinkedIterator<ItemType>::operator ++()
{
    currentItemPtr = currentItemPtr->getNext();
    return *this ;
} // end prefix operator++

template <typename ItemType>
bool LinkedIterator<ItemType>::operator ==(const LinkedIterator<ItemType>& rightHandSide) const{
    return ((containerPtr == rightHandSide.containerPtr) && (currentItemPtr == rightHandSide.currentItemPtr));
} // end operator==

template <typename ItemType>
bool LinkedIterator<ItemType>::operator !=(const LinkedIterator<ItemType>& rightHandSide) const{
    return ((containerPtr != rightHandSide.containerPtr) || (currentItemPtr != rightHandSide.currentItemPtr));
} // end operator!=

#endif