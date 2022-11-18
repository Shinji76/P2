#include "quadrato.h"

quadrato::quadrato(const punto v[]) : rettangolo(v) {}

double quadrato::perimetro() const {
    double lato = punto::lung(pp[1], pp[0]);
    return (lato*4);
}

double quadrato::area() const {
    double lato = punto::lung(pp[1], pp[0]);
    return (lato*lato);
}