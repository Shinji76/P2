#include "Mazzo.h"

Mazzo::Mazzo(
    std::string nome,
    AbstractCard::Classe classe,
    FixedVector<int, 50> n,
    unsigned int count = 0
    ) : nome(nome), classe(classe), numCopie(n), counter(count) {}

void Mazzo::addCard(const AbstractCard& card) {
    if(counter < 20 && (classe == card.getClasse() || card.getClasse() == 0) ) {
        // Rarita 3 = Leggendaria
        if( (card.getRarita() == 3 && numCopie[card.getID()] < 1) || (card.getRarita() != 3 && numCopie[card.getID()] < 2) ) {
            numCopie[card.getID()]++;
            counter++;
        }
    } else {
        //throw qualche errore
    }
}

void Mazzo::removeCard(const AbstractCard& card) {
    if(numCopie[card.getID()] > 0) {
        numCopie[card.getID()]--;
        counter--;
    }
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

FixedVector<int, 50> Mazzo::getNumCopie() const {
    return numCopie;
}

int Mazzo::getCounter() const {
    return counter;
}
