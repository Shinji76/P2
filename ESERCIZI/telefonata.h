#ifndef telefonata_h
#define telefonata_h
#include <iostream>
#include "orario.h"

class telefonata {
private:
    orario inizio, fine;
    int numero;
public:
    telefonata(orario, orario, int);
    telefonata();
    orario Inizio() const;
    orario Fine() const;
    int numero() const;
    bool operator== (const telefonata&) const;
};

std::ostream operator<<(std::ostream&, const telefonata&);
#endif