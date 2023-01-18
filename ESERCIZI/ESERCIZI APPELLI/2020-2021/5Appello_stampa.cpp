#include <iostream>
using std::cout;
	
class Z {
public:
	Z(int) {}
};

class A {
public:
	A() {cout << "A() ";}
	void f(int) {cout << "A::f(int) "; f(true);}
	virtual void f(bool) {cout << "A::f(bool) ";}
	virtual A* f(Z) {cout << "A::f(Z) "; f(2); return this;}
};

class B: virtual public A {
public:
	B() {cout << "B() ";}
	virtual ~B() {cout << "~B() ";}
	void f(const bool&) {cout << "B::f(const bool&) ";}
	void f(const int&) {cout << "B::f(const int&) ";}
	virtual B* f(Z) {cout << "B::f(Z) "; return this;}
};

class C: virtual public A {
public:
	C() {cout << "C() ";}
	C* f(Z) {cout << "C::f(Z) "; return this;}
};

class D: virtual public A {
public:
	D() {cout << "D() ";}
	~D() {cout << "~D() ";}
	virtual void f(bool) const {cout << "D::f(bool) ";}
	A* f(Z) {cout << "D::f(Z) "; return this;}
};

class E: public C {
public:
	E() {cout << "E() ";}
	~E() {cout << "~E() ";}
	C* f(Z) {cout << "E::f(Z) "; return this;}
};

class F: public B, public E, public D {
public:
	F() {cout << "F() ";}
	~F() {cout << "~F() ";}
	void f(bool) {cout << "F::f(bool) ";}
	F* f(Z) {cout << "F::f(Z) "; return this;}
};

//B *pb1 = new F;
//B *pb2 = new B;
//C *pc = new C;
//E *pe = new E;
//A *pa1 = pc;
//A *pa2 = pe;
A *pa3 = new F;


int main() {
//	pb2->f(3);									//STAMPA: B::f(const int&)
//	(pa2->f(Z(3)))->f(4);						//STAMPA: E::f(Z) A::f(int) A::f(bool)
//	(pc->f(Z(3)))->f(4);						//STAMPA: C::f(Z) C::f(Z)						ERRORE(corretto)
//	pa3->f(3);									//STAMPA: A::f(int) F::f(bool)
//	pb1->f(true);								//STAMPA: B::f(const bool&)
//	pa2->f(true);								//STAMPA: A::f(bool)
//	E* puntE = new F;							//STAMPA: A() B() C() E() D() F()				ERRORE(corretto)
	delete pa3;									//STAMPA: NON STAMPA NULLA  					ERRORE(corretto)
//	delete pb1;									//STAMPA: ~F() ~D() ~E() ~B()
//	pa1->f(Z(2));								//STAMPA: C::f(Z)
//	(dynamlc_cast<E*>(pa2))->f(Z(2));			//STAMPA: E::f(Z)
//	(dynamic_cast<C*>(pa3))->f(Z(2));			//STAMPA: F::f(Z)
}

// RISULTATO: 9/12

//il delete di pa3 risulta in un undef_behaviour in quanto in A non è definito il distruttore virtuale, stiamo provando a distruggere un oggetto di una derivata con una base senza distruttore virtuale, viene conseguenza chiamato quello standard che non manda il programma in errore ma fa cose diverse a seconda del compilatore in cui viene compilato