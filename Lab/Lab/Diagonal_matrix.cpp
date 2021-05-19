#include "Diagonal_matrix.h"

void Diagonal_matrix::In_Array(int N, ifstream& ifst)
{
    Array = new int[N]; //Выделяем память для диагональной матрицы

    for (int i = 0; i < N; i++)
    {
        ifst >> Array[i]; //Записываем новый элемент в матрицу
    }
}

void Diagonal_matrix::Out_Array(Key_out K_o, int N, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //Выводим размерность матрицы

    int index = 0;

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << Array[index] << " ";
                    index++;
                }
                else
                {
                    ofst << 0 << " ";
                }
            }

            ofst << endl;
        }
    }
    else if (K_o == BY_COLUMN)
    {
        int** temp_matrix = new int* [N];

        for (int i = 0; i < N; i++)
        {
            temp_matrix[i] = new int[N];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    temp_matrix[i][j] = Array[index];
                    index++;
                }
                else
                {
                    temp_matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << temp_matrix[j][i] << " ";
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
                if (i == j)
                {
                    ofst << Array[index] << " ";
                    index++;
                }
                else
                {
                    ofst << 0 << " ";
                }
            }
        }

        ofst << endl;
    }
}