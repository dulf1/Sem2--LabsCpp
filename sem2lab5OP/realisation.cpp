#include "realisation.h"
#include <cstdio>

template <typename T>
void Change(T& first, T& second) {
    T x = first;
    first = second;
    second = x;
}

MatrixListOfRange::MatrixListOfRange(int N, int M) {
    const int size = 100;
    message = new char[size];
    snprintf(message, size, "Index out of range. Matrix size: %dx%d", N, M);
}

MatrixListOfRange::~MatrixListOfRange() {
    delete[] message;
}

const char* MatrixListOfRange::what() const noexcept {
    return message;
}

template<typename T>
Matrix<T>::Matrix(const int n, const int m) {
    N = n;
    M = m;
    array = new T*[N];
    for (int i = 0; i < N; i++) {
        array[i] = new T[M];
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
}

template<typename T>
T& Matrix<T>::at(int i, int j) {
    if (i < 0 or i >= N or j < 0 or j >= M) {
        throw MatrixListOfRange(N, M);
    }
    return array[i][j];
}

template<typename T>
void Matrix<T>::add(int i, int j, T value) {
    if (i < 0 or i >= N or j < 0 or j >= M) {
        throw MatrixListOfRange(N, M);
    }
    array[i][j] = value;
}

template<typename T>
void Matrix<T>::show() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template void Change<int>(int&, int&);
template void Change<short>(short&, short&);
template void Change<char>(char&, char&);
template void Change<long long>(long long&, long long&);
template void Change<double>(double&, double&);
template void Change<float>(float&, float&);
template class Matrix<int>;
template class Matrix<short>;
template class Matrix<char>;
template class Matrix<long long>;
template class Matrix<double>;
template class Matrix<float>;

