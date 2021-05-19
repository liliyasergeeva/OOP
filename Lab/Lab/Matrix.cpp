#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

int Matrix::Get_N()
{
    return N;
}

Key_out Matrix::Get_K_o()
{
    return K_o;
}

Matrix* Matrix::In_Matrix(ifstream& ifst) {
    Matrix* M; //Создаем указатель на матрицу
    int K;

    ifst >> K; //Считываем идентификатор матрицы

    if (K == 1)
    {
        M = new Two_dimensional_array; //Создаем двумерный массив

        int Key_out = 0;

        ifst >> Key_out;

        if (Key_out == 1)
        {
            M->K_o= BY_LINE;
        }
        else if (Key_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (Key_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //Cчитываем размерность массива
    }
    else if (K == 2)
    {
        M = new Diagonal_matrix; //Создаем диагональную матрицу

        int Key_out = 0;

        ifst >> Key_out;

        if (Key_out == 1)
        {
            M->K_o = BY_LINE;
        }
        else if (Key_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (Key_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //Cчитываем размерность массива
    }
    else
    {
        return 0;
    }

    M->In_Array(M->N, ifst); //Считываем элементы матрицы
    
    return M;
}