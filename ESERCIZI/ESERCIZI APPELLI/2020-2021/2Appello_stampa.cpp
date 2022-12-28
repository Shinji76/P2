#include <iostream>
using std::cout;

class Z {
public:
	Z(int x) {}
};

class A {
public:
	void f(int) {cout << "A::f(int) "; f(true);}
	virtual void f(bool) {cout << "A::f(bool) ";}
	virtual A*f(Z) {cout << "A::f(Z) "; f(2); return this;}
	A() {cout << "A() "; }
};

class B: virtual public A {
public: 
	B() {cout << "B() ";}
	void f(const bool&) {cout << "B::f(const bool&) ";}
	void f(const int&) {cout << "B::f(const int&) ";}
	virtual B*f(Z) {cout << "B::f(Z) "; return this;}
	virtual ~B() {cout << "~B() ";}
};

class C: virtual public A {
public:
	C() {cout << "C() ";}
	C*f(Z) {cout << "C::f(Z) "; return this;}
};

class D: virtual public A {
public:
	D() {cout << "D() ";}
	~D() {cout << "~D() ";}
	virtual void f(bool) const {cout << "D::f(bool) ";}
	A*f(Z) {cout << "D::f(Z) "; return this;}
};

class E: public C {
public:
	E() {cout << "E() ";}
	~E() {cout << "~E() ";}
	C*f(Z) {cout << "E::f(Z) "; return this;}
};

class F: public B, public E, public D {
public:
	F() {cout << "F() "; }
	~F() {cout << "~F() ";}
	void f(bool) {cout << "F::f(bool) ";}
	F*f(Z) {cout << "F::f(Z) "; return this;}
};
	
B*pb1 = new F;
//B*pb2 = new B;
//C*pc = new C;
//E*pe = new E;
//A*pa1 = pc;
//A*pa2 = pe;
//A*pa3 = new F;


int main() {
	
//	pa3->f(3);								//STAMPA: A::f(int) F::f(bool)          
//	pb1->f(true);							//STAMPA: B::f(const bool&)     
//	pa2->f(true);							//STAMPA: A::f(bool)
//	pa1->f(Z(2));							//STAMPA: C::f(Z)
//	(dynamic_cast<E*>(pa2))->f(Z(2));		//STAMPA: E::f(Z)
//	(dynamic_cast<C*>(pa3))->f(Z(2));		//STAMPA: F::f(Z)
//	pb2->f(3);								//STAMPA: B::f(const int&)
//	(pa2->f(Z(3)))->f(4);					//STAMPA: E::f(Z) A::f(int) A::f(bool)      //ERRORE(corretto)
//	(pc->f(Z(3)))->f(4);					//STAMPA: C::f(Z) C::f(Z)
//	E*puntE = new F;						//STAMPA: A() B() C() E() D() F()
//	delete pa3;								//STAMPA: -									//ERRORE(corretto)
	delete pb1;								//STAMPA: ~F() ~D() ~E() ~B()				//ERRORE(corretto)
}

//RISULTATO 9/12