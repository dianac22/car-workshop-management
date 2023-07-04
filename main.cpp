#include <iostream>
#include "AtelierAuto.cpp"
using namespace std;

void Meniu() {
    AtelierAuto atelier;

    while (true) {
        cout << "\n--- Meniu ---\n";
        cout << "1. Afisare angajati\n";
        cout << "2. Adaugare angajat\n";
        cout << "3. Stergere angajat\n";
        cout << "4. Editare angajat\n";
        cout << "5. Calcul salariu angajat\n";
        cout << "0. Iesire\n";
        cout << "Introduceti optiunea: ";
        int optiune;
        cin >> optiune;

        switch (optiune) {
            case 1:
                atelier.afisareAngajati();
                break;
            case 2:
            {
                string nume, prenume, dataNasterii, dataAngajarii;
                float coeficient;

                cout << "Introduceti informatiile angajatului:\n";
                cout << "Nume: ";
                cin >> nume;
                cout << "Prenume: ";
                cin >> prenume;
                cout << "Data Nasterii: ";
                cin >> dataNasterii;
                cout << "Data Angajarii: ";
                cin >> dataAngajarii;
                cout << "Coeficient salariat:";
                cin >> coeficient;

                atelier.adaugareAngajat(nume, prenume, dataNasterii, dataAngajarii, coeficient*1.0f);
            }
                break;
            case 3:
            {
                int id;
                cout << "Introduceti ID-ul angajatului: ";
                cin >> id;
                atelier.stergereAngajat(id);
            }
                break;
            case 4:
            {
                int id;
                cout << "Introduceti ID-ul angajatului: ";
                cin >> id;
                atelier.editareAngajat(id);
            }
                break;
            case 5:
            {
                int id;
                cout << "Introduceti ID-ul angajatului: ";
                cin >> id;
                atelier.calculSalariu(id);
            }
                break;
            case 0:
                return;
            default:
                cout << "Optiune invalida. Incercati din nou.\n";
        }
    }
}

int main() {
    Meniu();
    return 0;
}
