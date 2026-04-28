/*
 * Driver for simple int Square class.
 *
 * Author: Kelvin Sung
 * Date: Oct 2018
 */

#include <iostream>
#include <any>
#include "Square.h"

using namespace std;

template <typename T>
void MySwap(T &s1, T &s2) {
    T t = s1;
    s1 = s2;
    s2 = t;
}

template <typename T>
void MyBubbleSort(T *data, int size) {
    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size-1-i; j++) {
            if (data[j] < data[j+1])
                MySwap(data[j], data[j+1]);
        }
    }
}

template <typename T>
void printArray(string msg, T *data, int size) {
    cout << msg << endl;
    for (int i = 0; i<size; i++) {
        cout <<  data[i] << " ";
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    Square<int> s1, s2;

    s1.setSize(5);
    s2.setSize(3);

    cout << "S1 is: " << s1 << endl;
    cout << "S2 is: " << s2 << endl;

    if (s1 < s2) 
        cout << "s1 is smaller" << endl;
    else 
        cout << "s2 is smaller" << endl;

    s1 = s2;
    cout << "after assignment" << endl;
    cout << "s1 is:" << s1 << endl;
    cout << "s2 is:" << s2 << endl;
    
    // do bubble sort
    int  num[10] = {10, 9, 8, 1, 0, 7, 20, 14, 2, 4};
    Square<int> sArray[10];  // call initialize by default constructors
    for (int i = 0; i<10; i++) {
        sArray[i].setSize(num[i]);
    }
    printArray("Array before sorting:", sArray, 10);
    MyBubbleSort(sArray, 10);
    printArray("Array after sorting:", sArray, 10);

    int floatSize = 5;
    float array1[5] = {10.44, 10.3, 0.33, 9.2, 5.56};
    int intSize = 7;
    int array2[7] = {4, 6, 3, 99, 2, 333, -3};
    int charSize = 4;
    char array3[4] = {'c', 'a', 'r', 's'};

    printArray("Float array before sorting:", array1, floatSize);
    MyBubbleSort(array1, floatSize);
    printArray("Float array after sorting:", array1, floatSize);
    printArray("Int array before sorting:", array2, intSize);
    MyBubbleSort(array2, intSize);
    printArray("Int array after sorting:", array2, intSize);
    printArray("Char array before sorting:", array3, charSize);
    MyBubbleSort(array3, charSize);
    printArray("Char array after sorting:", array3, charSize);

    Square<double>* squareList = new Square<double>[5]();
    int squareListSize = 5;
    for (int i = 0; i < squareListSize; i++) {
        squareList[i].setSize(i * 1.25);
    }
    printArray("squareList before sorting:", squareList, squareListSize);
    MyBubbleSort(squareList, squareListSize);
    printArray("squareList after sorting:", squareList, squareListSize);

    delete[] squareList;
}
