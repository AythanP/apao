#include <iostream>
#include "Vector.h"
#include "Complex.h"

using namespace std;

int main() {
    Vector<int> test1(5);
    Vector<double> test2(11);
    Vector<Complex> test3(4);

    for (int i = 0; i < test1.getCapacity(); i++) {
        test1.setDataAt(i, rand() % 10);
        cout << test1.getDataAt(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < test2.getCapacity(); i++) {
        test2.setDataAt(i, rand() % 10);
        cout << test2.getDataAt(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < test3.getCapacity(); i++) {
        test3.setDataAt(i, Complex(rand() % 10, rand() % 10));
        cout << test3.getDataAt(i).getReal() << " + " << test3.getDataAt(i).getImaginary() << "i ";
    }
    cout << endl;

    Vector<Complex> test4(test3);
    for (int i = 0; i < test4.getCapacity(); i++) {
        test4.setDataAt(i, Complex(rand() % 10, rand() % 10));
        cout << test4.getDataAt(i).getReal() << " + " << test4.getDataAt(i).getImaginary() << "i ";
    }
    cout << endl;

    Complex c1 = test3.getDataAt(0) + test4.getDataAt(0);
    cout << c1.getReal() << " + " << c1.getImaginary() << "i " << endl;

    Complex c2 = test3.getDataAt(1) - test4.getDataAt(1);
    cout << c2.getReal() << " - " << c2.getImaginary() << "i " << endl;

    Complex c3 = test3.getDataAt(2) * test4.getDataAt(2);
    cout << c3.getReal() << " * " << c3.getImaginary() << "i " << endl;

    Complex c4 = test3.getDataAt(3) / test4.getDataAt(3);
    cout << c4.getReal() << " / " << c4.getImaginary() << "i " << endl;
}