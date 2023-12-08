#ifndef RUTA_H
#define RUTA_H
#include <iostream>
#include <string>
using namespace std;

class Ruta
{

private:
    string nume;
    string plecare;
    string sosire;
    string data;
    string oraPlecare;
    string oraSosire;
    string locuri;

public:
    Ruta();

    void setNume(string nume);

    void setPlecare(string plecare);

    void setSosire(string sosire);

    void setData(string data);

    void setOraPlecare(string ora);

    void setOraSosire(string ora);

    void setLocuri(int locuri);

    string getNume();

    string getPlecare();

    string getSosire();

    string getData();

    string getOraPlecare();

    string getOraSosire();

    string getLocuri();

    void checkData();

    void deleteData();
};

#endif