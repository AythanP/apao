#include "Vector.h"
#include <iostream>

Vector2d::Vector2d() {
    x = 0;
    y = 0;
}
Vector2d:: Vector2d(double otherX, double otherY) {
    x = otherX;
    y = otherY;
}
Vector2d::Vector2d(const Vector2d& other) {
    x = other.x;
    y = other.y;
}
Vector2d::~Vector2d() {

}

Vector2d& Vector2d::operator=(const Vector2d& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// addition: a1 + b1, a2 + b2
Vector2d Vector2d::operator+(const Vector2d& b) const {
    return Vector2d(x + b.x, y + b.y);
}

// scalar multiplication: k * a1, k * a2
Vector2d Vector2d::operator*(const double scalar) const {
    return Vector2d(scalar * x, scalar * y);
}

// dot product: a1 * b1 + a2 * b2
double Vector2d::operator*(const Vector2d& b) const {
    return (x * b.x) + (y * b.y);
}

void Vector2d::printInfo() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}