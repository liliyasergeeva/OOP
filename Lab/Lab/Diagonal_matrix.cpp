#include "Diagonal_matrix.h"

#include <iostream>

void Diagonal_matrix::In_Array(int N, ifstream& ifst) {
    Array = new int[N]; //Выделяем память для диагональной матрицы
    string Alph_num = "0123456789";
    string Temp_Str = "";

    for (int i = 0; i < N; i++) {
        ifst >> Temp_Str;

        if (ifst.peek() == EOF) {
            //Завершение программы с ошибкой
            cout << "Input data is incomplete!";
            exit(1);
        }

        //Если считанное числе - пустая строка
        if (Temp_Str == "") {
            //Завершение программы с ошибкой
            cout << "Input data is incomplete!";
            exit(1);
        }

        //Если число начинается с 0
        if ((Temp_Str[0] == '0') && (Temp_Str.length() > 1)) {
            //Завершение программы с ошибкой
            cout << "Input data is incorrect!";
            exit(1);
        }

        //Цикл проверки того, что строка содержит только цифры
        for (int i = 0; i < Temp_Str.length(); i++) {
            if (Alph_num.find(Temp_Str[i]) == -1) {
                //Завершение программы с ошибкой
                cout << "Input data is incorrect!";
                exit(1);
            }
        }

        Array[i] = atoi(Temp_Str.c_str());
    }

    ifst.get(); //После считывания элементов массива в файле остается символ конца строки, считываем его
}

void Diagonal_matrix::Out_Array(Key_out K_o, int N, ofstream& ofst) {
    ofst << "It's diagonal matrix with dimension = " << N << endl;

    int index = 0; //Индекс прохода по массиву

    if (K_o == BY_LINE) { //Вывод по строкам
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
    else if (K_o == BY_COLUMN) { //Вывод по столбцам
        int** Temp_matrix = new int* [N];

        for (int i = 0; i < N; i++) {
            Temp_matrix[i] = new int[N];
        }

        //Преобразование одномерного массива в двумерный - диагональную матрицу
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
    else if (K_o == ONE_DIMENSIONAL) { //Вывод в виде одномерного массива
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