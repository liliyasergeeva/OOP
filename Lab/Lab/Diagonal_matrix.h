#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <fstream>

#include "Matrix.h"

using namespace std;

class Diagonal_matrix: public Matrix {
	int* Array; //Массива
public:
	int* Get_Array();
	void Set_Array(int* _Array);

	void In_Array(int N, ifstream& ifst); //Функция ввода массива
	void Out_Array(Key_out K_o, int N, ofstream& ofst); //Функция вывода массива
	int Sum(int N); //Функция подсчет суммы элементов матрицы
	Diagonal_matrix() {};
};

#endif //DIAGONAL_MATRIX_H