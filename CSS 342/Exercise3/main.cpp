#include <iostream>
#include <cstdlib>
#include "Vector.h"

using namespace std;

int main() {
    Vector2d test;
    cout << "Vector test: " << endl;
    test.printInfo();

    Vector2d test2(5, 6);
    cout << "Vector test2: " << endl;
    test2.printInfo();

    Vector2d test3(test2);
    cout << "Vector test3: " << endl;
    test3.printInfo();
    test = test3;
    cout << "Vector test reassigned: " << endl;
    test.printInfo();

    Vector2d test4 = test2;
    cout << "Vector test4: " << endl;
    test4.printInfo();

    double scalar1 = 3.45;
    int scalar2 = -5;
    
    test = test2 + test3;
    test2 = test2 * scalar1;
    test3 = test3 * scalar2;
    double dot = test2 * test3;

    cout << "test2 plus test3: " << endl;
    test.printInfo();

    cout << "test2 mulitplied by positive double scalar: " << endl;
    test2.printInfo();

    cout << "test3 multiplied by negative integer scalar: " << endl;
    test3.printInfo();

    cout << "product of test2 by test3: " << dot << endl;
}