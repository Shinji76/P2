#ifndef CARTA_MAGIA_H
#define CARTA_MAGIA_H

#include "carta.h"

class Carta_magia : public Carta {
private:

public:
    //costruttore magia
    Carta_magia(
        const unsigned int ID,
        const std::string nome,
        const std::string effetto,
        const unsigned int mana,
        const Rarita rarita,
        const Classe classe
    );
};

#endif // CARTA_MAGIA_H
