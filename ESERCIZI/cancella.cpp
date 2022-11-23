#include <iostream>

class A {
    double d;
};

class B : virtual public A{

};

class C : virtual public A {

};

class D : public B, public C {

};

int main() {
    std::cout << "size_of(A) ==" << sizeof(A) << std::endl;
    std::cout << "size_of(B) ==" << sizeof(B) << std::endl;
    std::cout << "size_of(C) ==" << sizeof(C) << std::endl;
    std::cout << "size_of(D) ==" << sizeof(D) << std::endl;
}