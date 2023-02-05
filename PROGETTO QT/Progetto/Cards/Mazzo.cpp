#include "Mazzo.h"

Mazzo::Mazzo(Fixed_vector<int> n, unsigned int c=1) : numCopie(n), counter(c) {}

void Mazzo::addCard(const AbstractCard& c) {
    if(counter < 20) {
        if(c.getRarita() == "Leggendaria" && numCopie[c.getID()] < 1 || c.getRarita() != "Leggendaria" && numCopie[c.getID()] < 2) {
            numCopie[c.getID()]++;
            counter++;
        }
    }
    else {      
        //throw qualche errore
    }
}

void Mazzo::removeCard(const AbstractCard& c) {
    if(numCopie[c.getID()] > 0) {
        numCopie[c.getID()]--;
        counter--;
    }
}

