#include "Mazzo.h"

Mazzo::Mazzo(
    std::string nome,
    AbstractCard::Classe classe,
    FixedVector<int> numCopie,
    unsigned int count
    ) : nome(nome), classe(classe), numCopie(numCopie), counter(count) {}

Mazzo::Mazzo() {}

void Mazzo::addCard(unsigned int id) {
    numCopie[id]++;
    counter++;
}

void Mazzo::removeCard(unsigned int id) {
    numCopie[id]--;
    counter--;
}

std::string Mazzo::getNomeMazzo() const {
    return nome;
}

void Mazzo::setNomeMazzo(std::string set) {
    nome = set;
}

AbstractCard::Classe Mazzo::getClasse() const {
    return classe;
}

void Mazzo::setClasse(AbstractCard::Classe set) {
    classe = set;
}

FixedVector<int> Mazzo::getNumCopie() const {
    return numCopie;
}

int Mazzo::getCounter() const {
    return counter;
}

bool Mazzo::isFull(const AbstractCard* card) {
    if(card->getRarita() == AbstractCard::Rarita::Leggendaria && numCopie[card->getID()] == 1 ) {
        return true;
    }
    else if(numCopie[card->getID()] == 2) {
        return true;
    }
    return false;
}