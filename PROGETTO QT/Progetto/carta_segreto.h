#ifndef CARTA_SEGRETO_H
#define CARTA_SEGRETO_H

#include "carta.h"

class Carta_segreto : public Carta {
public:
Carta_segreto(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe);
};

#endif  //CARTA_SEGRETO_H