#ifndef Sorting_H
#define Sorting_H

#include <vector>

using namespace std;

template <typename ItemType>
class Sorting {
    private:
        Sorting();
        ~Sorting();
        static void merge(vector<ItemType>& data, int beginning, int middle, int end);
        static int partition(vector<ItemType>& data, int beginning, int end);
    public:
        static void bubbleSort(vector<ItemType>& data, int beginning, int end);
        static void insertionSort(vector<ItemType>& data, int beginning, int end);
        static void mergeSort(vector<ItemType>& data, int beginning, int end);
        static void quickSort(vector<ItemType>& data, int beginning, int end);
};

#include "Sorting.cpp"

#endif