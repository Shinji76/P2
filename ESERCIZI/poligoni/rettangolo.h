#ifndef RET_H
#define RET_H
#include "poligono.h"

class rettangolo : public poligono {
public:
	rettangolo(const punto v[]);
	double perimetro() const;		//ridefinizione metodo perimetro definito in poligono.h
	double area() const;
};

//ridefiniamo il metodo perimetro perchè abbiamo bisogno di solo 2 lati ed è conveniente ridefinire il metodo piuttosto che fare cose in più
#endif 