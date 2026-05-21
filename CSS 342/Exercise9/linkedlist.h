#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "node.h"
#include "linked_iterator.h"

template <typename ItemType>
class LinkedList{

    private:
        Node<ItemType>* headPtr;
        int itemCount;
        Node<ItemType>* getNodeAt(int position) const;

    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& aList);
        ~LinkedList();
    
        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const;
        void setEntry(int position, const ItemType& newEntry);
        void printList() const;
        ItemType& operator=(const LinkedList<ItemType>& other);
        // Iterator operations
        LinkedIterator<ItemType> begin();
        LinkedIterator<ItemType> end();
};

#include "linkedlist.cpp"

#endif