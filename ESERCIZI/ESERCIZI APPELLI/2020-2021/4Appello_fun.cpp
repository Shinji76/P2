/*
Esercizio Gerarchia:
Definire una unica gerarchia di classi che includa:
(1) Una unica classe base polimorfa A alla radice della gerarchia;
(2) Una classe derivata astratta B;
(3) Una sottoclasse C di B che sia concreta;
(4) Una classe D che non permetta la costruzione pubblica dei suoi oggetti, ma solamente la costruzione di oggetti di D che siano sottoggetti; 
(5) una classe E definita mediante derivazione multipla a diamante con base virtuale, che abbia D come supertipo, e con l'assegnazione ridefinita pubblicamente con comportamento identico a quello dell'assegnazione standard di E. 
*/

class A {       		//base polimorfa
public:
	virtual ~A() {}
};

class B : virtual public A {	//derivata astratta
public:
	virtual void Fun() = 0;
};

class C : public B {	//derivata concreta
	void Fun() override {}
};

class D : virtual public A {
	D() {}
};

class E : public C, public D {
	E& operator=(const E& e) {
		C::operator=(e);
		D::operator=(e);
		return *this;
	}
};