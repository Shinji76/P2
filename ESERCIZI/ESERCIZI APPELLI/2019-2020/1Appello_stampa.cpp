#include <iostream>
using std::cout;

class A {
protected: 
	virtual void r() {cout<< "A::r ";}
public:
	virtual void g() const {cout << "A::g ";} 
	virtual void f() {cout << "A::f "; g(); r();} 
	void m() {cout << "A::m "; g(); r();}
	virtual void k() {cout << "A::k "; r(); m(); } 
	virtual A* n() {cout << "A::n "; return this;}
};

class B: public A { 
public:
	virtual void g() const {cout << "B::g ";}
	virtual void m() {cout << "B::m "; g(); r();}
	void k() {cout << "B::k "; A::n();}
	A* n(){cout << "B::n "; return this;}
};

class D: public B { 
protected:
	void r() {cout << "D::r ";} 
public:
	B* n() {cout << "D::n "; return this;} 
	void m() {cout << "D::m "; g(); r();}
};

class C: public A {
protected:
	void r() {cout << "C::r ";}
public:
	virtual void g() {cout << "C::g ";}
	void m() {cout << "C::m "; g(); r();}
	void k() const {cout << "C::k "; k();}
};

	A* p1 = new D(); 
	A* p2 = new B(); 
	A* p3 = new C(); 
	B* p4 = new D(); 
	const A* p5 = new C();
	
int main() {
	
//	p1->k();							//STAMPA: B::k A::n
//	p2->f();							//STAMPA: A::f B::g A::r
//	p2->m();							//STAMPA: A::m B::g A::r
//	p3->k();							//STAMPA: A::k C::r A::m A::g C::r
//	p3->f();							//STAMPA: A::f A::g C::r
//	p5->g();							//STAMPA: A::g
//	(p3->n())->m();						//STAMPA: A::n A::m A::g C::r
//	(p3->n())->n()->g();				//STAMPA: A::n A::n A::g
//	(p4->n())->m();						//STAMPA: D::n A::m B::g D::r			ERRORE(risolto)
//	(p5->n())->g();						//STAMPA: NON COMPILA
//	(dynamic_cast<B*>(p1))->m();		//STAMPA: D::m B::g D::r
	(static_cast<C*>(p2))->k();			//STAMPA: undef behaviour
}

// RISULTATO: 11/12