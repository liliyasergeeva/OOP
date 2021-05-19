#ifndef TWO_DIMENSIONAL_ARRAY_H
#define TWO_DIMENSIONAL_ARRAY_H

#include <fstream>

#include "Matrix.h"

using namespace std;

class Two_dimensional_array: public Matrix {
	int** Array; //Массив
public:
	void In_Array(int N, ifstream& ifst);  //Функция ввода массива
	void Out_Array(int N, ofstream& ofst); //Функция вывода массива
	int Sum(int N); //Функция подсчет суммы элементов матрицы
	Two_dimensional_array() {};
};
#endif //TWO_DIMENSIONAL_ARRAY_H