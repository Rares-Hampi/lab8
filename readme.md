Funcția Utilizator::rezervareRuta pare să fie responsabilă pentru rezervarea unei rute pentru un utilizator. Iată o descriere pas cu pas a ceea ce face funcția:

Începe prin crearea unui obiect admin de tipul Operator.

Verifică dacă mai sunt locuri disponibile pentru ruta specificată. Dacă nu sunt locuri disponibile, aruncă o excepție cu mesajul "Nu mai sunt locuri disponibile".

Deschide fișierul rute.csv pentru citire. Dacă fișierul nu poate fi deschis, aruncă o excepție cu mesajul "Nu s-a putut deschide fisierul".

Parcurge fiecare linie din fișier, extrăgând numele rutei și numărul de locuri disponibile.

Dacă numele rutei din fișier corespunde cu numele rutei pentru care se face rezervarea și mai sunt locuri disponibile, deschide fișierul rezervari.csv pentru a adăuga o nouă rezervare.

Adaugă o nouă linie în fișierul rezervari.csv cu numele rutei și adresa de email a utilizatorului.

Actualizează numărul de locuri disponibile pentru ruta respectivă, scăzând cu 1 numărul de locuri disponibile.

Dacă numele rutei din fișier nu corespunde cu numele rutei pentru care se face rezervarea sau nu mai sunt locuri disponibile, aruncă o excepție cu mesajul "Nu mai sunt locuri disponibile".

În final, închide fișierul rute.csv.

Dacă apare o eroare în timpul acestui proces, funcția va arunca o excepție cu un mesaj de eroare corespunzător.

Funcția Utilizator::anulareRezervare pare să fie responsabilă pentru anularea unei rezervări făcute de un utilizator. Iată o descriere pas cu pas a ceea ce face funcția:

Începe prin crearea unui obiect admin de tipul Operator.

Încearcă să deschidă fișierul rezervari.csv pentru citire și un fișier temporar temp2.csv pentru scriere.

Dacă ambele fișiere sunt deschise cu succes, parcurge fiecare linie din fișierul rezervari.csv.

Pentru fiecare linie, extrage numele și adresa de email.

Dacă numele și adresa de email corespund cu cele date ca parametri, anulează rezervarea prin afișarea unui mesaj și actualizarea numărului de locuri disponibile pentru ruta respectivă.

Dacă numele și adresa de email nu corespund cu cele date ca parametri, scrie linia în fișierul temporar.

Închide ambele fișiere.

Șterge fișierul original rezervari.csv și redenumește fișierul temporar temp2.csv în rezervari.csv.

Dacă apare o eroare în timpul acestui proces, cum ar fi imposibilitatea de a deschide unul dintre fișiere, funcția va arunca o excepție cu un mesaj de eroare corespunzător.