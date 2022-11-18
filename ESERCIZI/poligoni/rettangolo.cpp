#include "rettangolo.h"

rettangolo::rettangolo(const punto v[]) : poligono(4, v) {}

double rettangolo::perimetro() const {
	double base = punto::lung(pp[1], pp[0]);
	double altezza = punto::lung(pp[2], pp[1]);
	return ((base + altezza)*2);
}

double rettangolo::area() const {
   	double base = punto::lung(pp[1], pp[0]);
	double altezza = punto::lung(pp[2], pp[1]);
	return (base * altezza);
}