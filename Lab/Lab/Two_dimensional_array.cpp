#include "Two_dimensional_array.h"

void Two_dimensional_array::In_Array(int N, ifstream& ifst)
{
    Array = new int* [N]; //Выделение памяти под массив

    for (int i = 0; i < N; i++)
    {
        Array[i] = new int[N]; //Выделение памяти под массив
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ifst >> Array[i][j]; //Ввод элемента массива
        }
    }
}

void Two_dimensional_array::Out_Array(int N, ofstream& ofst)
{
    ofst << "It's two dimensional matrix with dimension = " << N << endl; //Выводим размерность массива

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ofst << Array[i][j] << " "; //Выводим элементы массива
        }

        ofst << endl;
    }
}

void Two_dimensional_array::Out_Only_Two_Dim(int N, ofstream& ofst) {
    Out_Array(N, ofst);
}