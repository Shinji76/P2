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
    }
}

int main() {
    A a; B b; C c; D d; E e;
    if(dynamic_cast<B*> (&e))
        cout << "ciao";
    
}