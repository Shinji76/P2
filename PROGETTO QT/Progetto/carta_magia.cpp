#include "carta_magia.h"

Carta_magia::Carta_magia(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe)
    : Carta(ID, nome, effetto, mana, rarita, classe) {}
