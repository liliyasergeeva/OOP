#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"
#include "Triangular_matrix.h"

#include <iostream>
#include <string>

int Matrix::Get_N()
{
    return N;
}

Key_out Matrix::Get_K_o()
{
    return K_o;
}

Matrix* Matrix::In_Matrix(ifstream& ifst) {
    Matrix* M = NULL; //������� ��������� �� �������
    string Temp_Str = "";

    getline(ifst, Temp_Str);

    //�������� ����, ��� ���� ���� �������� ��������� ������������ ������,
    //���� �� �������� ��� �����
    if ((Temp_Str != "1") && (Temp_Str != "2") && (Temp_Str != "3")) {
        //�������� �������������� ���, ������ ��� ��� ����� ����
        if (ifst.peek() == EOF) {
            return 0;
        }
        else { //� ���� ������ ������������� ����������� �����, ���� �� ��������
            //���������� ��������� � �������
            cout << "Input data is incomplete or incorrect!";
            exit(1);
        }
    }

    int K = atoi(Temp_Str.c_str());

    if (K == 1) {
        M = new Two_dimensional_array; //������� ��������� ������
    }
    else if (K == 2)
    {
        M = new Diagonal_matrix; //������� ������������ �������
    }
    else if (K == 3)
    {
        M = new Triangular_matrix; //������� ����������� �������
    }

    getline(ifst, Temp_Str);

    if (ifst.peek() == EOF) {
        //���������� ��������� � �������
        cout << "Input data is incomplete!";
        exit(1);
    }

    if ((Temp_Str != "1") && (Temp_Str != "2") && (Temp_Str != "3")) {
        //���������� ��������� � �������
        cout << "Input data is incorrect!";
        exit(1);
    }

    int Key_out = atoi(Temp_Str.c_str());

    if (Key_out == 1) {
        M->K_o = BY_LINE;
    }
    else if (Key_out == 2) {
        M->K_o = BY_COLUMN;
    }
    else if (Key_out == 3) {
        M->K_o = ONE_DIMENSIONAL;
    }

    getline(ifst, Temp_Str);

    string Alph_num = "0123456789";

    //���� �������� ����, ��� ������ �������� ������ �����
    for (int i = 0; i < Temp_Str.length(); i++) {
        if (Alph_num.find(Temp_Str[i]) == -1) {
            //���������� ��������� � �������
            cout << "Input data is incorrect!";
            exit(1);
        }
    }

    M->N = atoi(Temp_Str.c_str()); //���������� ����������� �������

    M->In_Array(M->N, ifst); //��������� �������� �������

    return M;
}

bool Matrix::Compare(Matrix& Other)
{
    return Sum(N) > Other.Sum(Other.N);
}

void Matrix::Out_Only_Two_Dim(Key_out K_o, int N, ofstream& ofst) {
    ofst << endl;
}

void Matrix::Set_N(int _N)
{
    N = _N;
}

void Matrix::Set_K_o(Key_out _K_o)
{
    K_o = _K_o;
}