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
    ofstream ofst(argv[2]);

    cout << "Start" << endl;

    Container C; //Объявляем новый контейнер

    C.In_Container(ifst); //Записываем элементы в контейнер

    ofst << "Filled container. " << endl;

    C.Sort(); //Сортировка контейнера

    C.Out_Container(ofst); //Вывод контейнера

    C.Clear_Container();//Очистка контейнера

    ofst << "Empty container. " << endl;

    C.Out_Container(ofst); //Вывод контейнера

    cout << "Stop" << endl;
    system("pause");
    return 0;
}