/*
 *  Primitive1.cpp
 *
 *  Created by Rob Nash
 *
 *  Modified by Yang Peng on 03/18/2025
 */

#include <iostream>
//#define DEBUG
int main()
{
  int a = 3;
  int b, c;
  b = c = 8;
    
  int d = a + b + c;
    
  std::cout << "Hello, World!\n";

  std::cout << "Ugly: " << a;
  std::cout << "a is " << a;
  std::cout << "b is " << b;
  std::cout << "c is " << c;
  std::cout << "d is " << d;

  int e, f = 10;
  // What is the value of e?
  // Does e have an initial value?
    
#ifdef DEBUG
  std::cerr << "This is a debug statement" << std::endl;
#endif
  return 0;   
}
