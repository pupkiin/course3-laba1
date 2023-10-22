#include <iostream>

using namespace std;

class Keeper
{
private:
    string _name;
    string _surname;
    string _lastname;

public:
    Keeper(string name, string surname, string lastname)
    {   
        _name = name;
        _surname = surname;
        _lastname = lastname;
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