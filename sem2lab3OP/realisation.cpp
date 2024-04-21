#include "realisation.h"
#include <cmath>

Array::Array() {
    length = 0;
}

int Array::getLength() const {
    return length;
}

void Array::append(int n) {
    if (length < MAX_LENGTH) {
        data[length++] = n;
    } else {
        std::cout << "length > 100" << std::endl;
    }
}

Array Array::operator+(const Array &other) const {
    Array result;
    for (int i = 0; i < length; i++) {
        result.data[i] = data[i];
        result.length++;
    }

    for (int i = 0; i < other.length and result.length < MAX_LENGTH; i++) {
        result.data[result.length] = other.data[i];
        result.length++;
    }

    return result;
}

bool Array::operator==(const Array &other) const {
    return length == other.length;
}

bool Array::operator>(const Array &other) const {
    return length > other.length;
}

bool Array::operator<(const Array &other) const {
    return length < other.length;
}

bool Array::operator!=(const Array &other) const {
    return length != other.length;
}

void Array::display() const {
    for (int i = 0; i < length; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator*(const Complex &other) const {
    double result_real = real * other.real - imaginary * other.imaginary;
    double result_imaginary = real * other.imaginary + imaginary * other.real;
    return Complex(result_real, result_imaginary);
}

Complex Complex::operator*(double scalar) const {
    return Complex(real * scalar, imaginary * scalar);
}

double Complex::length() const {
    return std::sqrt(real * real + imaginary * imaginary);
}