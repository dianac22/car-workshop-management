enum class ModTransmisie {
    Manual,
    Automat
};

class Masina {
private:
    int ID;
    int numarKilometri;
    int anFabricatie;
    bool motorDiesel;

public:
    Masina(int id, int kilometri, int an, bool diesel)
            : ID(id), numarKilometri(kilometri), anFabricatie(an), motorDiesel(diesel) {}
    virtual ~Masina() {}
    virtual double calculValoarePolitaDeAsigurare() const = 0;

    int get_anFabricatie() const{
        return anFabricatie;
    }

    bool is_motorDiesel() const{
        return motorDiesel;
    }

    int get_numarKilometri() const{
        return numarKilometri;
    }
};
