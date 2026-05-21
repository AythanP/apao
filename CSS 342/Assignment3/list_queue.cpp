#ifndef _LIST_QUEUE_CPP_
#define _LIST_QUEUE_CPP_

#include "list_queue.h" // Header file

template <typename ItemType>
ListQueue<ItemType>::ListQueue(){
    listPtr = new LinkedList<ItemType>();
} // end default constructor

template <typename ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) {
    listPtr = new LinkedList<ItemType>();
    for (int i = 1; i <= aQueue.listPtr->getLength(); i++) {
        this->enqueue(aQueue.listPtr->getEntry(i));
    }
} // end copy constructor

template <typename ItemType>
ListQueue<ItemType>::~ListQueue(){
    clear();
    delete listPtr;
    listPtr = nullptr;
} // end destructor

template <typename ItemType>
bool ListQueue<ItemType>::isEmpty() const{
    return listPtr->isEmpty();
} // end isEmpty

template <typename ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry){
    return listPtr->insert(listPtr->getLength() + 1, newEntry);
} // end enqueue

template <typename ItemType>
bool ListQueue<ItemType>::dequeue(){
    return listPtr->remove(1);
} // end dequeue

template <typename ItemType>
ItemType ListQueue<ItemType>::peekFront() const{
    if (isEmpty()){
        throw "peekFront() called with empty queue";
    }
    // Queue is not empty; return front
    return listPtr->getEntry(1);
} // end peekFront

template <typename ItemType>
void ListQueue<ItemType>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename ItemType>
ListQueue<ItemType>& ListQueue<ItemType>::operator=(const ListQueue<ItemType>& other) {
    if (this != &other) {
        clear();
        for (int i = 1; i <= other.listPtr->getLength(); i++) {
            this->enqueue(other.listPtr->getEntry(i));
        }
    }
    return *this;
}

#endif
// end of implementation file