/*
 * Author: Aythan Pao
 * Date: 4-15-26
 * Description: Program containing the functions for CSS 342 B assignment 1
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;

int* arrayRandom(int elements, int base);
void printArray(int* array, int size);
int toDecimalNumber(int* array, int size, int base);
int* convertToBase(int decimalNum, int base);
int convertToBaseHelper(int decimalNum, int base);

int main(int argc, char *argv[]) {
    // get user input
    int base = 0;
    do {
        cout << "Enter a positive integer greater than 1 for a base value" << endl;
        cin >> base;

        if (base <= 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please try again" << endl;
        }
    }
    while (cin.fail() || base <= 1);

    int n = 0;
    do {
        cout << "Enter a positive integer for number of elements" << endl;
        cin >> n;

        if (n <= 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please try again" << endl;
        }
    }
    while (cin.fail() || n <= 0);

    cout << "Contents of the user-created array: " << endl;
    int* baseArray = arrayRandom(n, base);
    printArray(baseArray, n);
    int decimalNum = toDecimalNumber(baseArray, n, base);
    cout << "User-created array as a decimal number using the provided base:\n" << decimalNum  << endl;
    
    int newBase = 0;
    do {
        cout << "Enter another positive integer greater than 1 for a new base value" << endl;
        cin >> newBase;

        if (newBase <= 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please try again" << endl;
        }
    }
    while (cin.fail() || newBase <= 1);
    
    cout << "Converting " << decimalNum << " to base " << newBase << ": " << endl;
    int* baseAny = convertToBase(decimalNum, newBase);
    if (baseAny == nullptr) {
        cout << "baseAny is null" << endl;
        return 0;
    }
    int baseAnyLength = convertToBaseHelper(decimalNum, newBase);
    printArray(baseAny, baseAnyLength);

    delete[] baseArray;
    delete[] baseAny;

    return 0;
}

// creates a pointer to an array [elements] big, with each element less than [base]
int* arrayRandom(int elements, int base) {
    if (base <= 1) {
        cout << "Invalid argument for arrayRandom(): base is less than or equal to 1" << endl;
        return nullptr;
    }
    else if (elements <= 0) {
        cout << "Invalid argument for arrayRandom(): there are no elements to dynamically allocate an array to" << endl;
        return nullptr;
    }

    int* array = new int[elements];
    std::random_device rd;
    std::default_random_engine generator(rd());
    // to prevent ak = 0
    uniform_int_distribution<int> firstDistribution(1, base - 1);
    uniform_int_distribution<int> normDistribution(0, base - 1);
    
    for (int i = 0; i < elements; i++) {
        if (i == 0) {
            *(array + i) = firstDistribution(generator);
        } else {
            *(array + i) = normDistribution(generator);
        }
    }

    return array;
}

// prints out the contents of an integer pointer array
void printArray(int* array, int size) {
    if (array == nullptr) {
        cout << "Invalid argument for printArray(): array pointer is null" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

// convert an array containing integers to the corresponding decimal number in base [base]
int toDecimalNumber(int* array, int size, int base) {
    if (array == nullptr) {
        cout << "Invalid argument for toDecimal(): array pointer is null" << endl;
        return 0;
    }

    int decimalNum = 0;
    for (int i = 0; i < size; i++) {
        decimalNum += *(array + i) * pow(base, size - 1 - i);
    }

    return decimalNum;
}

// convert a decimal number to any base
int* convertToBase(int decimalNum, int base) {
    if (base <= 1) {
        cout << "Invalid argument for convertToBaseHelper(): base is less than or equal to 1" << endl;
        return nullptr;
    }
    else if (decimalNum < 0) {
        cout << "Invalid argument for convertToBaseHelper(): decimalNum is less than 0" << endl;
        return nullptr;
    }

    int quotient, remainder;
    int index = convertToBaseHelper(decimalNum, base);

    int* newBase = new int[index];
    // reverse order because the first remainder is the smallest number, which belongs to the last index
    for (int i = index - 1; i >= 0; i--) {
        remainder = decimalNum % base;
        quotient = decimalNum / base;
        *(newBase + i) = remainder;
        decimalNum = quotient;
    }

    return newBase;
}

// find the length of an array representation of a decimal number, given its base
int convertToBaseHelper(int decimalNum, int base) {
    int quotient;
    int index = 0;
    do {
        index++;
        quotient = decimalNum / base;
        // to prevent infinite loop
        decimalNum = quotient;
    }
    while (quotient != 0);

    return index;
}