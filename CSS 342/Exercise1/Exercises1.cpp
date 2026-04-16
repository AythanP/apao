#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int* arrayAllocate(int elements);
void assignIntElements(int* array, int size);
void compareArraysAddress(int* array1, int* array2) {cout << "First array address: " << array1 << " Second array address: " << array2 << endl;};
void swapMinArray(int* array1, int size1, int* array2, int size2);

int main() {
    int size = 5;
    int* arrayPtr1 = arrayAllocate(size);
    int* arrayPtr2 = arrayAllocate(size);
    for (int i = 0; i < size; i++) {
        cout << arrayPtr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arrayPtr2[i] << " ";
    }
    cout << endl;

    assignIntElements(arrayPtr1, size);
    assignIntElements(arrayPtr2, size);

    compareArraysAddress(arrayPtr1, arrayPtr2);
    for (int i = 0; i < size; i++) {
        cout << arrayPtr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arrayPtr2[i] << " ";
    }
    cout << endl;
    cout << endl;

    swapMinArray(arrayPtr1, size, arrayPtr2, size);
    for (int i = 0; i < size; i++) {
        cout << arrayPtr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arrayPtr2[i] << " ";
    }
    cout << endl;

    delete[] arrayPtr1;
    delete[] arrayPtr2;
}

int* arrayAllocate(int elements) {
    int* array = new int[elements];
    return array;
}

void assignIntElements(int* array, int size) {
    if (array == nullptr) {
        cout << "Array is empty." << endl;
        return;
    }

    //srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < size; i++) {
        array[i] = rand();
        cout << array[i] << " ";
    }
    cout << endl;
}

// without smaller random numbers, I have no clue if this works as intended
void swapMinArray(int* array1, int size1, int* array2, int size2) {
    if (array1 == nullptr || array2 == nullptr) {
        cout << "One of the arrays is empty." << endl;
        return;
    }

    int min1 = *array1;
    for (int i = 0; i < size1; ++i) {
        if (*(array1 + i) < min1) {
            min1 = *(array1 + i);
        }
    }

    int min2 = *array2;
    for (int i = 0; i < size2; ++i) {
        if (*(array2 + i) < min2) {
            min2 = *(array2 + i);
        }
    }

    *array1 = min2;
    *array2 = min1;
}
