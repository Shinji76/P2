#include <math.h>
#include "triangolo.h"

triangolo::triangolo(const punto v[]) : poligono(3, v) {}

double triangolo::area() const {
    double p = perimetro()/2;
    double a = punto::lung(pp[1], pp[0]);
    double b = punto::lung(pp[2], pp[1]);
    double c = punto::lung(pp[0], pp[2]);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}