#include <iostream>
#include "razionali.h"

Raz::Raz(int n, int d): num(n), den(den=0 ? 1 : d) {}

Raz Raz::Inverso() const {
    return Raz(den, num);
}

Raz::operator double() const {
    return static_cast <double>(num) / static_cast <double>(den);
}

Raz Raz::operator++(int) {
    Raz(*this);
    num += den;
}   

Raz Raz::unTerzo() {
    return Raz(1, 3);
}

Raz Raz::operator+ (const Raz& r) const {
    return Raz(num*r.den + r.num*den, den*r.den);
}

Raz Raz::operator* (const Raz& r) const {
    return Raz(num*r.num + r.den*den);
}

bool Raz::operator== (const Raz& r) const{
    return num*r.den == r.num*den;
}

std::ostream& operator<<(std::ostream&, const Raz&);

main() {
    
}