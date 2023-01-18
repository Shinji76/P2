#include<iostream>
using std::cout;

class A {
public:
	A() {cout << "A() ";}
};

class B: virtual public A {
public:
	B() {cout << "B() ";}
};

class C: virtual public A {
public:
	C(): A() {cout << "C() ";}
};

class D: virtual public B, virtual public C {
public:
	D(): C(), B() {cout << "D() ";}
};	

/*--------------------------------------------------------------QUESITI---------------------------------------------------------------------*/

/*
class E: virtual public B {
public:
	E() {cout << "E() ";}
}; 
class F: public E, virtual public C {
public:
	F() {cout << "E() ";}
}; 
*/
//RISPOSTA 1: A() B() C() E() F() 

/* 
class E: public B {
public:
	E() {cout << "E() ";}
}; 
class F: virtual public E, virtual public C {
public:
	F() {cout << "F() ";}
}; 
*/
//RISPOSTA 2: A() B() E() C() F()


/*
class E: public D {
public:
	E() : B() {cout << "E() ";}
}; 
class F: public E {
public:
	F() {cout << "F() ";}
}; 
*/
//RISPOSTA 3: A() B() C() D() E() F()

/*
class E: public D {
public:
	E(): B() {cout << "E() ";}
}; 
class F: virtual public E {
public:
	F() {cout << "F() ";}
};
*/ 
//RISPOSTA 4: A() B() C() D() E() F()


/* 
class F: public B, virtual public C {
public:
	F() {cout << "F() ";}
}; 
*/
//RISPOSTA 5: A() C() B() F()


class E: public B {
public:
	E() {cout << "E() ";}
};
class F: public E, virtual public C {
public:
	F() {cout << "F() ";}
}; 
//RISPOSTA 6: A() C() B() E() F()




int main() {
	F f;
}