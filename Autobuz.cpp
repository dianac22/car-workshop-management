#include "Masina.cpp"

class Autobuz : public Masina {
private:
    int numarLocuri;

public:
    Autobuz(int id, int kilometri, int an, bool diesel, int locuri)
        : Masina(id, kilometri, an, diesel), numarLocuri(locuri) {}

    double calculValoarePolitaDeAsigurare() const override {
        double valoarePolitadeAsigurare = get_anFabricatie() * 200;

        if (is_motorDiesel()) {
            valoarePolitadeAsigurare += 1000;
        }

        if (get_numarKilometri() > 200000) {
            valoarePolitadeAsigurare += 1000;
        }
        else
            if (get_numarKilometri() > 100000) {
                valoarePolitadeAsigurare += 500;
            }
        return valoarePolitadeAsigurare;
    }
};
