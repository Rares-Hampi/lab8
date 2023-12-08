#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>

#include "operator.h"
#include "criptareandvalidare.h"
#include "utilizator.h"
#include "ruta.h"

using namespace std;

class Menu
{
public:
    string getOption()
    {
        string option;

        cout << "Introduceti optiunea: ";
        cin >> option;
        system("clear");
        return option;
    }

    void showMenu()
    {
        cout << "Bine ati venit!" << endl;
        cout << "Ce operatiuni doriti sa efectuati?" << endl;
        cout << "1-> Register" << endl;
        cout << "2-> Login" << endl;
        cout << "3-> Editare cont" << endl;
        cout << "4-> Operator" << endl;
        cout << "5-> Rute" << endl;
        cout << "6-> Logout" << endl;
        cout << "7-> Exit" << endl;
    }

    void showRegisterMenu()
    {

        cout << "Introduceti datele pentru inregistrare" << endl;
        cout << "1-> Nume" << endl;
        cout << "2-> Email" << endl;
        cout << "3-> Parola" << endl;
        cout << "4-> Telefon" << endl;
        cout << "5-> Inregistrare" << endl;
        cout << "6-> Inapoi" << endl;
    }

    void showLoginMenu()
    {
        cout << "Introduceti datele pentru logare" << endl;
        cout << "1-> Email" << endl;
        cout << "2-> Parola" << endl;
        cout << "3-> Login" << endl;
        cout << "4-> Inapoi" << endl;
    }

    void showEditMenu()
    {
        cout << "Introduceti datele pentru editare" << endl;
        cout << "1-> Nume" << endl;
        cout << "2-> Email" << endl;
        cout << "3-> Parola" << endl;
        cout << "4-> Telefon" << endl;
        cout << "5-> Inapoi" << endl;
    }

    void showOperatorMenu()
    {
        cout << "1-> Adauga ruta" << endl;
        cout << "2-> Editeaza ruta" << endl;
        cout << "3-> Sterge ruta" << endl;
        cout << "4-> Cauta ruta" << endl;
        cout << "5-> exit" << endl;
    }

    void showRutaMenu()
    {
        cout << "Ce operatiuni doriti sa efectuati?" << endl;
        cout << "1-> Afisare rute" << endl;
        cout << "2-> Cautare ruta" << endl;
        cout << "3-> Rezervare ruta" << endl;
        cout << "4-> Anulare rezervare" << endl;
        cout << "5-> Afisare rezervari" << endl;
        cout << "6-> Inapoi" << endl;
    }

    void showAdaugareRutaMenu()
    {
        cout << "Introduceti datele pentru ruta" << endl;
        cout << "1-> Nume ruta" << endl;
        cout << "3-> Oras plecare" << endl;
        cout << "3-> Oras sosire" << endl;
        cout << "4-> Data plecare" << endl;
        cout << "5-> Ora plecare" << endl;
        cout << "6-> Oras sosire" << endl;
        cout << "7-> Numar locuri" << endl;
        cout << "8-> Adauga ruta" << endl;
        cout << "9-> Inapoi" << endl;
    }

    void showEditRutaMenu()
    {
        cout << "Introduceti datele pentru editare" << endl;
        cout << "1-> Nume ruta" << endl;
        cout << "2-> Oras plecare" << endl;
        cout << "3-> Oras sosire" << endl;
        cout << "4-> Data plecare" << endl;
        cout << "5-> Ora sosire" << endl;
        cout << "6-> Ora plecare" << endl;
        cout << "7-> Numar locuri" << endl;
        cout << "8-> Inapoi" << endl;
    }

    void showExitMenu()
    {
        cout << "1-> Da" << endl;
        cout << "2-> Nu" << endl;
    }
};

class App
{
private:
    Menu menu;
    Utilizator user;
    Operator admin;
    Ruta ruta;
    CriptareAndValidare validareSiCriptare;

public:
    void run()
    {
        string option;
        do
        {
            menu.showMenu();
            option = menu.getOption();
            // Register
            if (option == "1")
            {
                string optionRegister;
                do
                {
                    menu.showRegisterMenu();
                    optionRegister = menu.getOption();
                    if (optionRegister == "1")
                    {
                        string nume;
                        string error;

                        do
                        {

                            cout << "Introduceti numele: ";

                            getline(cin, nume);

                            try
                            {
                                user.setNume(nume);
                                error = "";
                            }
                            catch (const char *e)
                            {
                                error = e;
                                cout << e << '\n';
                            };
                            fflush(stdin);
                        } while (error.length() > 0);
                    }
                    else if (optionRegister == "2")
                    {
                        string email;
                        string error;

                        do
                        {
                            cout << "Introduceti email: ";

                            cin >> email;
                            try
                            {
                                if (email.empty())
                                {
                                    throw "Emailul nu poate fi gol";
                                }

                                admin.getExistenceMail(email);
                                user.setEmail(email);
                                error = "";
                            }
                            catch (const char *e)
                            {
                                error = e;
                                cout << e << '\n';
                            }

                        } while (error.length() > 0);
                    }
                    else if (optionRegister == "3")
                    {
                        string parola;
                        string error;
                        do
                        {
                            cout << "Introduceti parola: ";
                            cin >> parola;
                            try
                            {
                                if (parola.empty())
                                {
                                    throw "Parola nu poate fi goala";
                                }
                                user.setParola(parola);
                                error = "";
                            }
                            catch (const char *e)
                            {
                                error = e;
                                cerr << e << '\n';
                            }
                            catch (const string &e)
                            {
                                error = e;
                                cerr << e << '\n';
                            }
                        } while (error.length() > 0);
                    }
                    else if (optionRegister == "4")
                    {
                        string phone;
                        string error;
                        do
                        {
                            cout << "Introduceti telefon: ";

                            cin >> phone;
                            try
                            {
                                if (phone.empty())
                                {
                                    throw "Telefonul nu poate fi gol";
                                }
                                admin.getExistencePhone(phone);
                                user.setPhone(phone);
                                error = "";
                            }
                            catch (const char *e)
                            {
                                error = e;
                                cerr << e << '\n';
                            }
                        } while (error.length() > 0);
                    }
                    else if (optionRegister == "5")
                    {
                        try
                        {
                            admin.getExistenceMail(user.getEmail());
                            admin.getExistencePhone(user.getPhone());
                            user.Register(user.getNume(), user.getEmail(), user.getParola(), user.getPhone());
                            cout << "Inregistrare cu succes" << endl;
                        }
                        catch (const char *e)
                        {
                            cout << e << '\n';
                        }
                    }

                } while (optionRegister != "6");
            }
            // Login
            else if (option == "2")
            {
                string optionLogin;
                do
                {
                    menu.showLoginMenu();
                    optionLogin = menu.getOption();
                    if (optionLogin == "1")
                    {
                        string email;
                        string error;

                        do
                        {
                            cout << "Introduceti email: ";
                            cin >> email;
                            try
                            {
                                if (email.empty())
                                {
                                    throw "Emailul nu poate fi gol";
                                }

                                user.setEmail(email);
                            }
                            catch (const char *e)
                            {
                                cerr << e << '\n';
                                error = e;
                            }
                        } while (error.length() > 0);
                    }
                    else if (optionLogin == "2")
                    {
                        string parola;
                        string error;
                        cout << "Introduceti parola: ";

                        cin >> parola;
                        do
                        {
                            try
                            {
                                if (parola.empty())
                                {
                                    throw "Parola nu poate fi goala";
                                }
                                user.setParola(parola);
                                cout << "Parola setata cu succes" << endl;
                                error = "";
                            }
                            catch (const char *e)
                            {
                                cerr << e << '\n';
                                error = e;
                            }
                        } while (error.length() > 0);
                    }
                    else if (optionLogin == "3")
                    {
                        try
                        {
                            user.Login(user.getEmail(), user.getParola());
                            cout << "Logare cu succes" << endl;
                        }
                        catch (const char *e)
                        {
                            cerr << e << '\n';
                        }
                        catch (const string &e)
                        {
                            cerr << e << '\n';
                        }
                    }
                    else if (optionLogin == "4")
                    {
                        cout << "Inapoi" << endl;
                    }
                } while (optionLogin != "4");
            }
            // Editare cont
            else if (option == "3")
            {
                string optionEdit;
                Operator admin;
                try
                {
                    admin.getStatus(user.getEmail());
                    do
                    {
                        menu.showEditMenu();
                        optionEdit = menu.getOption();
                        if (optionEdit == "1")
                        {
                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele: ";

                                getline(cin, nume);

                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }

                                    else if (nume.length() < 4)
                                    {
                                        throw "Numele trebuie sa aiba minim 4 caractere";
                                    }
                                    user.Edit("./csv/conturi.csv", user.getNume(), nume, user.getEmail());
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                };
                                fflush(stdin);

                            } while (error.length() > 0);
                        }
                        else if (optionEdit == "2")
                        {
                            string email;
                            string error;

                            do
                            {
                                cout << "Introduceti email: ";
                                cin >> email;
                                try
                                {
                                    if (email.empty())
                                    {
                                        throw "Emailul nu poate fi gol";
                                    }
                                    validareSiCriptare.validareMail(email);
                                    user.EditEmail(user.getEmail(), email);
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }

                            } while (error.length() > 0);
                        }
                        else if (optionEdit == "3")
                        {
                            string parola;
                            string error;
                            do
                            {
                                cout << "Introduceti parola: ";
                                cin >> parola;
                                try
                                {
                                    if (parola.empty())
                                    {
                                        throw "Parola nu poate fi goala";
                                    }
                                    validareSiCriptare.validareParola(parola);
                                    vector<int> keys = validareSiCriptare.menu();
                                    parola = validareSiCriptare.criptare(parola, keys[0], keys[1]);
                                    user.Edit("./csv/conturi.csv", user.getParola(), parola, user.getEmail());
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cerr << e << '\n';
                                }
                            } while (error.length() > 0);
                        }
                        else if (optionEdit == "4")
                        {
                            string phone;
                            string error;
                            do
                            {
                                cout << "Introduceti telefon: ";

                                cin >> phone;
                                try
                                {
                                    if (phone.empty())
                                    {
                                        throw "Telefonul nu poate fi gol";
                                    }
                                    validareSiCriptare.validareTelefon(phone);
                                    user.EditPhone(user.getEmail(), phone);
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cerr << e << '\n';
                                }
                            } while (error.length() > 0);
                        }
                        else if (optionEdit == "5")
                        {
                            cout << "Inapoi" << endl;
                        }

                    } while (optionEdit != "5");
                }
                catch (const char *e)
                {
                    cerr << e << '\n';
                };
            }
            // Operator
            else if (option == "4")
            {

                string optionOperator;
                try
                {
                    admin.getStatus(user.getEmail());
                    admin.getPermission(user.getEmail());

                    do
                    {
                        menu.showOperatorMenu();
                        optionOperator = menu.getOption();
                        // Adaugare ruta
                        if (optionOperator == "1")
                        {
                            do
                            {
                                menu.showAdaugareRutaMenu();
                                optionOperator = menu.getOption();
                                if (optionOperator == "1")
                                {
                                    string nume;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti numele: ";
                                        getline(cin, nume);
                                        try
                                        {
                                            if (nume.empty())
                                            {
                                                throw "Numele nu poate fi gol";
                                            }

                                            if (nume.length() < 4)
                                            {
                                                throw "Numele trebuie sa aiba minim 4 caractere";
                                            }

                                            admin.getExistenceRuta(nume);
                                            ruta.setNume(nume);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);

                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "2")
                                {

                                    string orasPlecare;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti orasul de plecare: ";
                                        getline(cin, orasPlecare);
                                        try
                                        {
                                            if (orasPlecare.empty())
                                            {
                                                throw "Orasul nu poate fi gol";
                                            }

                                            if (orasPlecare.length() < 4)
                                            {
                                                throw "Orasul trebuie sa aiba minim 4 caractere";
                                            }

                                            ruta.setPlecare(orasPlecare);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "3")
                                {
                                    string orasSosire;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti orasul de sosire: ";
                                        getline(cin, orasSosire);
                                        try
                                        {
                                            if (orasSosire.empty())
                                            {
                                                throw "Orasul nu poate fi gol";
                                            }

                                            if (orasSosire.length() < 4)
                                            {
                                                throw "Orasul trebuie sa aiba minim 4 caractere";
                                            }
                                            ruta.setSosire(orasSosire);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "4")
                                {
                                    string data;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti data (YYYY-MM-DD): ";
                                        cin >> data;
                                        try
                                        {
                                            if (data.empty())
                                            {
                                                throw "Data nu poate fi goala";
                                            }

                                            if (data.length() < 10)
                                            {
                                                throw "Data trebuie sa aiba minim 10 caractere";
                                            }

                                            data = validareSiCriptare.formatareData(data);
                                            validareSiCriptare.validareData(data);
                                            ruta.setData(data);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };

                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "5")
                                {
                                    string ora;
                                    string error;

                                    do
                                    {

                                        cout << "Introduceti ora plecarii (HH:MM): ";
                                        cin >> ora;
                                        try
                                        {
                                            if (ora.empty())
                                            {
                                                throw "Ora nu poate fi goala";
                                            }
                                            if (ora.length() < 5)
                                            {
                                                throw "Ora trebuie sa aiba minim 5 caractere";
                                            }

                                            validareSiCriptare.validareOra(ora);
                                            ruta.setOraPlecare(ora);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };

                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "6")
                                {
                                    string ora;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti ora sosirii(HH::MM): ";
                                        cin >> ora;
                                        try
                                        {
                                            if (ora.empty())
                                            {
                                                throw "Ora nu poate fi goala";
                                            }
                                            if (ora.length() < 5)
                                            {
                                                throw "Ora trebuie sa aiba minim 5 caractere";
                                            }

                                            validareSiCriptare.validareOra(ora);
                                            validareSiCriptare.verificareOra(ruta.getOraPlecare(), ora);
                                            ruta.setOraSosire(ora);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };

                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "7")
                                {
                                    int numarLocuri;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti numarul de locuri: ";
                                        cin >> numarLocuri;
                                        try
                                        {
                                            if (numarLocuri < 0)
                                            {
                                                throw "Numarul de locuri nu poate fi negativ";
                                            }

                                            if (numarLocuri == 0)
                                            {
                                                throw "Numarul de locuri nu poate fi 0";
                                            }
                                            ruta.setLocuri(numarLocuri);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        }
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "8")
                                {
                                    try
                                    {
                                        ruta.checkData();
                                        admin.getExistenceRuta(ruta.getNume());
                                        admin.adaugareRuta(ruta.getNume(), ruta.getPlecare(), ruta.getSosire(), ruta.getData(), ruta.getOraPlecare(), ruta.getOraSosire(), ruta.getLocuri());
                                        cout << "Ruta adaugata cu succes" << endl;
                                        ruta.getData();
                                    }
                                    catch (const char *e)
                                    {
                                        cerr << e << '\n';
                                    }
                                }
                                else if (optionOperator == "9")
                                {
                                    cout << "Inapoi" << endl;
                                }
                            } while (optionOperator != "9");
                        }
                        // Editare ruta
                        else if (optionOperator == "2")
                        {
                            do
                            {
                                menu.showEditRutaMenu();
                                optionOperator = menu.getOption();

                                if (optionOperator == "1")
                                {
                                    string nume;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti numele: ";
                                        getline(cin, nume);
                                        try
                                        {
                                            if (nume.empty())
                                            {
                                                throw "Numele nu poate fi gol";
                                            }

                                            if (nume.length() < 4)
                                            {
                                                throw "Numele trebuie sa aiba minim 4 caractere";
                                            }

                                            admin.getExistenceRuta(nume);
                                            admin.updateRuta(ruta.getNume(), "nume", nume);
                                            ruta.setNume(nume);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "2")
                                {
                                    string orasPlecare;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti orasul de plecare: ";
                                        getline(cin, orasPlecare);
                                        try
                                        {
                                            if (orasPlecare.empty())
                                            {
                                                throw "Orasul nu poate fi gol";
                                            }

                                            if (orasPlecare.length() < 4)
                                            {
                                                throw "Orasul trebuie sa aiba minim 4 caractere";
                                            }

                                            admin.updateRuta(ruta.getNume(), "plecare", orasPlecare);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "3")
                                {
                                    string orasSosire;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti orasul de sosire: ";
                                        getline(cin, orasSosire);
                                        try
                                        {
                                            if (orasSosire.empty())
                                            {
                                                throw "Orasul nu poate fi gol";
                                            }

                                            if (orasSosire.length() < 4)
                                            {
                                                throw "Orasul trebuie sa aiba minim 4 caractere";
                                            }

                                            admin.updateRuta(ruta.getNume(), "sosire", orasSosire);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };
                                        fflush(stdin);
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "4")
                                {
                                    string data;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti data (YYYY-MM-DD): ";
                                        cin >> data;
                                        try
                                        {
                                            if (data.empty())
                                            {
                                                throw "Data nu poate fi goala";
                                            }

                                            if (data.length() < 10)
                                            {
                                                throw "Data trebuie sa aiba minim 10 caractere";
                                            }

                                            data = validareSiCriptare.formatareData(data);
                                            validareSiCriptare.validareData(data);
                                            admin.updateRuta(ruta.getNume(), "data", data);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        };

                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "5")
                                {
                                    string ora;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti ora plecarii (HH:MM): ";
                                        cin >> ora;
                                        try
                                        {
                                            if (ora.empty())
                                            {
                                                throw "Ora nu poate fi goala";
                                            }

                                            if (ora.length() < 5)
                                            {
                                                throw "Ora trebuie sa aiba minim 5 caractere";
                                            }
                                            validareSiCriptare.validareOra(ora);
                                            admin.updateRuta(ruta.getNume(), "oraPlecare", ora);
                                            ruta.setOraPlecare(ora);
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        }
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "6")
                                {
                                    string ora;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti ora sosirii: ";
                                        cin >> ora;
                                        try
                                        {
                                            if (ora.empty())
                                            {
                                                throw "Ora nu poate fi goala";
                                            }

                                            if (ora.length() < 5)
                                            {
                                                throw "Ora trebuie sa aiba minim 5 caractere";
                                            }
                                            validareSiCriptare.validareOra(ora);
                                            validareSiCriptare.verificareOra(ruta.getOraPlecare(), ora);
                                            admin.updateRuta(ruta.getNume(), "oraSosire", ora);
                                            ruta.deleteData();
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        }
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "7")
                                {
                                    int numarLocuri;
                                    string error;

                                    do
                                    {
                                        cout << "Introduceti numarul de locuri: ";
                                        cin >> numarLocuri;
                                        try
                                        {
                                            if (numarLocuri < 0)
                                            {
                                                throw "Numarul de locuri nu poate fi negativ";
                                            }

                                            if (numarLocuri == 0)
                                            {
                                                throw "Numarul de locuri nu poate fi 0";
                                            }

                                            admin.updateRuta(ruta.getNume(), "locuri", to_string(numarLocuri));
                                            error = "";
                                        }
                                        catch (const char *e)
                                        {
                                            error = e;
                                            cout << e << '\n';
                                        }
                                    } while (error.length() > 0);
                                }
                                else if (optionOperator == "8")
                                {
                                    cout << "Inapoi" << endl;
                                }
                            } while (optionOperator != "8");
                        }
                        // Stergere ruta
                        else if (optionOperator == "3")
                        {

                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele rutei: ";
                                getline(cin, nume);
                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }

                                    admin.getExistenceRuta(nume);
                                    admin.deleteRuta(nume);
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }
                                fflush(stdin);
                            } while (error.length() > 0);
                        }
                        // Cautare ruta
                        else if (optionOperator == "4")
                        {

                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele rutei: ";
                                getline(cin, nume);
                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }
                                    admin.getRuta(nume);
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }
                                fflush(stdin);
                            } while (error.length() > 0);
                        }
                        else if (optionOperator == "5")
                        {
                            cout << "Inapoi" << endl;
                        }
                    } while (optionOperator != "5");
                }
                catch (const char *e)
                {
                    std::cerr << e << '\n';
                };
            }
            // Rute
            else if (option == "5")
            {
                string optionRuta;
                try
                {
                    admin.getStatus(user.getEmail());
                    do
                    {
                        menu.showRutaMenu();
                        optionRuta = menu.getOption();
                        if (optionRuta == "1")
                        {
                            admin.afisareRute();
                        }
                        else if (optionRuta == "2")
                        {
                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele rutei: ";
                                getline(cin, nume);
                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }

                                    admin.getRuta(nume);
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }
                                fflush(stdin);
                            } while (error.length() > 0);
                        }
                        else if (optionRuta == "3")
                        {
                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele rutei: ";
                                getline(cin, nume);
                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }

                                    user.rezervareRuta(nume, user.getEmail());
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }
                                fflush(stdin);
                            } while (error.length() > 0);
                        }
                        else if (optionRuta == "4")
                        {
                            string nume;
                            string error;

                            do
                            {
                                cout << "Introduceti numele rutei: ";
                                getline(cin, nume);
                                try
                                {
                                    if (nume.empty())
                                    {
                                        throw "Numele nu poate fi gol";
                                    }

                                    user.anulareRezervare(nume, user.getEmail());
                                    error = "";
                                }
                                catch (const char *e)
                                {
                                    error = e;
                                    cout << e << '\n';
                                }
                                fflush(stdin);
                            } while (error.length() > 0);
                        }
                        else if (optionRuta == "5")
                        {
                            user.getRezervari(user.getEmail());
                        }
                        else if (optionRuta == "6")
                        {
                            cout << "Inapoi" << endl;
                        }

                    } while (optionRuta != "6");
                }
                catch (const char *e)
                {
                    std::cerr << e << '\n';
                };
            }
            // Logout
            else if (option == "6")
            {
                user.Logout();
                cout << "Logout cu succes" << endl;
            }
            // Exit
            else if (option == "7")
            {
                string optionExit;
                do
                {
                    menu.showExitMenu();
                    optionExit = menu.getOption();
                    if (optionExit == "1")
                    {
                        cout << "La revedere" << endl;
                        exit(0);
                    }
                    else if (optionExit == "2")
                    {
                        cout << "Inapoi" << endl;
                    }
                } while (optionExit != "2");
            }
        } while (option != "7");
    }
};

int main()
{

    App app;
    app.run();

    return 0;
}