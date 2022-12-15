#include <iostream>

class prova {
private:
    unsigned int counter ;
public:
    prova(): counter(0) {}
    void upCounter();
    void downCounter();
    unsigned int getCounter();
};

void prova::upCounter() {
    counter++;
}

void prova::downCounter() {
    counter--;
}

unsigned int prova::getCounter() {
    return counter;
}

main() {
    prova x;
    for(int i=0; i<10; i++) {
        x.upCounter();
        std::cout << x.getCounter() << std::endl;
    }
    for(int i=0; i<10; i++) {
        x.downCounter();
        std::cout << x.getCounter() << std::endl;
    }
}