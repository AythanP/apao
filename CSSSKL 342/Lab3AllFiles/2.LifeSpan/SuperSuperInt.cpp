#include "SuperSuperInt.h"
#include <cstdlib>
#include <iostream>

using namespace std;

SuperSuperInt::SuperSuperInt(int init, const char *name) : SuperInt(init, name) {
    cout << "Created a SuperSuperInt called " + getMyName() << endl;
}

SuperSuperInt::~SuperSuperInt() {
    cout << "Destroyed a SuperSuperInt called " + getMyName() << endl;
}

const int& SuperSuperInt::theValue(void) {
    return SuperInt::theValue();
}