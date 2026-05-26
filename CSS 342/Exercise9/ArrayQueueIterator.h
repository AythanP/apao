#ifndef _Array_Queue_Iterator_H_
#define _Array_Queue_Iterator_H_

#include <iterator>
#include "node.h"

using namespace std;

// a forward declaration of the class ListQueue to break the "chicken and egg" problem of circular dependencies between an ADT and its iterator
template <typename ItemType>
class ArrayQueue;

template <typename ItemType>
class ArrayQueueIterator : public iterator<input_iterator_tag, ItemType>{
    private :
        // ADT associated with iterator
        const ArrayQueue<ItemType>* containerPtr;
        // Current location in collection
        int currentItemIndex;
    public :
        ArrayQueueIterator(const ArrayQueue<ItemType>* someQueue, int index);
        const ItemType operator*();    
        ArrayQueueIterator<ItemType> operator ++();
        bool operator ==(const ArrayQueueIterator<ItemType>& rightHandSide) const ;
        bool operator !=(const ArrayQueueIterator<ItemType>& rightHandSide) const ;
}; // end LinkedStackIterator

#include "ArrayQueueIterator.cpp"

#endif
