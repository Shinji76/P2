/*
Scrivere un template di classe SmartP<T> di puntatori smart al parametro di tipo T che ridefinisca assegnazione profonda, costruzione di copia profonda e distruzione profonda di puntatori smart.
Il template SmartP<T> dovrà essere dotato della minima interfaccia pubblica (cioè con il minor numero di membri) che permetta di compilare correttamente il seguente codice, la cui esecuzione dovrà provocare esattamente le stampe riportate nei commenti
*/

#include<iostream>
using std::cout;
using std::endl;

template <class T>
class SmartP {
private:
	T *ptr;
public:
	SmartP(const T* t = 0) : ptr( t ? new T(*t) : nullptr) {}
	SmartP(const SmartP& s) : ptr(new T(*s.ptr)) {}
	SmartP& operator=(const SmartP& s) {
		if(this != &s) {
			delete ptr;
			ptr = new T(*s.ptr);
		}		
		return *this;
	}
	~SmartP() {
		if(ptr)
			delete ptr;
	}
	T& operator*() const { return *ptr;}

	bool operator==(const SmartP& s) const {
		return ptr == s.ptr;
	}
};

class C {
public:
	int*p;
	C(): p(new int(5)) {}
};

int main() {
	const int a=1;
	const int*p=&a;
	SmartP<int> r;
	SmartP<int> s(&a);
	SmartP<int> t(s);
	cout << *s << " " << *t << " " << *p << endl;					// 1 1 1
	cout << (s == t) << " " << !(s == p) << endl;					// 0 1
	*s=2;
	*t=3;
	cout << *s << " " << *t << " " << *p << endl;					// 2 3 1
	r=t;*r=4;
	cout << *r << " " << *s << " " << *t << " " << *p << endl;		// 4 2 3 1
	C c;
	SmartP<C> x(&c);
	SmartP<C> y(x);
	cout << (x == y) << endl;										// 0
	cout <<*(c.p) << endl;                                      	// 5
	*(c.p)=6;
	cout <<*(c.p) << endl;											// 6
	SmartP<C>*q = new SmartP<C>(&c);
	delete q;
}