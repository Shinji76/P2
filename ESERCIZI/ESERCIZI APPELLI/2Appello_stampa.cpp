#include <iostream>
using std::cout;

class B {
protected:
virtual void h() {cout<<"B::h ";}
public:
	virtual void f() {cout <<"B::f "; g(); h();}
	virtual void g() const {cout <<"B::g ";}
	virtual void k() {cout <<"B::k "; h(); m(); }
	void m() {cout <<"B::m "; g(); h();}
	virtual B* n() {cout <<"B::n "; return this;}
};

class C: public B {
public:
virtual void k() {cout <<"C::k "; B::n();}
virtual void m() {cout <<"C::m "; g(); h();}
};

class D: public B {
protected:
	void h() {cout <<"D::h ";}
public:
	virtual void g() {cout <<"D::g ";}
	void k() const {cout <<"D::k "; k();}
	void m() {cout <<"D::m "; g(); h();}
};
	
class E: public C {
protected:
void h() {cout <<"E::h ";}
public:
	void m() {cout <<"E::m "; g(); h();}
	C*n() {cout <<"E::n "; return this;}
};
	
//const B*p1 = new D();
//B*p2 = new C();
B*p3 = new D();
//C*p4 = new E();
//B*p5 = new E();

int main() {
//	p1->g();						// STAMPA: B::g
//	(p1->n())->g();					// STAMPA: non compila
//	p2->f();						// STAMPA: B::f B::g B::h
//	p2->m();						// STAMPA: B::m B::g B::h
//	(static_cast<D*>(p2))->k();		// STAMPA: undefined behaviour
//	p3->k();						// STAMPA: D::k D::k
	p3->f();						// STAMPA: B::f B::g D::h
//	(p3->n())->m();					// STAMPA: 
//	(p3->n())->n()->g();			// STAMPA: 
//	(p4->n())->m();					// STAMPA: 
//	p5->g();						// STAMPA: 
//	p5->k();						// STAMPA: 
//	(dynamic_cast<C*>(p5))->m();	// STAMPA: 
}