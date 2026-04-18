/*
 *  C.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#include "C.h"
#include <iostream>

using namespace std;

C::C()
{
  setN("unnamed C");
  setData1(30);
  setData2(40);
  setDataB(50);
  testDataC = 60;
  cout << "Inside C::C() for object " << getN() << " " << getData1() << " " << getData2() << " " << getDataB() << " " << testDataC << endl;
}

C::C(string name, int data1, int data2, int dataB, double dataC) : B(name, data1, data2, dataB), testDataC(dataC)
{
  cout << "Inside C::C(string) for object " << getN() << " " << getData1() << " " << getData2() << " " << getDataB() << " " << testDataC  << endl;
}


C::~C()
{
  cout << "Inside C::~C() for object " << getN() << " " << getData1() << " " << getData2() << " " << getDataB() << " " << testDataC  << endl;
}

void C::setDataC(const int dataC) {
    testDataC = dataC;
}
int C::getDataC() const {
  return testDataC;
}
