#include "AbstractCard.h"

AbstractCard::~AbstractCard()
{
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
    return manaCost;
}

AbstractCard::Rarita AbstractCard::getRarita() const {
    return rarita;
}

AbstractCard::Classe AbstractCard::getClasse() const {
    return classe;
}

std::string AbstractCard::getPath() const {
    return image_path;
}