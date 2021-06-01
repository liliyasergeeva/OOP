#include <iostream>
#include "Container.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);

    if (!ifst.is_open())
    {
        cout << "No input file found or could not open!" << endl;
        system("pause");
        return 1;
    }

    ofstream ofst(argv[2]);

    if (!ofst.is_open())
    {
        cout << "No output file found or could not open!" << endl;
        system("pause");
        return 1;
    }

    cout << "Start" << endl;

    Container C; //Объявляем новый контейнер

    C.In_Container(ifst); //Записываем элементы в контейнер

    ofst << "Filled and sorted container. " << endl;

    C.Sort(); //Сортировка контейнера

    C.Out_Container(ofst); //Вывод контейнера

    C.Out_Only_Two_Dim(ofst); //Вывод только обычного двумерного массива

    C.Clear_Container();//Очистка контейнера

    ofst << "Empty container. " << endl;

    C.Out_Container(ofst); //Вывод контейнера

    cout << "Stop" << endl;
    system("pause");
    return 0;
}