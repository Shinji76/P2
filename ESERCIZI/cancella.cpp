#include <iostream>


class A {
private:
    class nested {
    public:
        std::string nome;
    };
};

class B : public nested {

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