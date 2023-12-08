#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Operator
{

public:
    void getExistenceMail(string email);
    void getExistencePhone(string phone);
    void getStatus(string email);
    void getPermission(string email);
    void adaugareRuta(string nume, string plecare, string sosire, string data, string oraPlecare, string oraSosire, string locuri);
    void getRuta(string nume);
    void afisareRute();
    string getRutaLocuri(string nume);
    void updateRuta(string nume, string oldValue, string newValue);
    void deleteRuta(string nume);
    void getExistenceRuta(string nume);
};
#endif