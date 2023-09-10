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

void Mazzo::setClasse(AbstractCard::Classe set) {
    classe = set;
}

std::string Mazzo::getNome() const {
    return nome;
}

void Mazzo::setNome(std::string nome) {
    nome = nome;
}

AbstractCard::Classe Mazzo::getClasse() const {
    return classe;
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
    nome = "";
}