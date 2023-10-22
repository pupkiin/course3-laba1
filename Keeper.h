#include <iostream>

using namespace std;

class Keeper
{
private:
    string _pos;
    string _name;
    string _surname;
    string _lastname;
    string _years;
    string _poetPros;
    string _romanPros;
    string _romanBio;
    string _fantPros;
    string _fantFilms;

public:
    Keeper(string pos, string name, string surname, string lastname, string years,
           string poetPros, string romanPros, string romanBio, string fantPros, string fantFilms)
    {
        _pos = pos;
        _name = name;
        _surname = surname;
        _lastname = lastname;
        _years = years;
        _poetPros = poetPros;
        _romanPros = romanPros;
        _romanBio = romanBio;
        _fantPros = fantPros;
        _fantFilms = fantFilms;
    }

    void setPos(string pos)
    {
        this->_pos = pos;
    }

    void setName(string name)
    {
        this->_name = name;
    }

    void setSurname(string surname)
    {
        this->_surname = surname;
    }

    void setLastname(string lastname)
    {
        this->_lastname = lastname;
    }

    void setYears(string years)
    {
        this->_years = years;
    }

    void setPoetPros(string poetPros)
    {
        this->_poetPros = poetPros;
    }

    void setRomanPros(string romanPros)
    {
        this->_romanPros = romanPros;
    }

    void setRomanBio(string romanBio)
    {
        this->_romanBio = romanBio;
    }

    void setFantPros(string fantPros)
    {
        this->_fantPros = fantPros;
    }

    void setFantFilms(string fantFilms)
    {
        this->_fantFilms = fantFilms;
    }

    string getPos()
    {
        return _pos;
    }

    string getName()
    {
        return _name;
    }

    string getSurname()
    {
        return _surname;
    }

    string getLastname()
    {
        return _lastname;
    }

    string getYears()
    {
        return _years;
    }

    string getPoetPros()
    {
        return _poetPros;
    }

    string getRomanPros()
    {
        return _romanPros;
    }

    string getRomanBio()
    {
        return _romanBio;
    }

    string getFantPros()
    {
        return _fantPros;
    }

    string getFantFilms()
    {
        return _fantFilms;
    }
};