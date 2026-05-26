#ifndef _ARRAY_QUEUE_CPP_
#define _ARRAY_QUEUE_CPP_

#include <stdexcept>
#include <iostream>
#include "array_queue.h" // Header file

template <typename ItemType>
ArrayQueue<ItemType>::ArrayQueue() : frontIndex(0), backIndex(0), capacity(MAX_QUEUE + 1) {
    items = new ItemType[capacity];
} // end default constructor
template <typename ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue<ItemType>& other) : frontIndex(other.frontIndex), backIndex(other.backIndex), capacity(other.capacity) {
    items = new ItemType[capacity];
    for (int i = 0; i < capacity; i++) {
        items[i] = other.items[i];
    }
} // end copy constructor
template <typename ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {
    delete[] items;
}

template <typename ItemType>
bool ArrayQueue<ItemType>::empty() const{
    return frontIndex == backIndex;
} // end isEmpty

template <typename ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    // if the queue is full, double it and copy the content over
    if ((backIndex + 1) % capacity == frontIndex){
        int newCapacity = capacity * 2;
        ItemType* newItems = new ItemType[newCapacity];
        int currentSize = size();
        for (int i = 0; i < currentSize; i++) {
            newItems[i + 1] = items[(frontIndex + 1 + i) % capacity];
        }
        frontIndex = 0;
        backIndex = currentSize;
        capacity = newCapacity;
        delete[] items;
        items = newItems;
    }
    
    backIndex = (backIndex + 1) % capacity;
    items[backIndex] = newEntry;
} // end enqueue

template <typename ItemType>
ItemType ArrayQueue<ItemType>::dequeue(){
    if (!empty()){
        frontIndex = (frontIndex + 1) % capacity;
        return items[frontIndex];
    } else {
        throw std::out_of_range("Error: Trying to dequeue an empty list");
    }// end if
} // end dequeue

template <typename ItemType>
bool ArrayQueue<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= size());

    if (ableToRemove) {
        int removeIndex = (frontIndex + position) % capacity;

        // Shift elements left toward the removed position
        int current = removeIndex;

        while (current != backIndex) {
            int next = (current + 1) % capacity;
            items[current] = items[next];
            current = next;
        }

        // Move backIndex backward one position
        backIndex = (backIndex - 1 + capacity) % capacity;
    }

    return ableToRemove;
}

template <typename ItemType>
ItemType ArrayQueue<ItemType>::front() const {
    // Enforce precondition
    if (empty()){
        throw std::out_of_range("front() called with empty queue");
    }    
    // Queue is not empty; return front
    return items[(frontIndex + 1) % capacity];
} // end front

template <typename ItemType>
int ArrayQueue<ItemType>::size() const {
    return (backIndex - frontIndex + capacity) % capacity;
}

template <typename ItemType>
int ArrayQueue<ItemType>::getCapacity() const {
    return capacity;
}
template <typename ItemType>
int ArrayQueue<ItemType>::getFrontIndex() const {
    return frontIndex;
}
template <typename ItemType>
int ArrayQueue<ItemType>::getBackIndex() const {
    return backIndex;
}
template <typename ItemType>
ItemType ArrayQueue<ItemType>::getItemAt(int position) const {
    if (position < 1 || position > size()) {
        throw std::out_of_range("Error: Position out of range");
    }
    int index = (frontIndex + position) % capacity;
    return items[index];
}

template <typename ItemType>
void ArrayQueue<ItemType>::clear() {
    while (!empty()) {
        dequeue();
    }
}

template <typename ItemType>
ArrayQueue<ItemType>& ArrayQueue<ItemType>::operator=(const ArrayQueue<ItemType>& other) {
    if (this != &other) {
        delete[] items;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;
        capacity = other.capacity;
        items = new ItemType[capacity];
        for (int i = 0; i < capacity; i++) {
            items[i] = other.items[i];
        }
    }
    return *this;
}

template <typename ItemType>
void ArrayQueue<ItemType>::printQueue() const {
    int current = (frontIndex + 1) % capacity;
    while (current != (backIndex + 1) % capacity) {
        std::cout << items[current] << " ";
        current = (current + 1) % capacity;
    }
    std::cout << std::endl;
}

#endif