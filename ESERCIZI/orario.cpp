#include <iostream>
#include "orario.h"

//DEFINIZIONE DEI COSTRUTTORI
orario::orario() {
    sec = 0;
}
orario::orario(int o, int m) {
    if(o < 0 || o > 23 || m < 0 || m > 59)
        sec = 0;    
    else
        sec = o * 3600 + m * 60;
}
orario::orario(int o, int m, int s) {
    if(o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        sec = 0;    
    else
        sec = o * 3600 + m * 60 + s;
}

int orario::Ore() {
    return sec / 3600;
}
int orario::Minuti() {
    return (sec/60) % 60;
}
int orario::Secondi() {
    return sec % 60;
}

orario orario::UnOraPiuTardi() {        //
    orario aux;
    aux.sec = (sec + 3600) % 86400;
    return aux;
}

void orario::AvanzaUnOra() {
    sec = (sec + 3600) % 86400;
}

void orario::StampaSecondi() const {
    std::cout << sec << std::endl;
}

orario orario::operator+(orario o) const {
    orario aux;
    aux.sec = (sec + o.sec) % 86400;
    return aux;
}

orario orario::operator-(orario o) const {
    orario aux;
    aux.sec = (sec - o.sec) % 86400;
    return aux;
}

int main() {
    orario mezzanotte;
    orario adesso(14, 25);
    orario adessoPreciso(14, 25, 47);
    std::cout << adessoPreciso.Secondi() << std::endl;
    std::cout << mezzanotte.Ore() << std::endl;
}