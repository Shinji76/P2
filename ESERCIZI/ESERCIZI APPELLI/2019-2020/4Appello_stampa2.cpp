#include <iostream>
using std::cout;
using std::endl;

class C {
public:
	C() { cout << "C0 ";}
	C(const C&) { cout << "Cc ";}
	C& operator=(const C& e) {
		cout << "C= ";
		return*this;
	}
};

class D {
public:
	C c;
	D() {cout <<"D0 ";}
	D(const D&) {cout << "Dc ";}
};

class E: public C {
public:
	C c;
	E() { cout << "E0 ";}
	E& operator=(const E& e) {
		*this = e;
		cout << "E= ";
		return *this;
	}
};

class F: public C {
public:
	C* pc;
	F() { cout << "F0 ";}
	F(const F&) { cout << "Fc ";}
	F& operator=(const F& f) {
		C::operator=(f);
		pc = f.pc;
		cout << "F= ";
		return*this;
	}
};

int main(){
//C x1; cout << endl << endl;
//C x2; cout << endl << endl;
//E y1; cout << endl << endl;
//E y2; cout << endl << endl;
//F z1; cout << endl << endl;
//F z2; cout << endl << endl;

//	D d1;					//STAMPA: C0 D0 			
//	D d2(d1);				//STAMPA: C0 Dc				ERRORE(corretto)
//	E e1;					//STAMPA: C0 C0 E0			
//	E e2 = y1;				//STAMPA: Cc				ERRORE(corretto)
//	y1 = y2;				//STAMPA: RunTimeError		ERRORE(corretto)				
//	F*pF = new F();			//STAMPA: C0 F0				
//	F f = z1;				//STAMPA: C0 Fc				
//	z1 = z2;				//STAMPA: C= F=				
//	x1 = y1;				//STAMPA: C=				ERRORE(corretto)
//	z1 = x1; 				//STAMPA: NON COMPILA		ERRORE(corretto)
}

// RISULTATO: 5/10
