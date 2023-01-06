#ifndef MOSTRO_H
#define MOSTRO_H

#include "AbstractCard.h"

class Mostro : public AbstractCard {
private:
    unsigned int attacco;
    unsigned int difesa;

public:
    //costruttore magia
    Mostro(
        const unsigned int ID,
        const std::string nome,
        const std::string effetto,
        const unsigned int mana,
        const Rarita rarita,
        const Classe classe,
        const unsigned int attacco,
        const unsigned int difesa
    );
};

#endif // MOSTRO_H