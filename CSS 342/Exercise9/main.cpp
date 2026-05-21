#include <iostream>
#include "linkedlist.h"
#include "linked_iterator.h"
#include "linked_stack.h"
#include "LinkedStackIterator.h"

using namespace std;

int main() {
    LinkedList<int> test1;
    for (int i = 1; i <= 6; i++) {
        test1.insert(i, i);
    }

    LinkedIterator<int> linkIterator = test1.begin();
    while (linkIterator != test1.end()) {
        cout << *linkIterator << endl;
        ++linkIterator;
    }

    LinkedStack<int> test2;
    for (int i = 0; i < 10; i++) {
        test2.push(i);
    }

    LinkedStackIterator<int> stackIterator = test2.begin();
    while (stackIterator != test2.end()) {
        cout << *stackIterator << endl;
        ++stackIterator;
    }
}