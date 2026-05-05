#include <iostream>
#include <list>

using namespace std;

template <typename T>
void printList(const list<T>& myList);
bool is_odd (const int& value) { return (value % 2 == 1); }

int main() {
    list<int> myList1;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) {
            myList1.emplace_back(i);
        }
    }
    cout << "Contents of myList1: ";
    printList(myList1);

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            myList1.emplace_front(i);
        }
    }
    cout << "Contents of myList1: ";
    printList(myList1);

    cout << "First element of myList1: " << myList1.front() << endl;
    cout << "Last element of myList1: " << myList1.back() << endl;

    myList1.remove(3);
    cout << "myList1 shouldn't have 3 in it: ";
    printList(myList1);

    myList1.sort();
    cout << "myList1 sorted: ";
    printList(myList1);

    myList1.remove_if(is_odd);
    cout << "myList1 with no odd numbers: ";
    printList(myList1);
}

template <typename T>
void printList(const list<T>& myList) {
    for (typename list<T>::const_iterator it = myList.begin(); it != myList.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}