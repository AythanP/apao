#ifndef Complex_H
#define Complex_H

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(const double &real, const double &imaginary = 0.0);
    Complex(const Complex &c);
    ~Complex();

    void setReal(const double &r);
    void setImaginary(const double &i);
    double getReal() const;
    double getImaginary() const;

    Complex conjugate() const;
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
};

#endif