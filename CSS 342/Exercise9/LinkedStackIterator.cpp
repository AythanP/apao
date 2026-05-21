#ifndef _Linked_Stack_Iterator_CPP_
#define _Linked_Stack_Iterator_CPP_

#include "LinkedStackIterator.h"

template <typename ItemType>
LinkedStackIterator<ItemType>::LinkedStackIterator(const LinkedStack<ItemType>* someStack, Node<ItemType>* nodePtr): containerPtr(someStack), currentItemPtr(nodePtr){
} // end constructor

template <typename ItemType>
const ItemType LinkedStackIterator<ItemType>::operator *(){
    return currentItemPtr->getItem();
} // end operator*

// this is specifically a prefix operator
template <typename ItemType>
LinkedStackIterator<ItemType> LinkedStackIterator<ItemType>::operator ++()
{
    currentItemPtr = currentItemPtr->getNext();
    return *this ;
} // end prefix operator++

template <typename ItemType>
bool LinkedStackIterator<ItemType>::operator ==(const LinkedStackIterator<ItemType>& rightHandSide) const{
    return ((containerPtr == rightHandSide.containerPtr) && (currentItemPtr == rightHandSide.currentItemPtr));
} // end operator==

template <typename ItemType>
bool LinkedStackIterator<ItemType>::operator !=(const LinkedStackIterator<ItemType>& rightHandSide) const{
    return ((containerPtr != rightHandSide.containerPtr) || (currentItemPtr != rightHandSide.currentItemPtr));
} // end operator!=

#endif