#include "Vector.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Vector::Vector() {
    size = 2;
    array = new double[size]();
}
Vector::Vector(int newSize) {
    size = newSize;
    array = new double[size]();
}
Vector::Vector(const Vector& other) {
    if (this != &other) {
        size = other.size;
        array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }
}
Vector::~Vector() {
    clear();
}

int Vector::getSize() const {
    return size;
}
double Vector::getValueAt(const int& i) const {
    if (i < 0) {
        throw std::out_of_range("Error: trying to access a negative index for a vector.");
    } else if (i >= size) {
        throw std::out_of_range("Error: trying to access an out of bounds index for a vector.");
    }
    return array[i];
}
void Vector::setValueAt(const int& i, double& value) {
    if (i < 0) {
        throw std::out_of_range("Error: trying to access a negative index for a vector.");
    } else if (i >= size) {
        throw std::out_of_range("Error: trying to access an out of bounds index for a vector.");
    }
    array[i] = value;
}

// Euclidian norm: sqrt(x1^2 + x2^2 + ... xn^2)
double Vector::euclideanNorm() const {
    double vectorLength = 0.0;
    for (int i = 0; i < size; i++) {
        vectorLength += pow(array[i], 2);
    }
    vectorLength = sqrt(vectorLength);
    return vectorLength;
}
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        clear();
        size = other.size;
        array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}
// Inner product: x1*y1 + x2*y2 + ... xn*yn
double Vector::operator*(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Error: Vectors can't be multiplied because they're not the same size.");
    }
    double scalar = 0.0;
    for (int i = 0; i < size; i++) {
        scalar += (array[i] * other.array[i]);
    }
    return scalar;
}

void Vector::printInfo() const {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::clear() {
    delete[] array;
    array = nullptr;
}