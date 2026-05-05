#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

const int MAX_QUEUE = 50;

template <typename ItemType>
class ArrayQueue{
    private:
        ItemType items[MAX_QUEUE + 1]; // Array of queue items
        int front; // Index to front of queue
        int back; // Index to back of queue
    public:
        ArrayQueue();
        bool isEmpty() const ;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        ItemType peekFront() const;
}; // end ArrayQueue

#include "array_queue.cpp"

#endif