#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

int Matrix::Get_N()
{
    return N;
}

Matrix* Matrix::In_Matrix(ifstream& ifst) {
    Matrix* M; //Создаем указатель на матрицу
    int K;

    ifst >> K; //Считываем идентификатор матрицы

    if (K == 1)
    {
        M = new Two_dimensional_array; //Создаем двумерный массив

        ifst >> M->N; //Cчитываем размерность массива
    }
    else if (K == 2)
    {
        M = new Diagonal_matrix; //Создаем диагональную матрицу

        ifst >> M->N; //Cчитываем размерность массива
    }
    else
    {
        return 0;
    }

    M->In_Array(M->N, ifst); //Считываем элементы матрицы
    
    return M;
}

bool Matrix::Compare(Matrix& Other)
{
    return Sum(N) > Other.Sum(Other.N);
}