#ifndef telefonata_h
#define telefonata_h
#include <iostream>
#include "orario.h"

class telefonata {
private:
    orario inizio, fine;
    int numero;
public:
    telefonata();
    telefonata(orario, orario, int);
    orario Inizio() const;
    orario Fine() const;
    int Numero() const;
    bool operator==(const telefonata&);
};

std::ostream operator<<(std::ostream&, const telefonata&);
#endif