#include "AbstractCard.h"

AbstractCard::AbstractCard(
    unsigned int ID,
    std::string nome,
    std::string effetto,
    unsigned int mana,
    Rarita rarita,
    Classe classe,
    std::string image_path
    ) : 
    ID(ID), nome(nome), effetto(effetto),
    mana(mana), rarita(rarita),
    classe(classe), image_path(image_path)
{
}

AbstractCard::~AbstractCard() {
    delete this;
}

unsigned int AbstractCard::getID() const {
    return ID;
}
std::string AbstractCard::getNome() const {
    return nome;
}

std::string AbstractCard::getEffetto() const {
    return effetto;
}

unsigned int AbstractCard::getManaCost() const {
    return mana;
}

AbstractCard::Rarita AbstractCard::getRarita() const {
    return rarita;
}

AbstractCard::Classe AbstractCard::getClasse() const {
    return classe;
}

const std::string AbstractCard::getPath() const {
    return image_path;
}