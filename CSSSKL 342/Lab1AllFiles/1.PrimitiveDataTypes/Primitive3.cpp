#include <iostream>
#include <cmath>

using namespace std;

int myRoundingFunction(double value);

int main() {
    double *test = new double[6]{0.4, 0.5, 0.6, -0.4, -0.5, -0.6};
    int testLength = 6;
    for (int i = 0; i < testLength; i++) {
        printf("%d\n", myRoundingFunction(test[i]));
    }   
    printf("%d\n", myRoundingFunction(-5.5));
    delete[] test;

    return 0;
}

int myRoundingFunction(double value) {
    double whole;
    // modf returns the fraction and assigns the integer to a pointer that's the same data type as its first parameter
    double fraction = modf(value, &whole);

    if (value >= 0 && fraction >= 0.5) {
        return whole += 1;
    }
    else if (value >= 0 && fraction < 0.5) {
        return whole;
    }
    else if (value < 0 && abs(fraction) >= 0.5) {
        return whole -= 1;
    }
    else if (value < 0 && abs(fraction) < 0.5) {
        return whole;
    }
    else {
        return whole;
    }
}