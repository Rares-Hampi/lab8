#include "ruta.h"
#include "operator.h"

Ruta::Ruta()
{
    nume = "";
    plecare = "";
    sosire = "";
    data = "";
    oraPlecare = "";
    oraSosire = "";
    locuri = "";
}

void Ruta::setNume(string nume)
{
    this->nume = nume;
}

void Ruta::setPlecare(string plecare)
{
    this->plecare = plecare;
}

void Ruta::setSosire(string sosire)
{
    this->sosire = sosire;
}

void Ruta::setData(string data)
{
    this->data = data;
}

void Ruta::setOraPlecare(string ora)
{
    this->oraPlecare = ora;
}

void Ruta::setOraSosire(string ora)
{
    this->oraSosire = ora;
}

void Ruta::setLocuri(int locuri)
{

    this->locuri = to_string(locuri);
}

string Ruta::getNume()
{
    return this->nume;
}

string Ruta::getPlecare()
{
    return this->plecare;
}

string Ruta::getSosire()
{
    return this->sosire;
}

string Ruta::getData()
{
    return this->data;
}

string Ruta::getOraPlecare()
{
    return this->oraPlecare;
}

string Ruta::getOraSosire()
{
    return this->oraSosire;
}

string Ruta::getLocuri()
{
    return this->locuri;
}

void Ruta::checkData()
{
    try
    {
        if (nume.empty())
        {
            throw "Nume nu este setat";
        }
        if (plecare.empty())
        {

            throw "Plecare nu este setat";
        }
        if (sosire.empty())
        {
            throw "Sosire nu este setat";
        }
        if (data.empty())
        {
            throw "Data nu este setata";
        }
        if (oraPlecare.empty())
        {
            throw "Ora nu este setata";
        }
        if (oraSosire.empty())
        {
            throw "Ora nu este setata";
        }
        if (locuri.empty())
        {
            throw "Locuri nu este setat";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Ruta::deleteData()
{
    this->nume = "";
    this->plecare = "";
    this->sosire = "";
    this->data = "";
    this->oraPlecare = "";
    this->oraSosire = "";
    this->locuri = "";
};
