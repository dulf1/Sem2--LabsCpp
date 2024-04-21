#include <iostream>
#include "comands.h"

void increaseByValuePointer(int *variable, int value) {
    *variable += value;
}

void increaseByValueReference(int &variable, int value) {
    variable += value;
}

void changeSignPointer(float *variable) {
    *variable = -(*variable);
}

void changeSignReference(float &variable) {
    variable = -variable;
}

void multiplicationMatrixPointer(float (*matrix)[3][3], float value) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            (*matrix)[i][j] *= value;
        }
    }
}

void multiplicationMatrixReference(float (&matrix)[3][3], float value) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] *= value;
        }
    }
}

void changeSignPointer(int *variable) {
    *variable = -(*variable);
}

void changeSignReference(int &variable) {
    variable = -variable;
}
