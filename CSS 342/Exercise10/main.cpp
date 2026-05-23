#include <vector>
#include <iostream>
#include <random>
#include "Bubble.cpp"
#include "Insertion.cpp"
#include "Merge.cpp"

using namespace std;

template <typename ItemType>
void populateVector(vector<ItemType>& vector);
template <typename ItemType>
void printVector(vector<ItemType>& vector);

static random_device generator;
static uniform_int_distribution<int> distribution(1, 1000);

int main() {
    int length = distribution(generator);
    vector<int> vector(length);

    populateVector(vector);
    printVector(vector);
    bubbleSort(vector);
    printVector(vector);
    
    populateVector(vector);
    printVector(vector);
    insertionSort(vector);
    printVector(vector);

    populateVector(vector);
    printVector(vector);
    mergeSort(vector, 0, vector.size());
    printVector(vector);
}

template <typename ItemType>
void populateVector(vector<ItemType>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        int value = distribution(generator);
        vector.at(i) = value;
    }
}

template <typename ItemType>
void printVector(vector<ItemType>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector.at(i) << " ";
    }
    cout << endl << endl;
}