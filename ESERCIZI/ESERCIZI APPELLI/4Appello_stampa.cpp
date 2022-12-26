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
	virtual  ~B() {cout << "~B() ";}
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
	C*f(Z){cout <<"E::f(Z) "; return this;}
	~E() {cout <<"~E() ";}
	E() {cout <<"E() ";}
};

class F: public B, public E, public D {
public:
	F() {cout <<"F() ";} 
	~F() {cout <<"~F() ";}
	void f(bool){cout<< "F::f(bool) ";}
	F*f(Z){cout <<"F::f(Z) "; return this;}
};

B*pb=new B;
C*pc = new C;
D*pd = new D;
E*pe = new E;
F*pf = new F;
B*pb1= new F;
A*pa1=pb,*pa2=pc,*pa3=pd,*pa4=pe,*pa5=pf;

int main() {
//	pa3->f(3);								//STAMPA: 
//	pa5->f(3);								//STAMPA: 
//	pb1->f(true);							//STAMPA: 
//	pa4->f(true);							//STAMPA: 
//	pa2->f(Z(2));							//STAMPA: 
//	pa5->f(Z(2));							//STAMPA: 
//	(dynamic_cast<E*>(pa4))->f(Z(2));		//STAMPA: 
//	(dynamic_cast<C*>(pa5))->f(Z(2));		//STAMPA: 
//	pb->f(3);								//STAMPA: 
//	pc->f(3);								//STAMPA: 
//	(pa4->f(Z(3)))->f(4);					//STAMPA: 
//	(pc->f(Z(3)))->f(4);					//STAMPA: 
//	E*puntE = new F;						//STAMPA: 
//	delete pa5;								//STAMPA: 
//	delete pb1;								//STAMPA: 
}