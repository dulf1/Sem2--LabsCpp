#ifndef SECONDSEMOPTASK1_COMANDS_H
#define SECONDSEMOPTASK1_COMANDS_H

void increaseByValuePointer(int* variable, int value);
void increaseByValueReference(int& variable, int value);
void changeSignPointer(float* variable);
void changeSignReference(float& variable);
void multiplicationMatrixPointer(float (*matrix)[3][3], float value);
void multiplicationMatrixReference(float (&matrix)[3][3], float value);
void changeSignPointer(int* variable);
void changeSignReference(int& variable);

#endif
