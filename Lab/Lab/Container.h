#ifndef CONTAINER_H
#define CONTAINER_H

#include "Matrix.h"

class Container {
    enum {
        Max_len = 100
    }; // Максимальная длина контейнера

    int Len; // Текущая длина
    Matrix* Cont[Max_len]; //Массив матриц
public:
    void In_Container(ifstream& ifst); //Функция ввода элементов в контейнер
    void Out_Container(ofstream& ofst); //Функция вывода элементов контейнера
    void Clear_Container(); //Функция очистки контейнера
    void Sort(); //Функция сортировки контейнера
    Container(); //Конструктор
    ~Container() { Clear_Container(); } //Деструктор контейнера
};
#endif //CONTAINER_H