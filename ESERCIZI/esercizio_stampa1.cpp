#include<iostream>
using namespace std;

class A {
private:
    void h() {cout << "A::h";}
public:
	virtual void g() {cout << "A::g";}
	
	virtual void f() {cout << "A::f";
	g(); h();}
	
	void m() {cout << "A::m";
	g(); h();}
	
	virtual void k() {cout << "A::k"; 
	g(); h(); m();}

	A* n() {cout << "A::n";
	return this;}
};

class B : public A {
private:
    void h() {cout << "B::h";}
public:
	virtual void g() {cout << "B::g";}

	void m() {cout << "B::m";
	g(); h();}
	
	void k() {cout << "B::k";
		g(); h(); m();}
		
	B* n() {cout << "B::n";
	return this;}
};

B* b = new B();
A* a = new B();

int main() {
	(a->n())->m();
	(a->n())->g();
	(b->n())->g();
	(b->n())->n()->g();
	
	b->f();
	b->m();
	b->k();
	
	a->f();
	a->m();
	a->k();
}