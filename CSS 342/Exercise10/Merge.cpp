#include <vector>

using namespace std;

template <typename ItemType>
void mergeSort(vector<ItemType>& vector, int beginning, int end);
template <typename ItemType>
void merge(vector<ItemType>& vector, int beginning, int middle, int end);

// Merge sort a vector from a beginning to and ending index
// To sort an entire vector, go from 0 to vector.size() - 1
template <typename ItemType>
void mergeSort(vector<ItemType>& vector, int beginning, int end) {
    if (beginning < end) {
        int middle = (beginning + end) / 2;
        mergeSort(vector, beginning, middle);
        mergeSort(vector, middle + 1, end);
        merge(vector, beginning, middle, end);
    }
};

template <typename ItemType>
void merge(vector<ItemType>& vector, int beginning, int middle, int end) {
    int leftVectorLength = middle - beginning + 1;
    int rightVectorLength = end - middle;
    // temporary vectors
    std::vector<ItemType> left(leftVectorLength), right(rightVectorLength);
    for (int i = 0; i < leftVectorLength; i++) {
        left.at(i) = vector.at(beginning + i);
    }
    for (int i = 0; i < rightVectorLength; i++) {
        right.at(i) = vector.at(middle + 1 + i);
    }

    int i = 0, j = 0;
    int index = beginning;

    // Merge the temp vectors back into the original vector, from beginning to end, making sure the values are sorted
    while (i < leftVectorLength && j < rightVectorLength) {
        if (left.at(i) <= right.at(j)) {
            vector.at(index) = left.at(i);
            i++;
        } else {
            vector.at(index) = right.at(j);
            j++;
        }
        index++;
    }

    // Copy the remaining elements of the left temporary vector, if there are any, into the original vector
    while (i < leftVectorLength) {
        vector[index] = left[i];
        i++;
        index++;
    }

    // Copy the remaining elements of the right temporary vector, if there are any, into the original vector
    while (j < rightVectorLength) {
        vector[index] = right[j];
        j++;
        index++;
    }
};