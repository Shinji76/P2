#include "Segreto.h"

Segreto::Segreto(
    const unsigned int ID,
    const std::string nome,
    const std::string effetto,
    const unsigned int mana, 
    const Rarita rarita,
    const Classe classe,
    const std::string image_path
    )
    : AbstractCard(ID, nome, effetto, mana, rarita, classe, image_path) {}

void Segreto::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Segreto::accept(IVisitor& visitor) {
    visitor.visit(*this);
}