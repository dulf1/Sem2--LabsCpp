#ifndef SEM2LAB5OP_REALISATION_H
#define SEM2LAB5OP_REALISATION_H

#include <iostream>
#include <exception>

template<typename T>
void Change(T &first, T &second);

class MatrixListOfRange : public std::exception {
private:
    char* message;
public:
    MatrixListOfRange(int N, int M);
    ~MatrixListOfRange();
    const char* what() const noexcept override;
};

template<typename T>
class Matrix {
private:
    int N, M;
    T **array;
public:
    Matrix() = default;
    Matrix(const int n, const int m);
    T& at(int i, int j);
    void add(int i, int j, T value);
    void show();
    ~Matrix();
};
#endif //SEM2LAB5OP_REALISATION_H
