#include "mazzo.h"

Mazzo::Mazzo() : numCopie{0} {}

void Mazzo::addCard(const Carta& c) {
    if(numCopie[c.getID()] < 2) {
        numCopie[c.getID()]++;
    }
}

void Mazzo::removeCard(const Carta& c) {
    if(numCopie[c.getID()] > 0) {
        numCopie[c.getID()]--;
    }
}
