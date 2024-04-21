#include <iostream>
#include "comands.h"

using namespace std;

int main() {
    int a = 10;
    float b = 3.5;
    float matrix[3][3]{{1,1,1},{1,1,1},{1,1,1}},value = 1.5;
    increaseByValuePointer(&a, 5);
    cout << "Increased value using pointer: " << a << std::endl;

    increaseByValueReference(a, 7);
    cout << "Increased value using reference: " << a << std::endl;

    changeSignPointer(&b);
    cout << "Changed sign for float using pointer: " << b << std::endl;

    changeSignReference(b);
    cout << "Changed sign for float using reference: " << b << std::endl;

    int c = -8;
    changeSignPointer(&c);
    cout << "Changed sign for int using pointer: " << c << std::endl;

    changeSignReference(c);
    cout << "Changed sign for int using reference: " << c << std::endl;

    multiplicationMatrixPointer(&matrix,value);
    cout << "Changed matrix after multiplication using pointer";
    for (int i = 0;i<3;i++){
        for (int j = 0;j<3;j++){
            cout << matrix[i][j] << " ";
        }
    }
    cout << "\n";
    multiplicationMatrixReference(matrix,value);
    cout << "Changed matrix after multiplication using reference";
    for (int i = 0;i<3;i++){
        for (int j = 0;j<3;j++){
            cout << matrix[i][j] << " ";
        }
    }
    return 0;
}