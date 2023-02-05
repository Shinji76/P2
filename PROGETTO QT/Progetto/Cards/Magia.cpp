#include "Magia.h"


Magia::Magia(
    const unsigned int ID, const std::string nome, const std::string effetto,
    const unsigned int mana, const Rarita rarita, const Classe classe)
    : AbstractCard(ID, nome, effetto, mana, rarita, classe) {}

void Magia::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Magia::accept(IVisitor& visitor) {
    visitor.visit(*this);
}
