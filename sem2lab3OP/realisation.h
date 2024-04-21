#ifndef SEM2LAB3OP_REALISATION_H
#define SEM2LAB3OP_REALISATION_H

#include <iostream>

const int MAX_LENGTH = 100;

class Array {
private:
    int data[MAX_LENGTH];
    int length;

public:
    Array();

    int getLength() const;

    void append(int n);

    Array operator+(const Array &other) const;

    bool operator==(const Array &other) const;

    bool operator>(const Array &other) const;

    bool operator<(const Array &other) const;

    bool operator!=(const Array &other) const;

    void display() const;
};

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0);
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    Complex operator+(const Complex &other) const;
    Complex operator*(const Complex &other) const;
    Complex operator*(double scalar) const;
    double length() const;
};

#endif //SEM2LAB3OP_REALISATION_H
