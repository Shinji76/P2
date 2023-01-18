#include <iostream>
using std::cout;

class A {
public:
	virtual ~A() {}
};

class B: public A {};

class C: public B {};

class D: public B {};

class E: public C {};

char F(A*pa, B& rb) {
	B*p = dynamic_cast<B*> (pa);
	C*q = dynamic_cast<C*> (pa);

	if(dynamic_cast<E*> (&rb)) {
		if(p && q)
			return 'M';
		else
			return 'I';
	}
	if(dynamic_cast<C*> (&rb))
		return 'L';
	if(q)
		return 'A';
	if(p)
		return 'N';
	return 'O';
}

int main() {
	A a; B b; C c; D d; E e;
	cout << F(&c, e) << F(&d, e) << F(&a, c) << F(&c, d) << F(&b, d) << F(&a, d); 
	//			M			I			L			A			N			O
}