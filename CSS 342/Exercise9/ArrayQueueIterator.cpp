#ifndef _Array_Queue_Iterator_CPP_
#define _Array_Queue_Iterator_CPP_

#include "ArrayQueueIterator.h"

template <typename ItemType>
ArrayQueueIterator<ItemType>::ArrayQueueIterator(const ArrayQueue<ItemType>* someQueue, int index): containerPtr(someQueue), currentItemIndex(index){
} // end constructor

template <typename ItemType>
const ItemType ArrayQueueIterator<ItemType>::operator *(){
    return containerPtr->getItemAt(currentItemIndex + 1);
} // end operator*

// this is specifically a prefix operator
template <typename ItemType>
ArrayQueueIterator<ItemType> ArrayQueueIterator<ItemType>::operator ++()
{
    if (currentItemIndex < containerPtr->size()) {
        currentItemIndex++;
    } else {
        currentItemIndex = containerPtr->size() + 1; // set to end
    }
    return *this ;
} // end prefix operator++

template <typename ItemType>
bool ArrayQueueIterator<ItemType>::operator ==(const ArrayQueueIterator<ItemType>& rightHandSide) const{
    return ((containerPtr == rightHandSide.containerPtr) && (currentItemIndex == rightHandSide.currentItemIndex));
} // end operator==

template <typename ItemType>
bool ArrayQueueIterator<ItemType>::operator !=(const ArrayQueueIterator<ItemType>& rightHandSide) const{
    return ((containerPtr != rightHandSide.containerPtr) || (currentItemIndex != rightHandSide.currentItemIndex));
} // end operator!=

#endif