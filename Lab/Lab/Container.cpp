#include "Container.h"

Container::Container() : Len(0) {};

void Container::In_Container(ifstream& ifst) 
{
    while (!ifst.eof()) 
    {
        if ((Cont[Len] = Matrix::In_Matrix(ifst)) != 0) //Считываем очередную матрицу
        {
            Len++;

            if (Len == Max_len) //Проверка на переполнение контейнера
            {
                break;
            }
        }
    }
}

void Container::Out_Container(ofstream& ofst) {
    ofst << "Container contents " << Len
        << " elements." << endl; //Выводим число элементов массива

    //Проверка на переполнение
    if (Len == Max_len)
    {
        ofst << endl << "Conteiner is full (" << Max_len << " elemets)!" << endl <<
            "It can't accommodate more elements." << endl;
    }

    //Выводим номера матриц и сами эти матрицы
    for (int i = 0; i < Len; i++) 
    {
        ofst << i << ": ";
        Cont[i]->Out_Array(Cont[i]->Get_K_o(), Cont[i]->Get_N(), ofst);

        ofst << "Sum of matrix elements = " << Cont[i]->Sum(Cont[i]->Get_N()) << endl;
    }
}

void Container::Clear_Container() 
{
    for (int i = 0; i < Len; i++) 
    {
        delete Cont[i]; //Очищаем память, вылеленную для каждой матрицы
    }
    
    Len = 0;
}

void Container::Sort() {
    if (Len > 1)
    {
        for (int i = 0; i < Len - 1; i++) 
        { 
            for (int j = i + 1; j < Len; j++) 
            { 
                if (Cont[i]->Compare((*Cont[j]))) 
                { 
                    Matrix* Temp = Cont[i]; 
                    Cont[i] = Cont[j]; 
                    Cont[j] = Temp; 
                } 
            } 
        }
    }
}