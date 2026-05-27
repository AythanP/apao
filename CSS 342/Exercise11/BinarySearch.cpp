#include <vector>
#include <stdexcept>

using namespace std;

// return the index the value is at with binary search algorithm
template <typename ItemType>
int binarySearch(const vector<ItemType> vector, ItemType target) {
    if (vector.empty()) {
        throw invalid_argument("Cannot search an empty vector");
    }
    int low = 0;
    int high = vector.size() - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (vector[middle] == target) {
            return middle;
        } else if (vector[middle] < target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return -1;
}

// return the index the value is at with recursive binary search algorithm
template <typename ItemType>
int binarySearchRecursive(const vector<ItemType> vector, ItemType target, int low, int high) {
    if (vector.empty()) {
        throw invalid_argument("Cannot search an empty vector");
    }
    if (low > high) {
        return -1;
    }
    int middle = (low + high) / 2;
    if (vector[middle] == target) {
        return middle;
    }
    if (vector[middle] < target) {
        return binarySearchRecursive(vector, target, middle + 1, high);
    } else {
        return binarySearchRecursive(vector, target, low, middle - 1);
    }
}