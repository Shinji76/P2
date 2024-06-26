#include <iostream>
using std::cout;

class A {
public:
	virtual void f() const {cout <<"A::f ";}
	virtual void g() {cout <<"A::g "; m(); }
	virtual void h() {cout <<"A::h "; f();}
	void m() {cout <<"A::m "; f();}
	virtual A* n() {cout <<"A::n "; return this;}
};

class B: public A {
public:
	virtual void f() const {cout <<"B::f ";}
	void g() {cout <<"B::g "; A::n();}
	virtual void m() {cout <<"B::m "; f();}
	A* n() {cout <<"B::n "; return this;}
};

class D: public B {
public:
	B* n() {cout <<"D::n "; return this;}
protected:
	void r() {cout <<"D::r ";}
public:
	void m() {cout <<"D::m "; f(); r();}
};

class C: public A {
public:
	virtual void f() {cout <<"C::f ";}
	void g() const {cout <<"C::g "; g();}
	void m() {cout <<"C::m "; g(); f();}
};

//A* q1 = new D(); 
//A* q2 = new B(); 
//A* q3 = new C(); 
B* q4 = new D(); 
//const A* q5 = new C();

int main() {
//	q1->f();								//STAMPA: B::f
//	q1->g();								//STAMPA: B::g A::n
//	q2->h();								//STAMPA: A::h B::f
//	q2->m();								//STAMPA: A::m B::f
//	q3->g();								//STAMPA: A::g A::m A::f
//	q3->h();								//STAMPA: A::h A::f
//	q4->m();								//STAMPA: D::m B::f D::r
//	q4->g();								//STAMPA: B::g A::n
//	(q3->n())->m();							//STAMPA: A::n A::m A::f
//	(q3->n())->n()->f();					//STAMPA: A::n A::n A::f
	(q4->n())->m();							//STAMPA: D::n D::m B::f D::r		ERRORE
//	(q5->n())->f();							//STAMPA: NON COMPILA
//	(dynamic_cast<B*>(q1))->m();			//STAMPA: D::m B::f D::r
//	(static_cast<C*>(q2))->g();				//STAMPA: RUNTIME ERROR
//	(static_cast<B*>(q3->n()))->f();		//STAMPA: RUNTIME ERROR				ERRORE
}

// RISULTATO 13/15