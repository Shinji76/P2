#include "Mazzo.h"

Mazzo::Mazzo(
    AbstractCard::Classe classe,
    FixedVector<int> numCopie,
    unsigned int count
    ) : classe(classe), numCopie(numCopie), counter(count) {}

Mazzo::Mazzo() {}

void Mazzo::addCard(unsigned int id) {
    numCopie[id]++;
    counter++;
}

void Mazzo::removeCard(unsigned int id) {
    numCopie[id]--;
    counter--;
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

void Mazzo::clear() {
    for(int i = 0; i < numCopie.getSize(); i++) {
        numCopie[i] = 0;
    }
    counter = 0;
}