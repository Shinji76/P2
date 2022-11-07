#include <iostream>
#include "queue.h"

int main() {
    Queue<int>* pi = new Queue<int>;
    int i;
    for(i = 0; i < 10; i++)
        pi->add(i);
    for(i = 0; i < 10; i++)
        std::cout << pi->remove() << std::endl;
}