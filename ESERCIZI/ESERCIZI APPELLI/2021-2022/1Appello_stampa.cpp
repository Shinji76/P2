#include <iostream>
using std::cout;

class Z {
public:
	Z(int x) {}
};

class A {
public:
	A() {cout << "A() ";}
	~A() {cout << "~A() ";}
};

class B : public A {
public:
	B() {cout << "B() ";}
	~B() {cout << "~B() ";}
	void f(int) {cout << "B::f(int) "; f(3.14);}
	virtual void f(double) {cout << "B::f(double) ";}
	virtual B* f(Z) {cout << "B::f(z) "; return this;}
};

class C: virtual public B {
public:
	C() {cout << "C() ";}
	virtual ~C() {cout << "~C() ";}
	virtual void f(const int&) {cout << "C::f(const int&) ";}
	virtual C* f(Z) {cout << "C::f(Z) "; return this;}
};

class D: virtual public B {
public:
	D() {cout << "D() ";}
	~D() {cout << "~D() ";}
	D* f(Z) {cout << "D::f(Z) "; f(3.14); return this;}
	virtual void f(double) {cout << "D::f(double) ";}
};

class E: public C {
public:
	E() {cout << "E() ";}
	~E() {cout << "~E() ";}
	virtual void f() {cout << "E::f() "; C::f(Z(1));}
	C* f(Z) {cout << "E::f(Z) "; f(); return this;}
	E(const E& e) {cout << "Ec ";}
};

class F: public E, public D {
public:
	F() {cout << "F() ";}
	~F() {cout << "~F() ";}
	void f() const {cout << "F() ";}
	F* f(Z) {cout << "F::f(Z) "; return this;}
	void f(double) {cout << "F::f(double) ";}
};

//A* pa = new F;
//D* pd = new D;
//E* pe = new E;
F* pf = new F;
//B* pb1 = pd;
B *pb2 = pf;
//C* pc = pf;

int main() {
//  F* puntF = new F;				// STAMPA: A() B() C() E() D() F()
//  E* puntE = new E(*pe);			// STAMPA: A() B() C() Ec
//  pb2->f(8);						// STAMPA: B::f(int) F::f(double)
//  pa->f(5.1);						// STAMPA: NON COMPILA                      //ERRORE
//  pb1->f(Z(7));					// STAMPA: D::f(Z) D::f(double)
//  if(typeid(pb2) == typeid(F))	// STAMPA: F::f(Z)                          //ERRORE
//  	pb2->f(Z(1));				
//  static_cast<E*>(pc)->f();		// STAMPA: E::f() C::f(Z)
//  pe->f(9);						// STAMPA: E::f(Z) E::f() C::f(Z)
//  (pc->f(Z(3))->f(2));			// STAMPA: F::f(Z) C::f(const int&)
//  (pb2->f(Z(2))->f(3));			// STAMPA: F::f(Z) B::f(int) F::f(double)
//  delete pb2;						// STAMPA: ~B() ~A()                        //ERRORE
//  delete pe;						// STAMPA: ~E() ~C() ~B() ~A()
}

//RISULTATO: 9/12