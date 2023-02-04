#include "Magia.h"

Magia::Magia(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe)
    : AbstractCard(ID, nome, effetto, mana, rarita, classe) {}
 

unsigned int Magia::getID() const {
    return ;    
}

std::string Magia::getNome() const {
    return ;    
}

std::string Magia::getEffetto() const {
    return ;    
}

unsigned int Magia::getManaCost() const {
    return ;    
}

AbstractCard::Rarita Magia::getRarita() const {
    return ;    
}

AbstractCard::Classe Magia::getClasse() const {
    return ;    
}
