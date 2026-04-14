/*
 *  Pointer1.cpp
 *
 *  Created by Rob Nash
 *
 *  Modified by Yang Peng on 01/09/18
 */


#include <iostream>
using namespace std;


void display1(int l, int m, int n, int o, int* p) {
  cout << "\ndisplay1():" << endl;
  cout << "var1 is " << l << endl;
  cout << "var2 is " << m << endl;
  cout << "var3 is " << n << endl;
  cout << "var4 is " << o << endl;
  cout << "address of \"l\" (var1) is " << &l << endl;
}

void display2(int l, int m, int n, int o, int& p) {
  cout << "\ndisplay2():" << endl;
  cout << "var1 is " << l << endl;
  cout << "var2 is " << m << endl;
  cout << "var3 is " << n << endl;
  cout << "var4 is " << o << endl;
  cout << "address of \"l\" (var1) is " << &l << endl;
}

void display3(int m, int* p) {
  m = 10;
  *p = 50;
  cout << "The value of p: " << *p << endl;
  cout << "The address of the variable being pointed to by p: " << p << endl;
  cout << "The address of the p: " << &p << endl;
};

int main()
{
  int a = 3;
  int b, c, d;
  int *aPtr, bPtr;  //Pitfall: note that bPtr is an int, not an int *
  b = 3;
  c = 5;
  d = a + b + c;
    
  aPtr = &a;

  // Fix the call for display2() without changing the function
  int& aRef = *aPtr;
    
  display1(a, b, c, d, aPtr);
  display2(a, b, c, d, aRef);
    
  cout << endl;
  cout << "\"aPtr\" is a pointer, whose value is " << aPtr << endl;
  cout << "This is the same as \"&a\", or " << &a << endl;
    
  cout << endl;
  cout << "\"aPtr\" points to the following value:  " << *aPtr << endl;
  cout << "This is the same as \"a\", or " << a <<endl;
  
  // Your additional code here.
  cout << endl;
  cout << "The value of b: " << b << endl;
  cout << "The value of a: " << a << endl;
  display3(b, aPtr);
  cout << "The new value of b: " << b << endl;
  cout << "The new value of a: " << a << endl;
  *aPtr = 6;
  cout << "The value of aPtr: " << *aPtr << endl;
  cout << "The value of a: " << a << endl;
  return 0;
}
