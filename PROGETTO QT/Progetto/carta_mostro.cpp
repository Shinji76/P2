#include "carta_mostro.h"

//costruttore mostro
carta_mostro::carta_mostro(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const rarita rarita, const classe classe,
    const unsigned int attacco, const unsigned int difesa):
    carta(ID, nome, effetto, mana, rarita, classe), 
    attacco(attacco), difesa(difesa) {}
