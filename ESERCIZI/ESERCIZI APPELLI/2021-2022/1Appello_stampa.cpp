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
	void f(int) {cout << "B::f(int) "; f(3.14);}
	virtual void f(double) {cout << "B::f(double) ";}
	virtual B* f(Z) {cout << "B::f(z) "; return this;}
	B() {cout << "B() ";}
	~B() {cout << "~B() ";}
};

class C: virtual public B {
public:
	virtual void f(const int&) {cout << "C::f(const int&) ";}
	virtual C* f(Z) {cout << "C::f(Z) "; return this;}
	C() {cout << "C() ";}
	virtual ~C() {cout << "~C() ";}
};

class D: virtual public B {
public:
	D* f(Z) {cout << "D::f(Z) "; f(3.14); return this;}
	virtual void f(double) {cout << "D::f(double) ";}
	D() {cout << "D() ";}
	~D() {cout << "~D() ";}
};

class E: public C {
public:
	virtual void f() {cout << "E::f() "; C::f(Z(1));}
	C* f(Z) {cout << "E::f(Z) "; f(); return this;}
	E(const E& e) {cout << "Ec ";}
	E() {cout << "E() ";}
	~E() {cout << "~E() ";}
};

class F: public E, public D {
public:
	void f() const {cout << "F() ";}
	F* f(Z) {cout << "F::f(Z) "; return this;}
	void f(double) {cout << "F::f(double) ";}
	F() {cout << "F() ";}
	~F() {cout << "~F() ";}
};

A* pa = new F;
D* pd = new D;
E* pe = new E;
F* pf = new F;
B* pb1 = pd;
B *pb2 = pf;
C* pc = pf;

int main() {
F* puntF = new F;				// STAMPA: A() B() C() E() D() F()
E* puntE = new E(*pe);			// STAMPA: A() B() C() E()
pb2->f(8);						// STAMPA: B::f(int) F::f(double)
pa->f(5.1);						// STAMPA: NON COMPILA
pb1->f(Z(7));					// STAMPA: D::f(Z) D::f(double)
if(typeid(pb2)==typeid(F))		// STAMPA: NON STAMPA NIENTE
	pb2->f(Z(1));				//
static_cast<E*>(pc)->f();		// STAMPA: E::f() C::f(Z)
pe->f(9);						// STAMPA: E::f(Z) E::f() C::f(Z)
(pc->f(Z(3))->f(2));			// STAMPA: E::f(Z) C::f(const int&)
(pb2->f(Z(2))->f(3));			// STAMPA: F::f(Z) B::f(int) F::f(double)
delete pb2;						// STAMPA: ~B() ~A()
delete pe;						// STAMPA: ~E() ~C() ~B() ~A()
}