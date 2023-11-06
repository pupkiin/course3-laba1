// #pragma once
#include <fstream>
#include "Books.h"
// #include "Keeper.h"
using namespace std;

class Novel : public Books {
private:
	string fio;      //ФИО
	string live;     //Годы жизни
	string works;    //Произведения
	string bio;      //Кратка биография
public:
	Novel();
	~Novel();
	Novel(const Novel&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Novel& obj);
	friend ifstream& operator >> (ifstream& fin, Novel& obj);
	friend ostream& operator << (ostream& out, Novel& obj);
	friend istream& operator >> (istream& in, Novel& obj);
	Novel& operator =(const Novel& other);
};
