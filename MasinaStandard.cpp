#include "Masina.cpp"

class MasinaStandard : public Masina {
private:
    ModTransmisie transmisie;

public:
    MasinaStandard(int id, int kilometri, int an, bool diesel, ModTransmisie trans)
    : Masina(id, kilometri, an, diesel), transmisie(trans) {}

    double calculValoarePolitaDeAsigurare() const override {
        double valoarePolitadeAsigurare = get_anFabricatie() * 100;
        if (is_motorDiesel()) {
            valoarePolitadeAsigurare += 500;
        }
        if (get_numarKilometri() > 200000) {
            valoarePolitadeAsigurare += 500;
        }
        return valoarePolitadeAsigurare;
    }
};
