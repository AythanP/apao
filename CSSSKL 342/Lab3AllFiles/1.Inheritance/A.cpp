/*
 *  A.cpp
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#include "A.h"
#include <iostream>

using namespace std;

A::A()
{
    n = "unnamed A";
    testData1 = 3;
    testData2 = 32;
    cout << "Inside A::A() for object " << n << " " << testData1 << " " << testData2 << endl;
}

A::A(string name, int data1, int data2) : n(name), testData1(data1), testData2(data2)
{
    cout << "Inside A::A(string) for object " << n << " " << testData1 << " " << testData2 << endl;
}


A::~A()
{
    cout << "Inside A::~A() for object " << n << " " << testData1 << " " << testData2 << endl;
}


void A::setN(const char* s)
{
  n = s;
}
void A::setData1(const int data1) {
  testData1 = data1;
}
void A::setData2(const int data2) {
  testData2 = data2;
}

string A::getN(void) const
{
  return n;
}
int A::getData1() const {
  return testData1;
}
int A::getData2() const {
  return testData2;
}

