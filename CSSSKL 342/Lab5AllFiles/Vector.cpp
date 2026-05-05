#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

static random_device generator;
static uniform_int_distribution<int> distribution(1, 100);

template <typename T>
void printVector(vector<T>& vectorToPrint);

int main() {
    vector<int> test1(5);
    for (vector<int>::iterator it = test1.begin(); it != test1.end();) {
        int value = distribution(generator);
        if (value % 2 == 0) {
            *it = value;
            it++;
        }
    }
    cout << "Values of test1 vector (all evens): " << endl;
    printVector(test1);
    for (int i = 0; i < 5;) {
        int value = distribution(generator);
        if (value % 2 == 1) {
            test1.push_back(value);
            i++;
        }
    }
    cout << "Values of test1 vector (evens and odds): " << endl;
    printVector(test1);
    sort(test1.begin(), test1.end());
    cout << "Values of test1 vector (sorted): " << endl;
    printVector(test1);

    vector<int> test2(test1);
    for (vector<int>::iterator it = test2.begin(); it != test2.end(); it++) {
        *it = *it * 2;
    }
    cout << "Values of test2 vector (double of test1): " << endl;
    printVector(test2);

    cout << "Print a 2D vector (test1 and test2): " << endl;
    vector<vector<int>> test3;
    test3.push_back(test1);
    test3.push_back(test2);
    for (vector<vector<int>>::iterator it = test3.begin(); it != test3.end(); it++) {
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << " ";
        }
        cout << endl;
    }
}

template <typename T>
void printVector(vector<T>& vectorToPrint) {
    for (typename vector<T>::iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}