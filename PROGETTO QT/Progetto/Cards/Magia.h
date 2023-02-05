#ifndef MAGIA_H
#define MAGIA_H

#include "AbstractCard.h"

class Magia : public AbstractCard {
private:

public:
    //costruttore magia
    Magia(
        const unsigned int ID,
        const std::string nome,
        const std::string effetto,
        const unsigned int mana,
        const Rarita rarita,
        const Classe classe
    );

    unsigned int getID() const override;
    std::string getNome() const override;
    std::string getEffetto() const override;
    unsigned int getManaCost() const override;
    Rarita getRarita() const override;
    Classe getClasse() const override;

};


#endif // MAGIA_H
