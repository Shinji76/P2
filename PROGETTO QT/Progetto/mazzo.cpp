#include "Mazzo.h"

Mazzo::Mazzo(Fixed_vector<int> n, unsigned int c=0) : numCopie(n), counter(c) {}

void Mazzo::upCounter() {
    if(counter < 20)
    counter++;
}

void Mazzo::downCounter() {
    if(counter > 20)
    counter--;
}

void Mazzo::addCard(const AbstractCard& c) {
    if(numCopie[c.getID()] < 2) {
        numCopie[c.getID()]++;
        upCounter();
    }
}

void Mazzo::removeCard(const AbstractCard& c) {
    if(numCopie[c.getID()] > 0) {
        numCopie[c.getID()]--;
        downCounter();
    }
}
