#include "Poet.h"
#include <iostream>
#include <string>
using namespace std;

Poet::Poet() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Poet" << endl << endl;
	fio = "";
	live = "";
	works = "";
}

Poet::Poet(const Poet& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Poet" << endl << endl;
	*this = other;
}

Poet::~Poet() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Poet" << endl << endl;
}

void Poet::p() {
	cin >> *this;
}

Poet& Poet::operator=(const Poet& other) {
	this->fio = other.fio;
	this->live = other.live;
	this->works = other.works;
	return *this;
}

ofstream& operator<<(ofstream& fout, Poet& obj) {
	fout << obj.fio << " " << endl;
	fout << obj.live << " " << endl;
	fout << obj.works << " " << endl;
	fout << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Poet& obj) {
	fin >> obj.fio >> obj.live >> obj.works;
	return fin;
}

ostream& operator<<(ostream& out, Poet& obj) {
	setlocale(LC_ALL, "Russian");
	out << "ФИО поэта: " << obj.fio << endl;
	out << "Годы жизни: " << obj.live << endl;
	out << "Произведения: " << obj.works << endl;
	return out;
}

istream& operator>>(istream& in, Poet& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "ФИО поэта: ";
	getchar();
	getline(cin, obj.fio);
	cout << "Годы жизни: ";
	cin >> obj.live;
	cout << "Произведения: ";
	getchar();
	getline(cin, obj.works);
	return in;
}
