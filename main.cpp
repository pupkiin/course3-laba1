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

#include "Keeper.h"

void showMenu1();
void showMenu2();

int main(void)
{
    setlocale(LC_ALL, "Russian");
    string name, surname, lastname, years, poetPros, romanPros, romanBio, fantPros, pos;
    string fantFilms;
    int x = 0;
    int k = 0;
    string line;

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
                cout << "Введите годы жизни" << endl;
                cin >> years;
                cout << "Введите несколько произведений(через запятую)" << endl;
                string s;
                getline(cin, s); // холостой вызов
                getline(cin, poetPros);

                pos = "Poet";

                Keeper human(pos, name, surname, lastname, years, poetPros, "", "", "", "");
                fstream fs;
                fs.open("text.txt", ios::app);

                fs << human.getPos() + ' ' + human.getName() + ' ' + human.getSurname() + ' ' + human.getLastname() + ' ' + human.getYears() + ' ' + '[' + "Произведения: " + human.getPoetPros() + ']' << endl;
                fs.close();
            }

            if (k == 2)
            { // удаление
                int numberDelete;
                string returnStr;
                cout << "Введите номер элемента" << endl;
                cin >> numberDelete;
                fstream fs;
                fstream change;
                fs.open("text.txt", ios::in);
                change.open("change.txt", ios::out);
                string line;
                int count = 0;
                if (fs.is_open() && change.is_open())
                {
                    while (getline(fs, line))
                    {
                        count += 1;
                        if (count != numberDelete)
                        {
                            change << line << endl;
                        }
                        else
                        {
                            returnStr = line;
                        }
                    }
                }
                fs.close();
                change.close();

                fs.open("text.txt", ios::out);
                change.open("change.txt", ios::in);
                if (fs.is_open() && change.is_open())
                {
                    while (getline(change, line))
                    {
                        fs << line << endl;
                    }
                }
                fs.close();
                change.close();
                cout << "Вы удалили" << endl;
                cout << "> " << returnStr << endl;
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
                            int spaceCount = 0;
                            int symbolCount = 0;
                            for (int j = 0; j < line.length(); j++) {
                                if (line[j] == ' ' && spaceCount == 4) {
                                    cout << count << " ";
                                    for (int s = 0; s < j; s++) {
                                        cout << line[s];
                                    }
                                    cout << endl;
                                    for (int s = j; s < line.length(); s++) {
                                        cout << line[s];
                                    }
                                    cout << endl << endl;
                                    spaceCount += 1;
                                } else {
                                    if (line[j] == ' ') {
                                        spaceCount += 1;
                                    }
                                }
                            }
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

        if (x == 2) // романисты
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
                cout << "Введите годы жизни" << endl;
                cin >> years;
                cout << "Введите несколько произведений(через запятую)" << endl;
                string s;
                getline(cin, s); // холостой вызов
                getline(cin, romanPros);
                cout << "Введите краткую биографию" << endl;
                getline(cin, romanBio);

                pos = "Romanist";

                Keeper human(pos, name, surname, lastname, years, "", romanPros, romanBio, "", "");
                fstream fs;
                fs.open("text.txt", ios::app);

                fs << human.getPos() + ' ' + human.getName() + ' ' + human.getSurname() + ' ' + human.getLastname() + ' ' + human.getYears() + ' ' + '[' + "Произведения: " + human.getRomanPros() + ']' + ' ' + '[' + "Биография: " + human.getRomanBio() + ']' << endl;
                fs.close();
            }

            if (k == 2)
            { // удаление
                int numberDelete;
                string returnStr;
                cout << "Введите номер элемента" << endl;
                cin >> numberDelete;
                fstream fs;
                fstream change;
                fs.open("text.txt", ios::in);
                change.open("change.txt", ios::out);
                string line;
                int count = 0;
                if (fs.is_open() && change.is_open())
                {
                    while (getline(fs, line))
                    {
                        count += 1;
                        if (count != numberDelete)
                        {
                            change << line << endl;
                        }
                        else
                        {
                            returnStr = line;
                        }
                    }
                }
                fs.close();
                change.close();

                fs.open("text.txt", ios::out);
                change.open("change.txt", ios::in);
                if (fs.is_open() && change.is_open())
                {
                    while (getline(change, line))
                    {
                        fs << line << endl;
                    }
                }
                fs.close();
                change.close();
                cout << "Вы удалили" << endl;
                cout << "> " << returnStr << endl;
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
                        for (int i = 0; i < 8; i++)
                        {
                            softStr += line[i];
                        }
                        if (softStr == "Romanist")
                        {
                            int spaceCount = 0;
                            int symbolCount = 0;
                            for (int j = 0; j < line.length(); j++) {
                                if (line[j] == ' ' && spaceCount == 4) {
                                    cout << count << " ";
                                    for (int s = 0; s < j; s++) {
                                        cout << line[s];
                                    }
                                    cout << endl;
                                    for (int s = j; s < line.length(); s++) {
                                        cout << line[s];
                                    }
                                    cout << endl << endl;
                                    spaceCount += 1;
                                } else {
                                    if (line[j] == ' ') {
                                        spaceCount += 1;
                                    }
                                }
                            }
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

        if (x == 3) // фантасты
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
                cout << "Введите несколько произведений(через запятую)" << endl;
                string s;
                getline(cin, s); // холостой вызов
                getline(cin, fantPros);
                cout << "Сняты ли фильмы по книгам (Да/Нет)" << endl;
                getline(cin, fantFilms);

                pos = "Fantast";

                Keeper human(pos, name, surname, lastname, "", "", "", "", fantPros, fantFilms);
                fstream fs;
                fs.open("text.txt", ios::app);

                fs << human.getPos() + ' ' + human.getName() + ' ' + human.getSurname() + ' ' + human.getLastname() + ' ' + '[' + "Произведения: " + human.getFantPros() + ']' + '[' + "Сняты ли фильмы по книгам: " + human.getFantFilms() + ']' << endl;
                fs.close();
            }

            if (k == 2)
            { // удаление
                int numberDelete;
                string returnStr;
                cout << "Введите номер элемента" << endl;
                cin >> numberDelete;
                fstream fs;
                fstream change;
                fs.open("text.txt", ios::in);
                change.open("change.txt", ios::out);
                string line;
                int count = 0;
                if (fs.is_open() && change.is_open())
                {
                    while (getline(fs, line))
                    {
                        count += 1;
                        if (count != numberDelete)
                        {
                            change << line << endl;
                        }
                        else
                        {
                            returnStr = line;
                        }
                    }
                }
                fs.close();
                change.close();

                fs.open("text.txt", ios::out);
                change.open("change.txt", ios::in);
                if (fs.is_open() && change.is_open())
                {
                    while (getline(change, line))
                    {
                        fs << line << endl;
                    }
                }
                fs.close();
                change.close();
                cout << "Вы удалили" << endl;
                cout << "> " << returnStr << endl;
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
                        for (int i = 0; i < 7; i++)
                        {
                            softStr += line[i];
                        }
                        if (softStr == "Fantast")
                        {
                            int spaceCount = 0;
                            int symbolCount = 0;
                            for (int j = 0; j < line.length(); j++) {
                                if (line[j] == ' ' && spaceCount == 3) {
                                    cout << count << " ";
                                    for (int s = 0; s < j; s++) {
                                        cout << line[s];
                                    }
                                    cout << endl;
                                    for (int s = j; s < line.length(); s++) {
                                        cout << line[s];
                                    }
                                    cout << endl << endl;
                                    spaceCount += 1;
                                } else {
                                    if (line[j] == ' ') {
                                        spaceCount += 1;
                                    }
                                }
                            }
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
            int count = 0;
            if (fs.is_open())
            {
                while (getline(fs, line))
                {
                    count += 1;
                    int spaceCount = 0;
                    int symbolCount = 0;
                    for (int j = 0; j < line.length(); j++) {
                        if (line[j] == ' ' && spaceCount == 3) {
                            cout << count << " ";
                            for (int s = 0; s < j; s++) {
                                cout << line[s];
                            }
                            cout << endl;
                            for (int s = j; s < line.length(); s++) {
                                cout << line[s];
                            }
                            cout << endl << endl;
                            spaceCount += 1;
                        } else {
                            if (line[j] == ' ') {
                                spaceCount += 1;
                            }
                        }
                    }
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
