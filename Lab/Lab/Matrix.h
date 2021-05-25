#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

using namespace std;

//Способ вывода матрицы
enum Key_out {
	BY_LINE, //По строкам
	BY_COLUMN, //По столбцам
	ONE_DIMENSIONAL //В виде одномерного массива
};

class Matrix {
	int N;
	Key_out K_o;
public:
	static Matrix* In_Matrix(ifstream& ifst); //Функция ввода матрицы
	virtual void In_Array(int N, ifstream& ifst) = 0; //Чисто вирутальная функция ввода матрицы,
                                              //она будет определена каждого класса массива
	virtual void Out_Array(Key_out K_o, int N, ofstream& ofst) = 0; //Чисто вирутальная функция вывода матрицы,
                                              //она будет определена каждого класса массива
	int Get_N(); //Функция получения размерности массива (общее значение)
	virtual int Sum(int N) = 0;
	Key_out Get_K_o(); //Функция получения способа вывода матрицы
	virtual void Out_Only_Two_Dim(Key_out K_o, int N, ofstream& ofst); //Функция вывода только обычного двумерного массива
	bool Compare(Matrix& Other);
protected:
	Matrix() {};
};

#endif //MATRIX_H