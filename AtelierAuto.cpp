#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <chrono>
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
        // Verificam varsta angajatului - sa aiba cel putin 18 ani
        tm tmNasterii = {};
        istringstream issNasterii(dataNasterii);
        string day, month, year;
        getline(issNasterii, day, '.');
        getline(issNasterii, month, '.');
        getline(issNasterii, year);
        tmNasterii.tm_mday = std::stoi(day);
        tmNasterii.tm_mon = std::stoi(month) - 1;
        tmNasterii.tm_year = std::stoi(year) - 1900;

        tm tmAngajarii = {};
        istringstream issAngajarii(dataAngajarii);
        getline(issAngajarii, day, '.');
        getline(issAngajarii, month, '.');
        getline(issAngajarii, year);
        tmAngajarii.tm_mday = std::stoi(day);
        tmAngajarii.tm_mon = std::stoi(month) - 1;
        tmAngajarii.tm_year = std::stoi(year) - 1900;

        time_t tNasterii = mktime(&tmNasterii);
        time_t tAngajarii = mktime(&tmAngajarii);

        double ageSeconds = difftime(tAngajarii, tNasterii);
        double ageYears = ageSeconds / (60 * 60 * 24 * 365.25); // an bisect

        if (ageYears < 18) {
            cout << "Angajatul trebuie sa aiba minim 18 ani la data angajarii.\n";
            return;
        }

        // Verificam data angajarii pentru a nu putea fi din viitor
        time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm* tmCurrent = localtime(&currentTime);

        if (tmAngajarii.tm_year > tmCurrent->tm_year || (tmAngajarii.tm_year == tmCurrent->tm_year && tmAngajarii.tm_mon > tmCurrent->tm_mon) ||
            (tmAngajarii.tm_year == tmCurrent->tm_year && tmAngajarii.tm_mon == tmCurrent->tm_mon && tmAngajarii.tm_mday > tmCurrent->tm_mday)) {
            cout << "Data de angajare nu poate fi în viitor.\n";
            return;
        }

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
