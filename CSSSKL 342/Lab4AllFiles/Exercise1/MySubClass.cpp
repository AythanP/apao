#include "MySubClass.h"

MySubClass::MySubClass() : MyClass(), subClassData(0) {

}
MySubClass::MySubClass(const MySubClass& other) : MyClass(other), subClassData(other.subClassData) {

}

int MySubClass::getSubClassData() const {
    return subClassData;
}
void MySubClass::setSubClassData(const int newSubClassData) {
    subClassData = newSubClassData;
}

MySubClass& MySubClass::operator=(const MySubClass& other) {
    if (this != &other) {
      MyClass::operator=(other);
      subClassData = other.subClassData;
    }
    return *this;
}