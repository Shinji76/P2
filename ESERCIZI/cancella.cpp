using namespace std;
#include <iostream>

class Z {
public:
    Z() { cout << "Z0 ";}
    Z(double d) { cout << "Z1 ";}
};

class C {
private:
    int x;
    Z w;
public:
    C() : w(6.28), x(8) {cout << x << " C0 ";}   //costruttore C default
    C(int z) : x(z) {cout << x << " C1 ";}       //costruttore C interi
};

class D : public C {
private:
    int y;
    Z z;
public:
    D() : y(0) {cout << "D0 ";}
    D(int a) : y(a), z(3.14), C(a) {cout << "D1 ";}
};

int main() {
    D d; cout << "UNO\n";
    D e(4); cout << "DUE\n";    
}