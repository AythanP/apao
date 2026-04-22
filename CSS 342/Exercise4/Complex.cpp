#include "Complex.h"

Complex::Complex() {
}
Complex::Complex(const double &real, const double &imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}
Complex::Complex(const Complex &other) {
    this->real = other.real;
    this->imaginary = other.imaginary;
}
Complex::~Complex() {
}
void Complex::setReal(const double &r) {
    this->real = r;
}

void Complex::setImaginary(const double &i) {
    this->imaginary = i;
}
double Complex::getReal() const {
    return this->real;
}
double Complex::getImaginary() const {
    return this->imaginary;
}

Complex Complex::conjugate() const {
    return Complex(this->real, -1 * this->imaginary);
}

Complex Complex::operator+(const Complex &c) {
    return Complex(this->real + c.real, this->imaginary + c.imaginary);
}
Complex Complex::operator-(const Complex &c) {
    return Complex(this->real - c.real, this->imaginary - c.imaginary);
}
Complex Complex::operator*(const Complex &c) {
    return Complex(this->real * c.real - this->imaginary * c.imaginary, this->real * c.imaginary + this->imaginary * c.real);
}
Complex Complex::operator/(const Complex &c) {
    Complex numerator = (*this) * c.conjugate();
    double denominator = (c.real * c.real) + (c.imaginary * c.imaginary);
    return Complex(numerator.real / denominator, numerator.imaginary / denominator);
}