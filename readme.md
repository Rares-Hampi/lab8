# Laborator 8

## Cum se ruleaza

```bash
$ cd lab8
$ make
$ ./aplicatie
```

Link catre [Makefile](./Makefile)

Link catre [Repo](https://github.com/Rares-Hampi/lab8)

## Descrierea temei

Tema presupune realizarea unei aplicatii care sa permita gestionarea unei companii de transport.

Aplicatia permite inregistrarea unui utilizator, autentificarea acestuia, editarea datelor unui utilizator, adaugarea unei rute, stergerea unei rute, editarea unei rute, vizualizarea rutelor disponibile, vizualizarea detaliilor unei rute, vizualizarea tuturor rutelor, vizualizarea tuturor rezervarilor, vizualizarea rezervarilor unui utilizator, stergerea unei rezervari, adaugarea unei rezervari.


## Descrierea bazei de date

Baza de date contine 3 tabele:

- 1. Tabela Useri
- 2. Tabela Rute
- 3. Tabela Rezervari

### Tabela Useri

Tabela Useri contine datele despre utilizatori.

Tabela are urmatoarele coloane:

-  email  - email-ul unui utilizator
-  nume  - numele unui utilizator
-  parola  - parola unui utilizator
-  telefon  - numarul de telefon al unui utilizator
- status - statusul unui utilizator (inregistrat sau logat)
- rol - rolul unui utilizator (user sau admin)


### Tabela Rute 
Tabela Rute contine datele despre rute.

Tabela are urmatoarele coloane:

-  nume  - numele unei rute
-  destinatie  - destinatia unei rute
-  plecare  - locul de plecare al unei rute
- destinatie  - destinatia unei rute
-  oraPleacre  - ora de plecare a unei rute
-  oraSosire  - ora de sosire a unei rute
-  data  - data unei rute
-  locuri  - locurile disponibile ale unei rute


### Tabela Rezervari
Tabela Rezervari contine datele despre rezervari.

Tabela are urmatoarele coloane:

- nume ruta - numele unei rute
- email - email-ul unui utilizator



## Functionalitati

- 1. Inregistrarea unui utilizator
- 2. Autentificarea unui utilizator
- 3. Editarea datelor unui utilizator
- 4. Adaugarea unei rute
- 5. Stergearea unei rute
- 6. Editarea unei rute
- 7. Vizualizarea rutelor disponibile
- 8. Vizualizarea detaliilor unei rute
- 9. Vizualizarea tuturor rutelor
- 10. Vizualizarea tuturor rezervarilor
- 11. Vizualizarea rezervarilor unui utilizator
- 12. Stergerea unei rezervari
- 13. Adaugarea unei rezervari


## Clasele folosite

- 1. User
- 2. Ruta
- 3. Operator
- 4. CriptareAndValidare
- 5. Menu
- 6. App

## Descrierea claselor

### User

Clasa User contine toate datele despre un utilizator, precum si metodele necesare pentru a lucra cu aceste date.

Pentru fiecare metoda avem validari pentru datele de intrare, iar in cazul in care acestea nu sunt valide, se arunca o exceptie.

Avem metode precum:

-  Register : Metoda care se ocupa cu inregistrarea unui utilizator
-  Login : Metoda care se ocupa cu autentificarea unui utilizator
-  Edit : Metoda care se ocupa cu editarea datelor unui utilizator
-  Logout : Metoda care se ocupa cu delogarea unui utilizator
-  Edit : Metoda care se ocupa cu editarea datelor unui utilizator
-  Getters : Metode care returneaza datele unui utilizator
-  Setters : Metode care seteaza datele unui utilizator
-  rezervareRuta : Metoda care se ocupa cu rezervarea unei rute
-  anulareRezervare : Metoda care se ocupa cu stergerea unei rezervari
- getRezervari : Metoda care returneaza rezervarile unui utilizator


### Ruta

Clasa Ruta contine toate datele despre o ruta, precum si metodele necesare pentru a lucra cu aceste date.

Pentru fiecare metoda avem validari pentru datele de intrare, iar in cazul in care acestea nu sunt valide, se arunca o exceptie.

Avem metode precum:

- Setters : Metode care seteaza datele unei rute
- Getters : Metode care returneaza datele unei rute


### Operator

Clasa Operator contine functiile necesare pentru a lucra cu datele din baza de date.

Pentru fiecare metoda avem validari pentru datele de intrare, iar in cazul in care acestea nu sunt valide, se arunca o exceptie.

Avem metode precum:

- metode de verificare a datelor pentru a nu se repeta in baza de date
- adaugareRuta : Metoda care se ocupa cu adaugarea unei rute
- deleteRuta : Metoda care se ocupa cu stergerea unei rute
- updateRuta : Metoda care se ocupa cu editarea unei rute
- getRuta : Metoda care returneaza o ruta
- getRutaLocuri : Metoda care returneaza locurile unei rute
- afisareRute : Metoda care returneaza toate rutele


### CriptareAndValidare

Clasa CriptareAndValidare contine metode pentru criptarea parolei unui utilizator si pentru validarea datelor de intrare.

Avem metode precum:

- criptare : Metoda care se ocupa cu criptarea parolei unui utilizator
- validareMail : Metoda care se ocupa cu validarea unui mail
- validarePhone : Metoda care se ocupa cu validarea unui numar de telefon
- formatareData : Metoda care se ocupa cu formatarea unei date
- verificareData : Metoda care se ocupa cu verificarea unei date
- validareData : Metoda care se ocupa cu validarea unei date
- validareOra : Metoda care se ocupa cu validarea unei ore


### Menu

Clasa Menu contine metode pentru afisarea meniului si pentru alegerea unei optiuni din meniu.



### App

Clasa App contine metoda main, care se ocupa cu rularea programului.


