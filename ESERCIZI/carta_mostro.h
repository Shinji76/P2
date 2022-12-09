#ifndef CARTA_MOSTRO_H
#define CARTA_MOSTRO_H

#include "carta.h"

class Carta_mostro : public Carta {
private:
    unsigned int attacco;
    unsigned int difesa;

public:
    //costruttore magia
    Carta_mostro(
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

#endif // CARTA_MOSTRO_H