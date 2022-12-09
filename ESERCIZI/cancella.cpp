#include <iostream>
#include<unordered_map>
#include "carta.h"
#include "carta_mostro.h"

int main() {
    std::unordered_map<unsigned int, unsigned int> map;

    Carta_mostro::Carta_mostro dragone(15, "drago", "nessuno", 3, "epico", "mago", 5, 6);

    map[Carta::getID()] = 1;
}