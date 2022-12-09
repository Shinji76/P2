#include "carta_mostro.h"

//costruttore mostro
Carta_mostro::Carta_mostro(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe,
    const unsigned int attacco, const unsigned int difesa):
    Carta(ID, nome, effetto, mana, rarita, classe), 
    attacco(attacco), difesa(difesa) {
        std::cout << "prova" << std::endl;
    }
