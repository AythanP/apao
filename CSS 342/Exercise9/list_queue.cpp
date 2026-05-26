#ifndef _LIST_QUEUE_CPP_
#define _LIST_QUEUE_CPP_

#include "list_queue.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
// #include <cstdlib>
#include <cassert>

template <typename ItemType>
ListQueue<ItemType>::ListQueue() : itemCount(0), frontPtr(nullptr), backPtr(nullptr){
} // end default constructor

template <typename ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue<ItemType>& aList) : itemCount(0), frontPtr(nullptr), backPtr(nullptr) {
    Node<ItemType>* current = aList.frontPtr;
    while (current != nullptr) {
        enqueue(current->getItem());
        current = current->getNext();
    }
} // end copy constructor

template <typename ItemType>
ListQueue<ItemType>::~ListQueue() {
    clear();
}

template <typename ItemType>
Node<ItemType>* ListQueue<ItemType>::getNodeAt(int position) const{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));
    // Count from the beginning of the chain
    Node<ItemType>* curPtr = frontPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr ;
} // end getNodeAt


template <typename ItemType>
void ListQueue<ItemType>::enqueue(const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    // Insert the new node
    if (empty()) {
        frontPtr = newNodePtr;
    } else {
        backPtr->setNext(newNodePtr);
    }
    backPtr = newNodePtr;
    itemCount++;
}

template <typename ItemType>
ItemType ListQueue<ItemType>::dequeue() {
    if (!empty()) {
        Node<ItemType>* nodeToDeletePtr = frontPtr;

        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr= nullptr;
        } else {
            frontPtr = frontPtr->getNext();
        }

        nodeToDeletePtr->setNext(nullptr);
        ItemType item = nodeToDeletePtr->getItem();
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
        return item;
    } else {
        throw std::out_of_range("Error: Trying to dequeue an empty list");
    }
}

template <typename ItemType>
bool ListQueue<ItemType>::remove(int position){
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove){
        Node<ItemType>* curPtr = nullptr;

        if (position == 1){
            // Remove the first node in the chain
            curPtr = frontPtr; // Save pointer to node
            frontPtr = frontPtr->getNext();
            if (curPtr == backPtr) {
                backPtr = nullptr;
            }
        }
        else{
            // Find node that is before the one to delete
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            // Point to node to delete
            curPtr = prevPtr->getNext();
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
            if (curPtr == backPtr) {
                backPtr = prevPtr;
            }
        }

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        itemCount--; // Decrease count of entries
    } // end if
    
    return ableToRemove;
} // end remove

template <typename ItemType>
void ListQueue<ItemType>::clear(){
    while (!empty()){
        dequeue();
    }
} // end clear


template <typename ItemType>
bool ListQueue<ItemType>::empty() const{
    return (itemCount == 0);
} // end empty


template <typename ItemType>
int ListQueue<ItemType>::size() const{
    return itemCount;
} // end size

template <typename ItemType>
ItemType ListQueue<ItemType>::front() const {
    if (empty()) {
        throw std::out_of_range("Error: Trying to access front of an empty list");
    }
    return frontPtr->getItem();
}

template <typename ItemType>
void ListQueue<ItemType>::printQueue() const {
    Node<ItemType>* current = frontPtr;
    while (current != nullptr) {
        std::cout << current->getItem() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

template <typename ItemType>
ListQueue<ItemType>& ListQueue<ItemType>::operator=(const ListQueue<ItemType>& other) {
    if (this != &other) {
        clear();
        Node<ItemType>* current = other.frontPtr;
        while (current != nullptr) {
            enqueue(current->getItem());
            current = current->getNext();
        }
    }
    return *this;
}

template <typename ItemType>
LinkedQueueIterator<ItemType> ListQueue<ItemType>::begin() {
    return LinkedQueueIterator<ItemType>(this, frontPtr);
}

template <typename ItemType>
LinkedQueueIterator<ItemType> ListQueue<ItemType>::end() {
    return LinkedQueueIterator<ItemType>(this, nullptr);
}

#endif