#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

const int MAX_QUEUE = 50;

template <typename ItemType>
class ArrayQueue{
    private:
        ItemType* items; // Array of queue items
        int frontIndex; // Index to front of queue
        int backIndex; // Index to back of queue
        int capacity; // Capacity of the queue
    public:
        ArrayQueue();
        ArrayQueue(const ArrayQueue<ItemType>& other);
        ~ArrayQueue();
        bool empty() const ;
        void enqueue(const ItemType& newEntry);
        ItemType dequeue();
        bool remove(int position);
        ItemType front() const;
        int size() const;
        int getCapacity() const;
        int getFrontIndex() const;
        int getBackIndex() const;
        ItemType getItemAt(int position) const;
        void clear();
        ArrayQueue<ItemType>& operator=(const ArrayQueue<ItemType>& other);
        void printQueue() const;
}; // end ArrayQueue

#include "array_queue.cpp"

#endif