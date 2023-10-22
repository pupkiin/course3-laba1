#include <iostream>
//  clang++ main.cpp -o main
//  ./main
#include <fstream>
#include <vector>
// Класс Печатное издание хранит книги поэтов, романистов и фантастов. Для
// поэтом определено: ФИО, годы жизни, несколько основных произведений. Для
// романистов определено: ФИО, годы жизни, несколько произведений, краткая
// биография. Для фантастов определено: ФИО, несколько произведений, сняты
// ли фильмы по книгам.

using namespace std;

// создавать обьекты, записывать их в файл,
// при чтении из файла создавать обьект снова по заданным параметрам

#include "Keeper.h"

void showMenu1();
void showMenu2();

int main(void)
{
    setlocale(LC_ALL, "Russian");
    string name, surname, lastname, years, poetPros, romanPros, romanBio, fantPros, pos;
    bool fantFilms;
    int x = 0;
    int k = 0;

    Keeper tom("Tom", "pidor", "ebaniy");
    cout << tom.getSurname() << endl;

    while (true)
    {
        showMenu1();
        cout << "----------------" << endl;
        cout << "Кого выбираем?" << endl;
        cin >> x;

        if (x == 1) // поэты
        {
            showMenu2();
            cout << "----------------" << endl;
            cout << "Что делаем?" << endl;
            cin >> k;

            if (k == 1)
            { // добавляем
                cout << "----------------" << endl;
                cout << "Введите имя" << endl;
                cin >> name;
                cout << "Введите фамилию" << endl;
                cin >> surname;
                cout << "Введите отчество" << endl;
                cin >> lastname;
                pos = "Поэт";

                Keeper human(name, surname, lastname);
                fstream fs;
                fs.open("text.txt", ios::app);

                fs << human.getName() + ' ' + human.getSurname() + ' ' + human.getLastname() << endl;
                fs.close();
            }

            if (k == 2) {

            }

            if (k == 3) {
                
            }

            if (k == 0) {
                break;
            }
        }

        if (x == 0) {
            break;
        }
    }
}

void showMenu1()
{
    cout << "----------------" << endl;
    cout << "1 - Поэт" << endl;
    cout << "2 - Романист" << endl;
    cout << "3 - Фантаст" << endl;
    cout << "4 - Выход" << endl;
    cout << "----------------" << endl;
}

void showMenu2()
{
    cout << "----------------" << endl;
    cout << "1 - добавить" << endl;
    cout << "2 - удалить" << endl;
    cout << "3 - вывести список" << endl;
    cout << "0 - выход" << endl;
    cout << "----------------" << endl;
}
