#ifndef _LIST_QUEUE_CPP_
#define _LIST_QUEUE_CPP_

#include "list_queue.h" // Header file

template <typename ItemType>
ListQueue<ItemType>::ListQueue(){
    listPtr = new LinkedList<ItemType>();
    frontPtr = listPtr->headPtr;
    backPtr = listPtr->getNodeAt(listPtr->itemCount);
} // end default constructor

// Note: This is a shallow copy
template <typename ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) : listPtr(aQueue.listPtr), frontPtr(aQueue.listPtr->headPtr), backPtr(aQueue.listPtr->getNodeAt(aQueue.listPtr->itemCount)) {
} // end copy constructor

template <typename ItemType>
ListQueue<ItemType>::~ListQueue(){
} // end destructor

template <typename ItemType>
bool ListQueue<ItemType>::isEmpty() const{
    return listPtr->isEmpty();
} // end isEmpty

/*
template <typename ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry){
    return listPtr->insert(listPtr->getLength() + 1, newEntry);
} // end enqueue
*/

/*
template <typename ItemType>
bool ListQueue<ItemType>::dequeue(){
    return listPtr->remove(1);
} // end dequeue
*/

template <typename ItemType>
ItemType ListQueue<ItemType>::peekFront() const{
    if (isEmpty()){
        throw "peekFront() called with empty queue";
    }
    // Queue is not empty; return front
    return listPtr->getEntry(1);
} // end peekFront


template <typename ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry){
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    // Insert the new node
    if (isEmpty()){
        frontPtr = newNodePtr; // The queue was empty
    }
    else{
        backPtr->setNext(newNodePtr); // The queue was not empty
    }
    backPtr = newNodePtr; // New node is at back
    return true;
} // end enqueue


template <typename ItemType>
bool ListQueue<ItemType>::dequeue(){
    bool result = false;
    if (!isEmpty()){
        // Queue is not empty; remove front
        Node<ItemType>* nodeToDeletePtr = frontPtr;

        if (frontPtr == backPtr){ // Special case: one node in queue
            frontPtr = nullptr ;
            backPtr = nullptr ;
        }
        else{
            frontPtr = frontPtr->getNext();
        }
        // Return deleted node to system
        nodeToDeletePtr->setNext( nullptr );
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        result = true;
    } // end if
    return result;
} // end dequeue
// end of implementation file

#endif