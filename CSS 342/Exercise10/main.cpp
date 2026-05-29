#include <vector>
#include <iostream>
#include <random>
#include "Bubble.cpp"
#include "Insertion.cpp"
#include "Merge.cpp"
#include "Quick.cpp"

using namespace std;

template <typename ItemType>
void populateVector(vector<ItemType> &vector);
template <typename ItemType>
void printVector(vector<ItemType> &vector);
template <typename ItemType>
void printResultsSimple(vector<ItemType> vector, void (*sortingFunction)(std::vector<ItemType> &vector));
template <typename ItemType>
void printResultsComplex(vector<ItemType> vector, void (*sortingFunction)(std::vector<ItemType> &vector, int beginning, int end));

random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(1, 563);

int main() {
    int length = distribution(generator);
    vector<int> vector(length);

    /*
    populateVector(vector);
    printVector(vector);
    cout << "Bubble sort: " << endl;
    bubbleSort(vector);
    printVector(vector);
    */
    printResultsSimple(vector, &bubbleSort);

    populateVector(vector);
    printVector(vector);
    cout << "Insertion sort: " << endl;
    insertionSort(vector);
    printVector(vector);

    populateVector(vector);
    printVector(vector);
    cout << "Merge sort: " << endl;
    mergeSort(vector, 0, vector.size() - 1);
    printVector(vector);

    populateVector(vector);
    printVector(vector);
    cout << "Quick sort: " << endl;
    quickSort(vector, 0, vector.size() - 1);
    printVector(vector);
}

template <typename ItemType>
void populateVector(vector<ItemType> &vector) {
    for (int i = 0; i < vector.size(); i++)
    {
        int value = distribution(generator);
        vector.at(i) = value;
    }
}

template <typename ItemType>
void printVector(vector<ItemType> &vector) {
    for (int i = 0; i < vector.size(); i++)
    {
        if (i >= 25 && i % 25 == 0)
        {
            cout << endl;
        }
        cout << vector.at(i) << " ";
    }
    cout << endl
         << endl;
}

template <typename ItemType>
void printResultsSimple(vector<ItemType> vector, void (*sortingFunction)(std::vector<ItemType> &vector)) {
    populateVector(vector);
    printVector(vector);
    cout << "Sorted vector: " << endl;
    sortingFunction(vector);
    printVector(vector);
}

template <typename ItemType>
void printResultsComplex(vector<ItemType> vector, void (*sortingFunction)(std::vector<ItemType> &vector, int beginning, int end)) {
    populateVector(vector);
    printVector(vector);
    cout << "Sorted vector: " << endl;
    sortingFunction(vector, 0, vector.size() - 1);
    printVector(vector);
}