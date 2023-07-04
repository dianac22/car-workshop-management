#include <iostream>
#include <string>
using namespace std;

class Angajat {
public:
    int ID;
    string Nume;
    string Prenume;
    string DataNasterii;
    string DataAngajarii;
    float CoeficientSalariat;

    Angajat(int id, string nume, string prenume, string dataNasterii, string dataAngajarii, float coeficient) : ID(id),
    Nume(nume), Prenume(prenume), DataNasterii(dataNasterii), DataAngajarii(dataAngajarii), CoeficientSalariat(coeficient) {}

    void afisareAngajat() {
        cout << "ID:" << ID << endl;
        cout << "Nume:" << Nume << endl;
        cout << "Prenume:" << Prenume << endl;
        cout << "Data nasterii:" << DataNasterii << endl;
        cout << "Data angajarii:" << DataAngajarii << endl;
        cout << "Coeficient:" << CoeficientSalariat << endl;
    }
};
