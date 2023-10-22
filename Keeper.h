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

public:
    Keeper(string pos, string name, string surname, string lastname, string years)
    {   
        _pos = pos;
        _name = name;
        _surname = surname;
        _lastname = lastname;
        _years = years;
    }

    void setPos(string pos) {
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

    string getPos() {
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
};