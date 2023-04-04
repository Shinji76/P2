#include "Mazzo.h"

Mazzo::Mazzo(AbstractCard::Classe cl, Fixed_vector<int> n, unsigned int count = 0) : classe(cl), numCopie(n), counter(count) {}

void Mazzo::addCard(const AbstractCard& card) {
    if(counter < 20 && (classe == card.getClasse() || card.getClasse() == 0) ) {
        // Rarita 3 = Leggendaria
        if(card.getRarita() == 3 && numCopie[card.getID()] < 1 || card.getRarita() != 3 && numCopie[card.getID()] < 2) {
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

AbstractCard::Classe Mazzo::getClasse() const {
    return classe;
}

void Mazzo::setClasse(AbstractCard::Classe set) {
    classe = set;
}
