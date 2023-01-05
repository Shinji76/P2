#include <iostream>
using std::cout;

class A {};
class B {};
class C {};
class D {};

template<class X, class Y>
X* fun(X* p) {
	return dynamic_cast<Y*>(p);
}

A* fun(A* c) {
	dynamic_cast<B*>(c);
}

main() {
	C c;
	fun<A,B>(&c);
	if(fun<A,B>(new C()) == 0) 
		cout << "Bjarne";
	if(dynamic_cast<C*>(new B()) == 0)
		cout << "Stroustrup";
	A* p = fun<D,B>(new D());
}

/*
Supponendo che il main() compili correttamente e stampi la parola "Bjarne Stroupstrup" dedurre le relazioni di sotto-tipaggio delle classi A, B, C, D, indicando con Vero, Falso, Possibile
*/

//  A <= B	
//  A <= C	
//  A <= D	
//  B <= A	
//  B <= C	
//  B <= D	
//  C <= A	
//  C <= B	
//  C <= D	
//  D <= A	
//  D <= B	
//  D <= C	