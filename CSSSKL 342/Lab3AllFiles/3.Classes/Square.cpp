/*
 *  Square.cpp
 *  Class-example
 *
 */

#include "Square.h"

void Square::setSize(int newSize)
{
   theSize = newSize;
}


int Square::getSize(void) const
{
   return theSize;
}

// The Square class needs an overloaded assignment operator to allow initialized objects to be assigned new values, allowing them to behave like primitive data types. 
Square& Square::operator = (const Square& other)
{
	theSize = other.getSize();
	return *this;
}

bool Square::operator<(const Square& other) const {
   if (theSize < other.theSize) {
      return true;
   }
   else {
      return false;
   }
}