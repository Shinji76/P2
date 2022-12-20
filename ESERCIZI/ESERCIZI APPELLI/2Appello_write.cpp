class Z {
private:
	int x;
};

class B {
private:
	Z bz;
};

class C: virtual public B {
private:
	Z cz;
};

class D: public C {
};

class E: virtual public B {
public:
	Z ez;
	E& operator=(const E& e) {	// ridefinizione assegnazione standard di E
		B::operator=(e);
		ez = e.ez;
		return *this;
	}
};

class F: public D, public E {
private:
	Z*fz;
public:
    // ridefinizione del costruttore di copia profonda di F
	F(const F& f): B(f), D(f), E(f), fz(f.fz != nullptr ? new Z(*f.fz) : nullptr)  {}
	
    ~F() {						// ridefinizione del distruttore profondo di F
        delete fz;
	}

	F& clone(const F& f) {		// definizione del metodo di clonazione di F
        
	}
};