#include "carta.h"

Carta::~Carta()
{
    delete this;
}

unsigned int Carta::getID() const {
    return ID;
}
