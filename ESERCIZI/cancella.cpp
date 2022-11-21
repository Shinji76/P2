using namespace std;
#include <iostream>

class Z {
public:
    Z() {cout << "Z0 ";}
    Z(const Z& x) { cout << "Zc ";}
};

class C {
private:
    Z w;
public:
    C() {cout << " C0 ";}   //costruttore C default
    C(const C& x) : w(x.w) {cout << "Cc ";}       //costruttore C interi
};

class D : public C {
private:
    Z z;
public:
    D() {cout << "D0 ";}
};

int main() {
    D d; cout << "UNO\n";
    D e = d; cout << "DUE\n";    
}