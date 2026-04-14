/*
 * ArrayDemo2
 *
 * Created by Rob Nash
 *
 * Modified by Yang Peng on 03/24/2025
 * Modified by Aythan Pao on 04/10/2026
 */

#include <iostream>
using namespace std;

// Forward declarations.
void display(int data[], int size);
int linearSearch(int data[], int size, int target);
void bubble2(int* data, int size);
void swap2(int* idx1, int* idx2);

int main(int argc, const char * argv[])
{
  const int SIZE = 7;
  // These are auto variables.
  int* set = new int[SIZE]{1,4,3,2,5,9,8}; // Size implicit
  int* set2 = new int[SIZE]{30, 23, 25, 19, 100, 12, 7};
  // How does it look like in JAVA?
  // int[] myArray = new int[3];
  // int[] myArray = {1, 2, 3};
  // int[] myArray = new int[] {1, 2, 3};
    
  // You have to pass the size in; a C++ array is just a dumb block of
  // storage; no size information is carried with it and no bounds
  // checking is done.
  display(set, SIZE);
  bubble2(set, SIZE);
  display(set, SIZE);

  cout << linearSearch(set, SIZE, 5) << endl;

  delete[] set;
  delete[] set2;
  set = nullptr;
  set2 = nullptr;
  return 0;
}

void display(int* data, int size) {
  if (data == nullptr) {
    cout << "data is emtpy" << endl;
  }
  else {
    for(int i = 0; i < size; i++) {
        cout << *(data + i) << ",";
    }
    cout << std::endl;
  }
}

// exercise 4 function prototype
int linearSearch(int* data, int size, int target) {
  if (data == nullptr) {
    cout << "data is emtpy" << endl;
  }
  else {
    for (int i = 0; i < size; i++) {
        if (*(data + i) == target) {
            return i;
        }
    }
  }

  return -1;
}

// exercise 4 function prototype
void bubble2(int* data, int size)
{
  if (data == nullptr) {
    cout << "data is empty" << endl;
  }
  else {
    for(int i = 0; i < size; i++) {
      for(int k = 0; k < size - 1 - i; k++) {
        if(*(data + k) < *(data + (k + 1))) {
		    swap2(data + k, data + (k+1));
        }
      }
    }
  }
}

// exercise 4 function prototype
void swap2(int* idx1, int* idx2)
{
  if (idx1 == nullptr && idx2 == nullptr) {
    cout << "idx1 and idx2 are empty" << endl;
  }
  else if (idx1 == nullptr) {
    cout << "idx1 is empty" << endl;
  }
  else if (idx2 == nullptr) {
    cout << "idx2 is empty" << endl;
  }
  else {
    int temp = *idx1;
    *idx1 = *idx2;
    *idx2 = temp;
  }
}
