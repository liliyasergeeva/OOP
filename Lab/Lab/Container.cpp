#include "Container.h"

#include "Container.h"

Container::Container() : Len(0) {};

void Container::In_Container(ifstream& ifst) {
    while (!ifst.eof()) {
        if ((Cont[Len] = Matrix::In_Matrix(ifst))) {
            Len++;

            if (Len == Max_len) {
                break;
            }
        }
    }
}

void Container::Out_Container(ofstream& ofst) {
    ofst << "Container contents " << Len
        << " elements." << endl << endl;

    //ѕроверка заполнение контейнера до максимума
    if (Len == Max_len) {
        ofst << endl << "Conteiner is full (" << Max_len << " elemets)!" << endl <<
            "It can't accommodate more elements." << endl;
    }

    for (int i = 0; i < Len; i++) {
        ofst << i << ": ";

        if (Cont[i]->Get_N() == -1) {
            ofst << "Incorrect element!" << endl;
        }
        else {
            Cont[i]->Out_Array(Cont[i]->Get_K_o(), Cont[i]->Get_N(), ofst);

            ofst << "Sum of matrix elements = " << Cont[i]->Sum(Cont[i]->Get_N()) << endl << endl;
        }
    }
}

void Container::Clear_Container() {
    for (int i = 0; i < Len; i++) {
        delete Cont[i];
    }

    Len = 0;
}

void Container::Sort() {
    for (int i = 0; i < Len - 1; i++) {
        for (int j = i + 1; j < Len; j++) {
            if (Cont[i]->Get_N() != -1 && Cont[j]->Get_N() != -1) {
                if (Cont[i]->Compare((*Cont[j]))) {
                    Matrix* Temp = Cont[i];
                    Cont[i] = Cont[j];
                    Cont[j] = Temp;
                }
            }
        }
    }
}

void Container::Out_Only_Two_Dim(ofstream& ofst) {
    ofst << "Only Two Dimensional arrays." << endl << endl;

    for (int i = 0; i < Len; i++) {
        ofst << i << ": ";

        Cont[i]->Out_Only_Two_Dim(Cont[i]->Get_K_o(), Cont[i]->Get_N(), ofst);
    }
}