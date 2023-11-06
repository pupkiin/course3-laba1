#include "Fantast.h"
#include <iostream>
#include <string>
using namespace std;

Fantastic::Fantastic() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Fantastic" << endl << endl;
	fio = "";
	live = "";
	works = "";
	films = "";
}

Fantastic::Fantastic(const Fantastic& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Fantastic" << endl << endl;
	*this = other;
}

Fantastic::~Fantastic() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Fantastic" << endl << endl;
}

void Fantastic::p() {
	cin >> *this;
}

Fantastic& Fantastic::operator=(const Fantastic& other) {
	this->fio = other.fio;
	this->live = other.live;
	this->works = other.works;
	this->films = other.films;
	return *this;
}

ofstream& operator<<(ofstream& fout, Fantastic& obj) {
	fout << obj.fio << " " << endl;
	fout << obj.live << " " << endl;
	fout << obj.works << " " << endl;
	fout << obj.films << " " << endl;
	fout << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Fantastic& obj) {
	fin >> obj.fio >> obj.live >> obj.works >> obj.films;
	return fin;
}

ostream& operator<<(ostream& out, Fantastic& obj) {
	setlocale(LC_ALL, "Russian");
	out << "ФИО писателя фантаста: " << obj.fio << endl;
	out << "Годы жизни: " << obj.live << endl;
	out << "Произведения: " << obj.works << endl;
	out << "Краткая биография: " << obj.films << endl;
	return out;
}

istream& operator>>(istream& in, Fantastic& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "ФИО писателя фантаста: ";
	getchar();
	getline(cin, obj.fio);
	cout << "Годы жизни: ";
	cin >> obj.live;
	cout << "Произведения: ";
	getchar();
	getline(cin, obj.works);
	cout << "Сняты ли по книгам фильмы: ";
	getchar();
	getline(cin, obj.films);
	return in;
}
