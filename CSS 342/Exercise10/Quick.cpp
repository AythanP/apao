#include <vector>
#include <random>

using namespace std;

template <typename ItemType>
void quickSort(vector<ItemType>& vector, int beginning, int end);
template <typename ItemType>
int partition(vector<ItemType>& vector, int beginning, int end);

// Quick sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void quickSort(vector<ItemType>& vector, int beginning, int end) {
    if (beginning < end) {
        int pivotIndex = partition(vector, beginning, end);
        quickSort(vector, beginning, pivotIndex - 1);
        quickSort(vector, pivotIndex + 1, end);
    }
}

// returns the final sorted index of the pivot
template <typename ItemType>
int partition(vector<ItemType>& vector, int beginning, int end) {
    ItemType pivot = vector[end];
    int leftIndex = beginning - 1;

    // move all elements smaller than the pivot to the left half of the vector
    for (int i = beginning; i < end; i++) {
        if (vector[i] <= pivot) {
            leftIndex++;
            swap(vector[leftIndex], vector[i]);
        }
    }

    // put the pivot after the last small element
    swap(vector[leftIndex + 1], vector[end]);
    // return the pivot's index
    return leftIndex + 1;
}