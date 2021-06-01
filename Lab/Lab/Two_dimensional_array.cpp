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

void Two_dimensional_array::Out_Array(Key_out K_o, int N, ofstream& ofst)
{
    ofst << "It's two dimensional matrix with dimension = " << N << endl; //Выводим размерность массива

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << Array[i][j] << " ";
            }
            ofst << endl;
        }
    }
    else if (K_o == BY_COLUMN)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << Array[j][i] << " ";
            }
            ofst << endl;
        }
    }
    else if (K_o == ONE_DIMENSIONAL)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << Array[j][i] << " ";
            }
        }

        ofst << endl;
    }
}

int Two_dimensional_array::Sum(int N) {
    int Sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Sum += Array[i][j];
        }
    }

    return Sum;
}

void Two_dimensional_array::Out_Only_Two_Dim(Key_out K_o, int N, ofstream& ofst) {
    Out_Array(K_o, N, ofst);
}

int** Two_dimensional_array::Get_Array()
{
    return Array;
}
void Two_dimensional_array::Set_Array(int** _Array)
{
    Array = _Array;
}