#include "Triangular_matrix.h"

void Triangular_matrix::In_Array(int N, ifstream& ifst)
{
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N != 0)
    {
        Array_size += Temp_N;
        Temp_N--;
    }

    Array = new int[Array_size];
    for (int i = 0; i < Array_size; i++)
    {
        ifst >> Array[i];
    }
}

void Triangular_matrix::Out_Array(int N, ofstream& ofst)
{
    ofst << "It's triangular matrix with dimension = " << N << endl;

    int index = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i >= j)
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

int Triangular_matrix::Sum(int N) {
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N) {
        Array_size += Temp_N;
        Temp_N--;
    }

    int Sum = 0;

    for (int i = 0; i < Array_size; i++) {
        Sum += Array[i];
    }

    return Sum;
}