#include <iostream>

using namespace std;

int multiply(int m, int n);

int main() {
    int test1 = multiply(5, 6);

    cout << test1 << endl;
}

int multiply(int m, int n) {
    if (n == 1) {
        return m;
    }
    else {
        return multiply(m, n - 1) + m;
    }
}