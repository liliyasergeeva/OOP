#include "Diagonal_matrix.h"

#include <iostream>

void Diagonal_matrix::In_Array(int N, ifstream& ifst) {
    Array = new int[N]; //�������� ������ ��� ������������ �������
    string Alph_num = "0123456789";
    string Temp_Str = "";

    for (int i = 0; i < N; i++) {
        ifst >> Temp_Str;

        if (ifst.peek() == EOF) {
            //���������� ��������� � �������
            cout << "Input data is incomplete!";
            exit(1);
        }

        //���� ��������� ����� - ������ ������
        if (Temp_Str == "") {
            //���������� ��������� � �������
            cout << "Input data is incomplete!";
            exit(1);
        }

        //���� ����� ���������� � 0
        if ((Temp_Str[0] == '0') && (Temp_Str.length() > 1)) {
            //���������� ��������� � �������
            cout << "Input data is incorrect!";
            exit(1);
        }

        //���� �������� ����, ��� ������ �������� ������ �����
        for (int i = 0; i < Temp_Str.length(); i++) {
            if (Alph_num.find(Temp_Str[i]) == -1) {
                //���������� ��������� � �������
                cout << "Input data is incorrect!";
                exit(1);
            }
        }

        Array[i] = atoi(Temp_Str.c_str());
    }

    ifst.get(); //����� ���������� ��������� ������� � ����� �������� ������ ����� ������, ��������� ���
}

void Diagonal_matrix::Out_Array(Key_out K_o, int N, ofstream& ofst) {
    ofst << "It's diagonal matrix with dimension = " << N << endl;

    int index = 0; //������ ������� �� �������

    if (K_o == BY_LINE) { //����� �� �������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    ofst << Array[index] << " ";
                    index++;
                }
                else {
                    ofst << 0 << " ";
                }
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == BY_COLUMN) { //����� �� ��������
        int** Temp_matrix = new int* [N];

        for (int i = 0; i < N; i++) {
            Temp_matrix[i] = new int[N];
        }

        //�������������� ����������� ������� � ��������� - ������������ �������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    Temp_matrix[i][j] = Array[index];
                    index++;
                }
                else {
                    Temp_matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << Temp_matrix[j][i] << " ";
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == ONE_DIMENSIONAL) { //����� � ���� ����������� �������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    ofst << Array[index] << " ";
                    index++;
                }
                else {
                    ofst << 0 << " ";
                }
            }
        }

        ofst << endl;
    }
}

int Diagonal_matrix::Sum(int N) {
    int Sum = 0;

    for (int i = 0; i < N; i++) {
        Sum += Array[i];
    }

    return Sum;
}

int* Diagonal_matrix::Get_Array()
{
    return Array;
}

void Diagonal_matrix::Set_Array(int* _Array)
{
    Array = _Array;
}