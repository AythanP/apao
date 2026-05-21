#ifndef _LIST_QUEUE_H_
#define _LIST_QUEUE_H_

#include "linkedlist.h"

template <typename ItemType>
class ListQueue{
    private :
        LinkedList<ItemType>* listPtr; // Pointer to list of queue items
    public :
        ListQueue();
        ListQueue(const ListQueue& aQueue);
        ~ListQueue();
        bool isEmpty() const ;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        ItemType peekFront() const;
        void clear();
        ListQueue<ItemType>& operator=(const ListQueue<ItemType>& other);
}; // end ListQueue

#include "list_queue.cpp"

#endif