#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Keeper.h"
// #include "Books.h"
#include "Novel.h"
#include "Poet.h"
#include "Fantast.h"
// #include "Check.h"
using namespace std;

template <typename T>
void vybor_deystviya(T& obj, string line) {
	int c;
	int i;
	bool flag = true;
	setlocale(LC_ALL, "Russian");
	while (flag) {
		system("cls");
		cout << "Выберите действие: " << endl << endl;
		cout << "1 - Добавить объект" << endl;
		cout << "2 - Удалить объект" << endl;
		cout << "3 - Вывод объектов" << endl;
		cout << "4 - Изменить данные объектов" << endl;
		cout << "5 - Сохранить данные в файл" << endl;
		cout << "6 - Взять данные из файла" << endl;
		cout << "0 - Вернуться к выбору писаталей" << endl << endl;
		cout << "Выберите действие: ";
		cin >> c;
		if (cin.fail() || c < 0 || c > 7) {
			c = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (c) {
		case 1:
			obj.push();
			system("pause");
			break;
		case 2: obj.show();
			cout << "Выберите для удаления: ";
			cin >> i;
			obj.pop(i);
			system("pause");
			break;
		case 3:
			obj.show();
			system("pause");
			break;
		case 4:
			obj.show();
			cout << "Выберите для изменения: ";
			cin >> i;
			obj.edit(i);
			system("pause");
			break;
		case 5:
			obj.write(line);
			system("pause");
			break;
		case 6:
			obj.read(line);
			system("pause");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "Введите от 1 до 7:" << endl << endl;
			system("pause");
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Keeper <Novel> novel;
	Keeper <Poet> poet;
	Keeper <Fantastic> fantastic;
	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Меню: " << endl << endl;
		cout << "1 - Писатель романтист" << endl;
		cout << "2 - Поэт" << endl;
		cout << "3 - Писатель фантаст" << endl;
		cout << "0 - Завершение рабоыт программы" << endl << endl;
		cout << "Выберите пункт: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			vybor_deystviya(novel, "novel.txt");
			break;
		case 2:
			vybor_deystviya(poet, "poet.txt");
			break;
		case 3:
			vybor_deystviya(fantastic, "fantastic.txt");
			break;
		case 0:
			flag = false;
			cout << "\nЗавершение работы" << endl;
			break;
		default:
			cout << endl << "Введите другое число!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
	return 0;
}

