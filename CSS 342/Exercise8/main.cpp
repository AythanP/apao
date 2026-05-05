#include <iostream>
#include "array_queue.h"
#include "list_queue.h"

using namespace std;

int main() {
    ArrayQueue<int> test1 = ArrayQueue<int>();
    bool removeSuccessful = test1.dequeue();
    cout << removeSuccessful << endl << endl;
    for (int i = 0; i < 50; i++) {
        // TODO: enqueue doesn't work
        bool addSuccessful = test1.enqueue(i);
        cout << addSuccessful << endl;
    }
    cout << endl;
    bool addSuccessful = test1.enqueue(51);
    cout << addSuccessful << endl << endl;

    int value = test1.peekFront();
    cout << value << endl;

    ListQueue<int> test2 = ListQueue<int>();
    removeSuccessful = test2.dequeue();
    cout << removeSuccessful << endl;
    for (int i = 0; i < 10; i++) {
        bool addSuccessful = test2.enqueue(i);
        cout << addSuccessful << endl;
    }
    int value2 = test2.peekFront();
    cout << value2 << endl;
}