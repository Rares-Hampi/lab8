#include "operator.h"

void Operator::getExistenceMail(string email)
{
    try
    {
        ifstream file;
        file.open("./csv/conturi.csv");
        if (file.is_open())
        {
            string line;
            bool emailExists = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedEmail;
                getline(ss, storedEmail, ',');
                if (storedEmail == email)
                {
                    emailExists = true;
                    break;
                }
            }
            file.close();

            if (emailExists)
            {

                throw "Exista deja un cont inregistrat cu acest email";
            }
        }
        else
        {

            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::getExistencePhone(string phone)
{

    try
    {

        ifstream file;
        file.open("./csv/conturi.csv");
        if (file.is_open())
        {
            string line;
            bool phoneExists = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedPhone;
                getline(ss, storedPhone, ',');
                for (int i = 0; i < 3; i++)
                {
                    getline(ss, storedPhone, ',');
                }
                if (storedPhone == phone)
                {
                    phoneExists = true;
                    break;
                }
            }
            file.close();

            if (phoneExists)
            {
                throw "Exista deja un cont inregistrat cu acest numar de telefon";
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::getStatus(string email)
{

    try
    {
        if (!(email.length() > 0))
        {
            throw "Nu ai permisiunea de a accesa aceasta optiune. Te rog sa te loghezi. Alegeti optiunea 1 sau 2 din meniu";
        }

        ifstream file;
        file.open("./csv/conturi.csv");
        if (file.is_open())
        {
            string line;
            string status;
            bool emailFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedEmail;
                getline(ss, storedEmail, ',');
                if (storedEmail == email)
                {
                    emailFound = true;
                    for (int i = 0; i < 4; i++)
                    {
                        getline(ss, status, ',');
                    }
                    break;
                }
            }
            file.close();

            if (!emailFound)
            {
                throw "Email-ul nu a fost gasit in baza de date";
            }
            else if (status == "inregistrat")
            {
                throw "Inca nu ai drepturi pentru a accesa aceasta optiune. Te rog sa te loghezi";
            }
            else if (status == "logat")
            {
                cout << "Deja esti logat" << endl;
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::getPermission(string email)
{
    try
    {
        ifstream file;
        file.open("./csv/conturi.csv");
        if (file.is_open())
        {

            string line;
            string rol;
            bool emailFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedEmail;
                getline(ss, storedEmail, ',');
                if (storedEmail == email)
                {
                    emailFound = true;
                    for (int i = 0; i < 5; i++)
                    {
                        getline(ss, rol, ',');
                    }
                    break;
                }
            }

            if (rol == "user")
            {
                throw "Nu ai drepturi pentru a accesa aceasta optiune";
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::adaugareRuta(string nume, string plecare, string sosire, string data, string oraPleacare, string oraSosire, string locuri)
{
    ofstream file;
    file.open("./csv/rute.csv", ios::app);
    if (file.is_open())
    {
        file << nume << "," << plecare << "," << sosire << "," << oraPleacare << "," << oraSosire << "," << data << "," << locuri << endl;
        file.close();
    }
    else
    {
        throw "Nu s-a putut deschide fisierul";
    }
}

void Operator::deleteRuta(string nume)
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool rutaFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedName;
                if (storedName == nume)
                {
                    rutaFound = true;
                    break;
                }
            }
            file.close();

            if (!rutaFound)
            {
                throw "Ruta nu a fost gasita in baza de date";
            }
            else
            {
                ifstream file;
                file.open("./csv/rute.csv");
                ofstream temp;
                temp.open("./csv/temp.csv");
                if (file.is_open() && temp.is_open())
                {
                    string line;
                    while (getline(file, line))
                    {
                        stringstream ss(line);
                        string storedName;
                        string storedPlecare;
                        string storedSosire;
                        string storedData;
                        string storedOraPlacare;
                        string storedOraSosire;
                        string storedLocuri;
                        getline(ss, storedName, ',');
                        getline(ss, storedPlecare, ',');
                        getline(ss, storedSosire, ',');
                        getline(ss, storedOraPlacare, ',');
                        getline(ss, storedOraSosire, ',');
                        getline(ss, storedData, ',');
                        getline(ss, storedLocuri, ',');
                        if (storedName != nume)
                        {

                            temp << storedName << "," << storedPlecare << "," << storedSosire << "," << storedOraPlacare << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                        }
                    }
                    file.close();
                    temp.close();
                    remove("./csv/rute.csv");
                    rename("./csv/temp.csv", "./csv/rute.csv");
                }
                else
                {
                    throw "Nu s-a putut deschide fisierul";
                }
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::getExistenceRuta(string nume)
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool rutaFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedName;
                getline(ss, storedName, ',');

                if (storedName == nume)
                {
                    rutaFound = true;
                    break;
                }
            }
            file.close();

            if (rutaFound)
            {
                throw "Ruta exista deja in baza de date";
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::getRuta(string nume)
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool rutaFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedName;
                string storedPlecare;
                string storedSosire;
                string storedData;
                string storedOraPlecare;
                string storedOraSosire;
                string storedLocuri;
                getline(ss, storedName, ',');
                getline(ss, storedPlecare, ',');
                getline(ss, storedSosire, ',');
                getline(ss, storedOraPlecare, ',');
                getline(ss, storedOraSosire, ',');
                getline(ss, storedData, ',');
                getline(ss, storedLocuri, ',');
                if (storedName == nume)
                {
                    rutaFound = true;
                    cout << "Nume: " << storedName << " Plecare: " << storedPlecare << " Sosire: " << storedSosire << " Ora pleacare: " << storedOraPlecare << " Ora sosire: " << storedOraSosire << " Data: " << storedData << " Locuri: " << storedLocuri << endl;
                    break;
                }
            }

            file.close();

            if (!rutaFound)
            {
                throw "Ruta nu a fost gasita in baza de date";
            }
        }

        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

string Operator::getRutaLocuri(string name)
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool rutaFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedName;

                string storedLocuri;
                getline(ss, storedName, ',');
                for (int i = 0; i < 6; i++)
                {
                    getline(ss, storedLocuri, ',');
                }

                if (storedName == name)
                {
                    rutaFound = true;
                    return storedLocuri;
                    break;
                }
            }

            file.close();

            if (!rutaFound)
            {
                throw "Ruta nu a fost gasita in baza de date";
            }
        }

        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::afisareRute()
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool firstLine = true;
            while (getline(file, line))
            {
                if (firstLine)
                {
                    firstLine = false;
                    continue; // Skip the first line
                }
                stringstream ss(line);
                string storedName;
                string storedPlecare;
                string storedSosire;
                string storedData;
                string storedOraPlecare;
                string storedOraSosire;
                string storedLocuri;
                getline(ss, storedName, ',');
                getline(ss, storedPlecare, ',');
                getline(ss, storedSosire, ',');
                getline(ss, storedOraPlecare, ',');
                getline(ss, storedOraSosire, ',');
                getline(ss, storedData, ',');
                getline(ss, storedLocuri, ',');
                cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "| Nume: " << storedName << "| Plecare: " << storedPlecare << "| Sosire: " << storedSosire << "| Ora pleacare: " << storedOraPlecare << "| Ora sosire: " << storedOraSosire << "| Data: " << storedData << "| Locuri: |" << storedLocuri << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            file.close();
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}

void Operator::updateRuta(string nume, string oldValue, string newValue)
{
    try
    {
        ifstream file;
        file.open("./csv/rute.csv");
        if (file.is_open())
        {
            string line;
            bool rutaFound = false;
            while (getline(file, line))
            {
                stringstream ss(line);
                string storedName;

                getline(ss, storedName, ',');

                if (storedName == nume)
                {
                    rutaFound = true;
                    break;
                }
            }
            file.close();

            if (!rutaFound)
            {
                throw "Ruta nu a fost gasita in baza de date";
            }
            else
            {
                ifstream file;
                file.open("./csv/rute.csv");
                ofstream temp;
                temp.open("./csv/temp.csv");
                if (file.is_open() && temp.is_open())
                {
                    string line;
                    while (getline(file, line))
                    {
                        stringstream ss(line);
                        string storedName;
                        string storedPlecare;
                        string storedSosire;
                        string storedData;
                        string storedOraPlecare;
                        string storedOraSosire;
                        string storedLocuri;
                        getline(ss, storedName, ',');
                        getline(ss, storedPlecare, ',');
                        getline(ss, storedSosire, ',');
                        getline(ss, storedOraPlecare, ',');
                        getline(ss, storedOraSosire, ',');
                        getline(ss, storedData, ',');
                        getline(ss, storedLocuri, ',');

                        if (storedName != nume)
                        {
                            temp << storedName << "," << storedPlecare << "," << storedSosire << "," << storedOraPlecare << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                        }
                        else
                        {

                            if (oldValue == "nume")
                            {
                                temp << newValue << "," << storedPlecare << "," << storedSosire << "," << storedOraPlecare << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "plecare")
                            {
                                temp << storedName << "," << newValue << "," << storedSosire << "," << storedOraPlecare << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "sosire")
                            {
                                temp << storedName << "," << storedPlecare << "," << newValue << "," << storedOraPlecare << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "oraPlecare")
                            {
                                temp << storedName << "," << storedPlecare << "," << storedSosire << "," << newValue << "," << storedOraSosire << "," << storedData << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "oraSosire")
                            {
                                temp << storedName << "," << storedPlecare << "," << storedSosire << "," << storedOraPlecare << "," << newValue << "," << storedData << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "data")
                            {
                                temp << storedName << "," << storedPlecare << "," << storedSosire << "," << storedOraPlecare << "," << storedOraSosire << "," << newValue << "," << storedLocuri << endl;
                            }
                            else if (oldValue == "locuri")
                            {
                                temp << storedName << "," << storedPlecare << "," << storedSosire << "," << storedOraPlecare << "," << storedOraSosire << "," << storedData << "," << newValue << endl;
                            }
                        }
                    }
                    file.close();
                    temp.close();
                    remove("./csv/rute.csv");
                    rename("./csv/temp.csv", "./csv/rute.csv");
                }
                else
                {
                    throw "Nu s-a putut deschide fisierul";
                }
            }
        }
        else
        {
            throw "Nu s-a putut deschide fisierul";
        }
    }
    catch (const char *e)
    {
        throw e;
    }
}
