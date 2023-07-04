#include <iostream>
#include <vector>
#include <string>
#include "Angajat.cpp"
using namespace std;

class AtelierAuto {
private:
    vector<Angajat> angajati;
    int idCounter = 1;

public:
    void afisareAngajati() {
        cout << "Angajati:\n";
        for(auto& angajat : angajati) {
            angajat.afisareAngajat();
            cout << endl;
        }
    }

    void adaugareAngajat(string nume, string prenume, string dataNasterii, string dataAngajarii, float coeficient) {
        angajati.push_back(Angajat(idCounter++, nume, prenume, dataNasterii, dataAngajarii, coeficient));
        cout << "Angajatul a fost adaugat cu succes.\n";
    }

    void stergereAngajat(int id) {
        for(auto it = angajati.begin(); it != angajati.end(); ++it) {
            if(it->ID == id) {
                angajati.erase(it);
                cout << "Angajatul cu id-ul:" << id << " a fost sters.\n";
                return;
            }
        }
        cout << "Nu exista un angajat cu id-ul:" << id << ".\n";
    }

    void editareAngajat(int id) {
        for(auto& angajat : angajati) {
            if(angajat.ID == id) {
                string nume, prenume, dataNasterii, dataAngajarii;
                float coeficient;
                cout << "Introduceti noile informatii:\n";
                cout << "Nume:";
                cin >> nume;
                cout << "Prenume:";
                cin >> prenume;
                cout << "Data nasterii:";
                cin >> dataNasterii;
                cout << "Data angajarii:";
                cin >> dataAngajarii;
                cout << "Coeficient:";
                cin >> coeficient;

                angajat.Nume = nume;
                angajat.Prenume = prenume;
                angajat.DataNasterii = dataNasterii;
                angajat.DataAngajarii = dataAngajarii;
                angajat.CoeficientSalariat = coeficient;
                cout << "Angajatul cu id-ul:" << id << " a fost actualizat.\n";
                return;
            }
        }
        cout << "Nu exista angajatul cu id-ul:" << id <<".\n";
    }

    void calculSalariu(int id) {
        for(auto& angajat : angajati) {
            if(angajat.ID == id) {
                time_t now = time(nullptr);
                tm* currentDate = localtime(&now);
                int aniVechime = currentDate->tm_year + 1900 - stoi(angajat.DataAngajarii.substr(6, 4));
                float salariu = aniVechime * angajat.CoeficientSalariat * 1000;

                cout << "Salariul angajatului cu id-ul " << id << " este: " << salariu << " lei.\n";
                return;
            }
        }
        cout << "Nu exista angajatul cu id-ul:" << id << ".\n";
    }
};
