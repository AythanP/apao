#ifndef _LIST_QUEUE_H_
#define _LIST_QUEUE_H_

#include "node.h"

template <typename ItemType>
class ListQueue{
    private:
        int itemCount;
        Node<ItemType>* getNodeAt(int position) const;
        Node<ItemType>* frontPtr;
        Node<ItemType>* backPtr;
    public:
        ListQueue();
        ListQueue(const ListQueue<ItemType>& aList);
        ~ListQueue();
    
        bool empty() const;
        int size() const;
        void enqueue(const ItemType& name);
        ItemType dequeue();
        bool remove(int position);
        void clear();
        ItemType front() const;
        void printQueue() const;
        ListQueue<ItemType>& operator=(const ListQueue<ItemType>& other);
};

#include "list_queue.cpp"

#endif