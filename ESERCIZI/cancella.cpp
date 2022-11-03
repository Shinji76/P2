#include <iostream>

class C {
private:
    int dato;
public:
    C(int);
    static int cont;
};

//file.cpp
int C::cont = 0;
C::C(int n) {cont++; dato = n;}

int main() {
    C c1(1), c2(2);
    std::cout << C::cont << std::endl;
}