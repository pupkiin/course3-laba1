// #pragma once
#include <fstream>
#include "Books.h"
// #include "Keeper.h"
// #include <iostream>
using namespace std;

class Fantastic : public Books {
private:
	string fio;      //ФИО
	string live;     //Годы жизни
	string works;    //Произведения
	string films;    //Сняты ли фильмы по книгам
public:
	Fantastic();
	~Fantastic();
	Fantastic(const Fantastic&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Fantastic& obj);
	friend ifstream& operator >> (ifstream& fin, Fantastic& obj);
	friend ostream& operator << (ostream& out, Fantastic& obj);
	friend istream& operator >> (istream& in, Fantastic& obj);
	Fantastic& operator =(const Fantastic& other);
};

