#include "mazzo.h"

Mazzo::Mazzo() : numCopie{0} {}

void Mazzo::upCounter() {
    if(counter < 20)
    counter++;
}

void Mazzo::downCounter() {
    if(counter > 20)
    counter--;
}

void Mazzo::addCard(const Carta& c) {
    if(numCopie[c.getID()] < 2) {
        numCopie[c.getID()]++;
        upCounter();
    }
}

void Mazzo::removeCard(const Carta& c) {
    if(numCopie[c.getID()] > 0) {
        numCopie[c.getID()]--;
        downCounter();
    }
}
