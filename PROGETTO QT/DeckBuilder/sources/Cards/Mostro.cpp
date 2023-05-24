#include "Mostro.h"

//costruttore mostro
Mostro::Mostro(
    const unsigned int ID,
    const std::string nome,
    const std::string effetto,
    const unsigned int mana,
    const Rarita rarita,
    const Classe classe,
    const std::string image_path,
    const Razza razza = Comune,
    const unsigned int attacco = 0,
    const unsigned int difesa = 0
    ) : AbstractCard(ID, nome, effetto, mana, rarita, classe, image_path), razza(razza), attacco(attacco), difesa(difesa) {}

//getters
Mostro::Razza Mostro::getRazza() const {
    return razza;
}

unsigned int Mostro::getAttacco() const {
    return attacco;
}

unsigned int Mostro::getDifesa() const {
    return difesa;
}

void Mostro::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Mostro::accept(IVisitor& visitor) {
    visitor.visit(*this);
}
