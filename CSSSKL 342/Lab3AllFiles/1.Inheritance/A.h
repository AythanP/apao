/*
 *  A.h
 *  Inheritance Example
 *
 *  Created by Prof. Michael Stiber
 *  Modified by Yang Peng on 01/12/2018
 *
 */

#ifndef A_H
#define A_H

#include <string>
using namespace std;

class A
{
public:
    A();
    A(string name, int data1, int data2);
	~A();
    
    void setN(const char* s);
    void setData1(const int data1);
    void setData2(const int data2);
    string getN() const;
    int getData1() const;
    int getData2() const;
    
private:
    string n;
    int testData1;
    int testData2;
};

#endif
