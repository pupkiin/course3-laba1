#include <iostream>
//  clang++ main.cpp -o main
//  ./main
#include <fstream>
#include <vector>
#include <string>
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

    while (true)
    {
        showMenu1();
        cout << "----------------" << endl;
        cout << "Кого выбираем?" << endl;
        cin >> x;
        cout << "----------------" << endl;

        if (x == 1) // поэты
        {
            showMenu2();
            cout << "----------------" << endl;
            cout << "Что делаем?" << endl;
            cin >> k;
            cout << "----------------" << endl;

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

                Keeper human("Poet", name, surname, lastname, "");
                fstream fs;
                fs.open("text.txt", ios::app);

                fs << human.getPos() + ' ' + human.getName() + ' ' + human.getSurname() + ' ' + human.getLastname() << endl;
                fs.close();
            }

            if (k == 2)
            { // удаление
                fstream fs;
                fs.open("text.txt", ios::in);
                string line;
                int count = 0;
                if (fs.is_open())
                {
                    while (getline(fs, line))
                    {
                        count += 1;
                    }
                }
                fs.close();
                cout << count << endl;
            }

            if (k == 3)
            { // вывод
                fstream fs;
                fs.open("text.txt", ios::in);
                string line;
                int count = 0;
                if (fs.is_open())
                {
                    while (getline(fs, line))
                    {
                        count += 1;
                        string softStr;
                        for (int i = 0; i < 4; i++)
                        {
                            softStr += line[i];
                        }
                        if (softStr == "Poet")
                        {
                            cout << line << endl;
                        }
                        softStr = "";
                    }
                }
                fs.close();
            }

            if (k == 0)
            {
                break;
            }
        }

        if (x == 4)
        {
            cout << "Полный список авторов" << endl
                 << endl;
            fstream fs;
            fs.open("text.txt", ios::in);
            string line;
            if (fs.is_open())
            {
                while (getline(fs, line))
                {
                    cout << line << endl;
                }
            }
            fs.close();
        }

        if (x == 0)
        {
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
    cout << "4 - Вывести список" << endl;
    cout << "0 - Выход" << endl;
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
