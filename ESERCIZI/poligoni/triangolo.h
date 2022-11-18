#ifndef TRI_H
#define TRI_H
#include "poligono.h"

class triangolo : public poligono {
public:
    triangolo(const punto v[]);
    double area() const;
};

#endif