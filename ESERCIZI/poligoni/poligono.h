#ifndef POL_H
#define POL_H

class punto {
private:
    double x, y;
public:
    punto(double a = 0, double b = 0) : x(a), y(b) {}
    static double lung(const punto& p1, const punto& p2);
};

class poligono {
protected:
    unsigned int n_vertici;
    punto* pp;  
public:
    poligono (unsigned int n, const punto v[]);
    ~poligono();
    poligono(const poligono&);
    poligono& operator=(const poligono&);
    double perimetro() const;
};

//va ridefinito costruttore copia profonda, assegnazione profonda e distruzione profonda.
#endif