#include "Mostro.h"

//costruttore mostro
Mostro::Mostro(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe,
    const Razza razza, const unsigned int attacco, const unsigned int difesa):
    AbstractCard(ID, nome, effetto, mana, rarita, classe), razza(razza), attacco(attacco), difesa(difesa) {}

