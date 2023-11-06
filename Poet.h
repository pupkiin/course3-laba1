// #pragma once
#include <fstream>
#include "Books.h"
// #include "Keeper.h"
using namespace std;

class Poet : public Books {
private:
	string fio;      //ФИО
	string live;     //Годы жизни
	string works;    //Произведения
public:
	Poet();
	~Poet();
	Poet(const Poet&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Poet& obj);
	friend ifstream& operator >> (ifstream& fin, Poet& obj);
	friend ostream& operator << (ostream& out, Poet& obj);
	friend istream& operator >> (istream& in, Poet& obj);
	Poet& operator =(const Poet& other);
};
