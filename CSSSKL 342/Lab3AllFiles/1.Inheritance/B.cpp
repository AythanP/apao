/*
 *  B.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#include "B.h"
#include <iostream>

using namespace std;

B::B()
{
  setN("unnamed B");
  setData1(5);
  setData2(6);
  testDataB = 10;
  cout << "Inside B::B() for object " << getN() << " " << getData1() << " " << getData2() << " " << testDataB << endl;
}

B::B(string name, int data1, int data2, int dataB) : A(name, data1, data2), testDataB(dataB)
{
  cout << "Inside B::B(string) for object " << getN() << " " << getData1() << " " << getData2() << " " << testDataB << endl;
}


B::~B()
{
  cout << "Inside B::~B() for object " << getN() << " " << getData1() << " " << getData2() << " " << testDataB << endl;
}

void B::setDataB(const int dataB) {
  testDataB = dataB;
}
int B::getDataB() const {
  return testDataB;
}