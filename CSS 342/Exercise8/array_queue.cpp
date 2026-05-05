#ifndef _ARRAY_QUEUE_CPP_
#define _ARRAY_QUEUE_CPP_

#include "array_queue.h" // Header file

template <typename ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(MAX_QUEUE - 1){
} // end default constructor

template <typename ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return front == back;
} // end isEmpty

template <typename ItemType>
bool ArrayQueue<ItemType>::enqueue( const ItemType& newEntry){
    bool result = false;
    if ((back + 1) % (MAX_QUEUE + 1) != front){
        // Queue has room for another item
        back = (back + 1) % MAX_QUEUE;
        items[back] = newEntry;
        result = true ;
    } // end if
    return result;
} // end enqueue

template <typename ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    bool result = false ;
    if (!isEmpty()){
        front = (front + 1) % MAX_QUEUE;
        result = true ;
    } // end if
    return result;
} // end dequeue


template <typename ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    // Enforce precondition
    if (isEmpty()){
        throw "peekFront() called with empty queue";
    }    
    // Queue is not empty; return front
    return items[front];
} // end peekFront

#endif