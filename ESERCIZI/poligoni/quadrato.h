#ifndef QUA_H
#define QUA_H
#include "rettangolo.h"

class quadrato: public rettangolo {
public:
	quadrato(const punto v[]);
	double perimetro() const;
	double area() const;
};

#endif