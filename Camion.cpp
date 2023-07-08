#include "Masina.cpp"

class Camion : public Masina {
private:
    int tonaj;

public:
    Camion(int id, int kilometri, int an, bool diesel, int ton)
        : Masina(id, kilometri, an, diesel), tonaj(ton) {}

    double calculValoarePolitaDeAsigurare() const override {
        double valoarePolitadeAsigurare = get_anFabricatie() * 300;

        if (get_numarKilometri() > 800000) {
            valoarePolitadeAsigurare += 700;
        }
        return valoarePolitadeAsigurare;
    }
};
