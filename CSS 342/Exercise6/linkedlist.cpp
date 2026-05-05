#ifndef _LINKED_LIST_CPP_
#define _LINKED_LIST_CPP_

#include "linkedlist.h"
#include <cstddef>
#include <iostream>
// #include <cstdlib>
#include <cassert>

template <typename ItemType>
LinkedList<ItemType>::LinkedList() : headPtr( nullptr), itemCount(0){
} // end default constructor

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    itemCount = aList.itemCount;
    for (int i = 1; i <= itemCount; i++) {
        this.insert(i, aList.getEntry(i));
    }
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));
    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr ;
} // end getNodeAt


template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet){
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else{        
        throw "getEntry() called with an empty list or invalid position.";
    } // end if
} // end getEntry




template <typename ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert){
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        // Attach new node to chain
        if (newPosition == 1){
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr); 
            headPtr = newNodePtr;
        }
        else{
            // Find node that will be before new node
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        } // end if
        
        itemCount++; // Increase count of entries
    } // end if
    
    return ableToInsert;
} // end insert


template <typename ItemType>
bool LinkedList<ItemType>::remove(int position){
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove){
        Node<ItemType>* curPtr = nullptr;

        if (position == 1){
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else{
            // Find node that is before the one to delete
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            // Point to node to delete
            curPtr = prevPtr->getNext();
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        } // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr ;
        itemCount--; // Decrease count of entries
    } // end if
    
    return ableToRemove;
} // end remove


template <typename ItemType>
void LinkedList<ItemType>::clear(){
    while (!isEmpty()){
        remove(1);
    }
} // end clear


template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    return (itemCount == 0);
    // return (headPtr == nullptr);
} // end isEmpty


template <typename ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
} // end getLength

template <typename ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet){
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else{        
        throw "setEntry() called with an empty list or invalid position.";
    }
}

template <typename ItemType>
void LinkedList<ItemType>::printList() const {
    Node<ItemType>* current = headPtr;
    while (current != nullptr) {
        std::cout <<  current->getItem() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

template <typename ItemType>
void LinkedList<ItemType>::printListRecursive() const {
    printListRecursiveHelper(headPtr);
}

template <typename ItemType>
void LinkedList<ItemType>::printListRecursiveHelper(const Node<ItemType>* headPtr) const {
    if (!isEmpty()) {
        std::cout << headPtr->getItem() << std::endl;
        if (headPtr->getNext() != nullptr) {
            printListRecursiveHelper(headPtr->getNext());
        }
    }
    return;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::findValueRecursive(const ItemType& value) const {
    return findValueRecursiveHelper(headPtr, value, 0);
}

template <typename ItemType>
ItemType LinkedList<ItemType>::findValueRecursiveHelper(const Node<ItemType>* currPtr, const ItemType& value, int position) const {
    if (currPtr == nullptr) {
        return -1;
    } else if (currPtr->getItem() == value) {
        return position;
    }
    return findValueRecursiveHelper(currPtr->getNext(), value, ++position);
}

template <typename ItemType>
void LinkedList<ItemType>::printListReverseRecursive() const {
    printListReverseRecursiveHelper(headPtr);
}

template <typename ItemType>
void LinkedList<ItemType>::printListReverseRecursiveHelper(const Node<ItemType>* headPtr) const {
    if (headPtr == nullptr) {
        return;
    }
    if (headPtr->getNext() == nullptr) {
        std::cout << headPtr->getItem() << std::endl;
        return;
    } 
    printListReverseRecursiveHelper(headPtr->getNext());
    std::cout << headPtr->getItem() << std::endl;
    return;
}

template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::reverseInPlace(Node<ItemType>* curPtr) {
    Node<ItemType> newHead;
    if (currPtr == nullptr || curPtr->getNext() == nullptr) {
        return curPtr;
    }
    // new head points to the tail
    newHead = reverseInPlace(curPtr->getNext());

    // set the node you point to to point to yourself
    curPtr->getNext()->setNext(curPtr);
    // set yourself to point to null to act as the new tail
    curPtr->setNext(nullptr);

    return newHead;
}

#endif