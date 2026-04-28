/*
 *  Square.cpp
 *  Class-example
 *
 */

#ifndef Square_CPP
#define Square_CPP

#include <iostream>
#include "Square.h"

using namespace std;
template <class ItemType>
void Square<ItemType>::setSize(ItemType newSize)
{
	theSize = newSize;
}

template <class ItemType>
ItemType Square<ItemType>::getSize(void) const
{
	return theSize;
}

template <class ItemType>
Square<ItemType> & Square<ItemType>::operator=(const Square<ItemType>& other)
{
	theSize = other.getSize();
	return *this;
}

template <class T>
ostream& operator<<(ostream &os, const Square<T> &c)
{
	os << c.getSize();
	return os;
}

template <class ItemType>
bool Square<ItemType>::operator<(const Square<ItemType>& other) const
{
	return theSize < other.getSize();
}

#endif