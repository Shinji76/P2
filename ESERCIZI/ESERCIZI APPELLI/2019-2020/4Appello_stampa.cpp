#include <iostream>
using std::cout;
using std::endl;

class A {
	bool x;
public:
	virtual ~A() {};
};

class B {
	bool y;
public:
	virtual void f() const { cout << "B::f ";}
};

class C: public A {};

class D: public B {
public:
	void f() const { cout << "D::f ";}
};

class E: public D {
public:
	void f() const { cout << "E::f ";}
};

template<class T>
void Fun(const T& ref) {
	const B* pB = dynamic_cast<const B*>(&ref);
	const E* pE = dynamic_cast<const E*>(&ref);

	if(dynamic_cast<const C*>(&ref)) {
		cout << "C ";
		ref.f();
		return;
	}
	if(pE) {
		cout << "E ";
		pE->f();
		return;
	}
	if(pB) {
		cout << "B ";
		pB->f();
		return;
	}
	if(dynamic_cast<const A*>(&ref)) {
		cout << "A "; return;
	}
	if(dynamic_cast<const D*>(&ref)) {
		cout << "D "; return;
	}
}

C c; D d; E e;
A& a1 = c;
B& b1 = d;
B& b2 = e;
B* b3 = new B();
D& d1 = e;
D* pd1 = dynamic_cast<E*>(&b2);
D* pd2 = dynamic_cast<D*>(&b2);

int main() {
//	Fun<A>(c); 				//STAMPA: NON COMPILA
//	Fun(a1); 				//STAMPA: NON COMPILA
	Fun(b1); 				//STAMPA: B D::f
//	Fun<D>(e); 				//STAMPA: E E::f
//	Fun(b2); 				//STAMPA: E E::f
//	Fun<E>(e); 				//STAMPA: E E::f
//	Fun(*b3); 				//STAMPA: B B::f
	Fun(*pd1); 				//STAMPA: E E::f
//	Fun(e); 				//STAMPA: E E::f
}
