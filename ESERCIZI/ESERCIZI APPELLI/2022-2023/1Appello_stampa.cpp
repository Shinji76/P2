#include <iostream>
using std::cout;

class B {
public:
	B() {cout << "B() ";}
	virtual ~B() {cout << "~B() ";}
	virtual void g() const {cout << "B::g ";}
	virtual const B* j() {cout << "B::j "; return this;}
	virtual void k() {cout << "B::k "; j(); m();}
	void m() {cout << "B::m "; g(); j();}
	virtual B& n() {cout << "B::n "; return *this;}
};

class C : virtual public B {
public:
	C() {cout << "C() ";}
	~C() {cout << "~C() ";}
	void g() const {cout << "C::g ";}
	void k() override {cout << "C::k "; B::n();}
	virtual void m() {cout << "C::m "; g(); j();}
	B& n() override {cout << "C::n "; return *this;}
};

class D : virtual public B {
public:
	D() {cout << "D() ";}
	~D() {cout << "~D() ";}
	virtual void g() {cout << "D::g ";}
	const B* j() {cout << "D::j"; return this;}
	void k() const {cout << "D::k "; k();}
	void m() {cout << "D::m "; g(); j();}
};

class E : public C, public D {
public:
	E() {cout << "E() ";}
	~E() {cout << "~E() ";}
	virtual void g() {cout << "E::g ";}
	const E* j() {cout << "E::j"; return this;}
	void m() {cout << "E::m "; g(); j();}
	D& n() final {cout << "E::n "; return *this;}
};

class F : virtual public E {
public:
	F() {cout << "F() ";}
	~F() {cout << "~F() ";}
	F(const F& x) : B(x) {cout << "Fc ";}
	void k() {cout << "F::k "; g();}
	void m() {cout << "F::m "; j();}
};

//	B* p1 = new E();
//	B* p2 = new C();
//	B* p3 = new D();
	C* p4 = new E();
//	const B* p5 = new E();
//	const B* p6 = new F();

int main() {
	(p4->n()).m();      								//STAMPA: 
//	p3->k();        									//STAMPA: 
//	(p3->n()).m();      								//STAMPA: 
//	p2->m();        									//STAMPA: 
//	(p2->j())->g();     								//STAMPA: 
//	C* p = new F(F());      							//STAMPA: 
//	(p1->j())->k();										//STAMPA: NON COMPILA 
//	(dynamic_cast<const F*>(p1->j()))->g();             //STAMPA: NON COMPILA
//	(dynamic_cast<E*>(p5))->j();						//STAMPA: NON COMPILA
//	(dynamic_cast<C*>(const_cast<B*>(p6)))->k();		//STAMPA: 
}

