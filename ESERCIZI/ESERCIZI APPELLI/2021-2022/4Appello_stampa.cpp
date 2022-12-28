#include <iostream>
using std::cout;

class Z {
public:
	Z(int x) {}
};

class A {
public:
	A() {cout <<"A() ";}
	void f(int) {cout << "A::f(int) "; f(true);}
	virtual void f(bool) {cout <<"A::f(bool) ";}
	virtual A*f(Z) {cout <<"A::f(Z) "; f(2); return this;}
};
	
class B: virtual public A {
public:
	B() {cout <<"B() ";}
	void f(const bool&){cout<< "B::f(const bool&) ";}
	void f(const int&){cout<< "B::f(const int&) ";}
	virtual B* f(Z) {cout <<"B::f(Z) "; return this;}          
	virtual ~B() {cout << "~B() ";}
};

class C: virtual public A {
public:
	C*f(Z){cout <<"C::f(Z) "; return this;}
	C() {cout <<"C() ";}
};

class D: virtual public A {
public:
	~D() {cout <<"~D() ";}
	D() {cout <<"D() ";}
	virtual void f(bool) const {cout <<"D::f(bool) ";}
	A*f(Z) {cout << "D::f(Z) "; return this;}
};

class E: public C {
public:
	~E() {cout <<"~E() ";}
	E() {cout <<"E() ";}
	C*f(Z){cout <<"E::f(Z) "; return this;}
};

class F: public B, public E, public D {
public:
	F() {cout <<"F() ";} 
	~F() {cout <<"~F() ";}
	void f(bool){cout<< "F::f(bool) ";}
	F*f(Z){cout <<"F::f(Z) "; return this;}
};

//B*pb = new B;
//C*pc = new C;
//D*pd = new D;
//E*pe = new E;
//F*pf = new F;
B*pb1= new F;
//A*pa1=pb;
//A*pa2=pc;
//A*pa3=pd;
//A*pa4=pe;
//A*pa5=pf;

int main() {
//	pa3->f(3);								//STAMPA: A::f(int) A::f(bool)								/
//	pa5->f(3);								//STAMPA: A::f(int) F::f(bool)								/
//	pb1->f(true);							//STAMPA: B::f(const bool&)									/
//	pa4->f(true);							//STAMPA: A::f(bool)										/
//	pa2->f(Z(2));							//STAMPA: C::f(Z)											ERRORE(corretto)
//	pa5->f(Z(2));							//STAMPA: F::f(Z)											ERRORE(corretto)
//	(dynamic_cast<E*>(pa4))->f(Z(2));		//STAMPA: E::f(Z)											/
//	(dynamic_cast<C*>(pa5))->f(Z(2));		//STAMPA: F::f(Z)											ERRORE(corretto)
//	pb->f(3);								//STAMPA: B::f(const int&)									/
//	pc->f(3);								//STAMPA: C::f(Z)											ERRORE(corretto)
//	(pa4->f(Z(3)))->f(4);					//STAMPA: E::f(Z) A::f(int) A::f(bool)						ERRORE(corretto)
//	(pc->f(Z(3)))->f(4);					//STAMPA: C::f(Z) C::f(Z)									ERRORE(corretto)
//	E*puntE = new F;						//STAMPA: A() B() C() E() D() F()							/
//	delete pa5;								//STAMPA: 													ERRORE(corretto)
	delete pb1;								//STAMPA: ~F() ~D() ~E() ~B()								/
}

// RISULTATO: 8/15