#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H

#include "Matrix.h"
#include <fstream>

using namespace std;

class Triangular_matrix : public Matrix {
    int* Array; //Массив
public:
    void In_Array(int N, ifstream& ifst); //Функция ввода массива
    void Out_Array(Key_out K_o, int N, ofstream& ofst); //Функция вывода массива
    int Sum(int N); //Функция подсчет суммы элементов матрицы
    Triangular_matrix() {};
};

#endif // TRIANGULAR_MATRIX_H
