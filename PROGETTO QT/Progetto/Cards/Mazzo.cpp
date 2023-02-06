#include "Mazzo.h"

Mazzo::Mazzo(AbstractCard::Classe cl, Fixed_vector<int> n, unsigned int c=1) : classe(cl), numCopie(n), counter(c) {}

void Mazzo::addCard(const AbstractCard& c) {
    if(counter < 20 && getClasse() == c.getClasse()) {
        // Rarita 3 = Leggendaria
        if(c.getRarita() == 3 && numCopie[c.getID()] < 1 || c.getRarita() != 3 && numCopie[c.getID()] < 2) {
            numCopie[c.getID()]++;
            counter++;
        }
    } else {      
        //throw qualche errore
    }
}

void Mazzo::removeCard(const AbstractCard& c) {
    if(numCopie[c.getID()] > 0) {
        numCopie[c.getID()]--;
        counter--;
    }
}

