//#include "2020-2021/2Appello_fun.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::cout;



class Z {
public:
    Z() {cout << "Z0 ";}
    Z(const Z& x) { cout << "Zc ";}
};

class C {
private:
    Z w;
public:
    C() {cout << "C0 ";}   //costruttore C default
    C(const C& x) : w(x.w) {cout << "Cc ";}       //costruttore C interi
};

class D : public C {
private:
    Z z;
public:
    D() {cout << "D0 ";}
    D(const D& d) : C(d), z(d.z) {cout << "Dc ";}
};

class E : public D {
private:
    Z k;
public:
    E() {cout << "E0 ";}
    E(const E& e) : D(e), k(e.k) {cout << "Ec ";}
};


int main() {
    D d; cout << "UNO\n";
    D e = d; cout << "DUE\n";   
    E standard; cout << "TRE\n"; 
    E copia = standard; cout << "QUATTRO\n"; 
}