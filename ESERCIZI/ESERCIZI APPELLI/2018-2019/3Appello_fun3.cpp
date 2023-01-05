class Z {
public:
    Z(int x=0) {}
};

class B {
private:
    Z bz;
};

class C : virtual public B {
private:
    Z* cz;
};

class D : public C {};

class E : virtual public B {
public:
    Z ez;
}; 

class F: public D, public E {
private:
    Z* pz;
public: // ridefinizione del costruttore di copia di F }; 
    F(const F& f) : pz(f.pz) {}
};
/*
Si considerino le definizioni nel riquadro sopra. Ridefinire (ovviamente senza usare la keyword default) nel riquadro sottostante il costruttore di copia della classe E' in modo tale che il suo comportamento coincida esattamente con quello del costruttore di copia standard di F. 
*/