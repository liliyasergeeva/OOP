#include "Diagonal_matrix.h"

void Diagonal_matrix::In_Array(int N, ifstream& ifst)
{
    Array = new int[N]; //Выделяем память для диагональной матрицы

    for (int i = 0; i < N; i++)
    {
        ifst >> Array[i]; //Записываем новый элемент в матрицу
    }
}

void Diagonal_matrix::Out_Array(int N, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //Выводим размерность матрицы

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                ofst << Array[i] << " "; //Выводим элемент матрицы; (i == j) -> только по диагонали
            }
            else
            {
                ofst << "0 "; //(i != j) -> не диагональ, выводим нули
            }
        }

        ofst << endl;
    }
}