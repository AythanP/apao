#include "linkedlist.cpp"
#include <iostream>

using namespace std;

int main() {
    LinkedList<int> list = LinkedList<int>();
    for (int i = 1; i <= 20; i++) {
        list.insert(i, i);
    }
    for (int i = 1; i <= list.getLength(); i++) {
        cout << list.getEntry(i) << endl;
    }

    return 0;
}