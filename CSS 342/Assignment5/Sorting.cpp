#ifndef Sorting_CPP
#define Sorting_CPP

#include <random>
#include "Sorting.h"

template <typename ItemType>
Sorting<ItemType>::Sorting() {

}
template <typename ItemType>
Sorting<ItemType>::~Sorting() {

}

// Bubble sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void Sorting<ItemType>::bubbleSort(vector<ItemType>& data, int beginning, int end) {
   for (int i = beginning; i < end; i++) {
    for (int j = end; j > i; j--) {
        if (data[j] < data[j - 1]) {
            swap(data[j], data[j - 1]);
        }
    }
   }
};

// Insertion sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void Sorting<ItemType>::insertionSort(vector<ItemType>& data, int beginning, int end) {
    for (int j = beginning + 1; j <= end; j++) {
        ItemType key = data[j];
        int i = j;
        while (i > 0 && data[i - 1] > key) {
            data[i] = data[i - 1];
            i -= 1; 
        }
        data[i] = key;
    }
}

// Merge sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void Sorting<ItemType>::mergeSort(vector<ItemType>& data, int beginning, int end) {
    if (beginning < end) {
        int middle = beginning + (end - beginning) / 2;
        mergeSort(data, beginning, middle);
        mergeSort(data, middle + 1, end);
        merge(data, beginning, middle, end);
    }
};

template <typename ItemType>
void Sorting<ItemType>::merge(vector<ItemType>& data, int beginning, int middle, int end) {
    int leftVectorLength = middle - beginning + 1;
    int rightVectorLength = end - middle;
    // temporary vectors
    std::vector<ItemType> left(leftVectorLength), right(rightVectorLength);
    for (int i = 0; i < leftVectorLength; i++) {
        left[i] = data[beginning + i];
    }
    for (int i = 0; i < rightVectorLength; i++) {
        right[i] = data[middle + 1 + i];
    }

    int i = 0, j = 0;
    int index = beginning;

    // Merge the temp vectors back into the original vector, from beginning to end, making sure the values are sorted
    while (i < leftVectorLength && j < rightVectorLength) {
        if (left[i] <= right[j]) {
            data[index] = left[i];
            i++;
        } else {
            data[index] = right[j];
            j++;
        }
        index++;
    }

    // Copy the remaining elements of the left temporary vector, if there are any, into the original vector
    while (i < leftVectorLength) {
        data[index] = left[i];
        i++;
        index++;
    }

    // Copy the remaining elements of the right temporary vector, if there are any, into the original vector
    while (j < rightVectorLength) {
        data[index] = right[j];
        j++;
        index++;
    }
};

// Quick sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void Sorting<ItemType>::quickSort(vector<ItemType>& data, int beginning, int end) {
    // While loop needed to continue sorting the larger partition iteratively, instead of recursively, 
    // to avoid stack overflow errors with large vectors
    while (beginning < end)
    {
        int pivotIndex = partition(data, beginning, end);

        // Left partition is smaller, recursively sort it first
        if (pivotIndex - beginning < end - pivotIndex)
        {
            quickSort(data, beginning, pivotIndex - 1);

            // Continue iteratively on the larger partition
            beginning = pivotIndex + 1;
        }
        // Right partition is smaller, recursively sort it first
        else
        {
            quickSort(data, pivotIndex + 1, end);

            // Continue iteratively on the larger partition
            end = pivotIndex - 1;
        }
    }
}

// returns the final sorted index of the pivot
template <typename ItemType>
int Sorting<ItemType>::partition(vector<ItemType>& data, int beginning, int end) {
    // generate a random pivot index
    static random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(beginning, end);
    int pivotIndex = distribution(generator);

    // move the pivot to the end of the vector to maintain the Lomuto partition scheme
    swap(data[pivotIndex], data[end]);
    
    ItemType pivot = data[end];
    int leftIndex = beginning - 1;

    // move all elements smaller than the pivot to the left half of the vector
    for (int i = beginning; i < end; i++) {
        if (data[i] < pivot) {
            leftIndex++;
            swap(data[leftIndex], data[i]);
        }
    }

    // put the pivot after the last small element
    swap(data[leftIndex + 1], data[end]);
    // return the pivot's index
    return leftIndex + 1;
}

#endif