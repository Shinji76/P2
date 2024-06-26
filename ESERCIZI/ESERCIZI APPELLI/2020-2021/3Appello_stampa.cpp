#include<iostream>
using std::cout;

class A {
public:
	virtual ~A() {}
};

class B: public A {
};

class C: public A {
};

class D: public C {
};

template<class T>
void Fun(T* pt) {
	bool b = 0;
	try{
		throw T(*pt);
	}
	catch(B) {cout << "B "; b=1;}
	catch(C) {cout << "C "; b=1;}
	catch(D) {cout << "D "; b=1;}
	catch(A) {cout << "A "; b=1;}
	if(!b) cout << "NO ";
}

B b;
C c;
D d;
A *pa1 = &b;
A *pa2 = &d;
B *pb1 = dynamic_cast<B*>(pa1);
B *pb2 = dynamic_cast<B*>(pa2);

int main() {
//	Fun(&c);			// STAMPA: C
//	Fun(&d);			// STAMPA: C
//	Fun(pa1);			// STAMPA: A
//	Fun(pa2);			// STAMPA: A
//	Fun(pb1);			// STAMPA: B
//	Fun(pb2);			// STAMPA: B
//	Fun<A>(pb1);		// STAMPA: A
//	Fun<A>(pa2);		// STAMPA: A
//	Fun<B>(pb1);		// STAMPA: B
//	Fun<C>(pa2);		// STAMPA: NON COMPILA
//	Fun<C>(&d);			// STAMPA: C
//	Fun<D>(pa2);		// STAMPA: NON COMPILA
}
 
//	RISULTATO /12