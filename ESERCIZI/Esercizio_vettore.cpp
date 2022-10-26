/*
Definire una classe VETTORE i cui oggetti rappresentano array di interi. Vettore deve includere:
-un costruttore di default
-una operazione di concatenazione che restituisce un nuovo vettore
-un operazione di append
-overloading di uguaglianza
-overloading operatore di output
-overloading operatore di indicizzazione
-costruttore copia profonda
-assegnazione profonda
-distruzione profonda
*/
#include <iostream>
#include "Esericizio_vettore.h"

explicit Vettore::Vettore(int v, unsigned int dim) : A(dim == 0 ? nullptr : new int(dim)), size(dim) {
    for(unsigned int k=0; k<size; k++) {
        A[k] = v;
    }
}

Vettore::Vettore(const Vettore& v) : A(v.copia()), size(v.size) { }

Vettore& Vettore::operator=(const Vettore& v) {
    if(this != &v) {
        delete[] A;
        size = v.size;
        A = v.copia();
    }
    return *this;
}

bool Vettore::operator==(const Vettore& v) const {
    if(size != v.size)
        return false;
    else
        for(unsigned int i=0; i<size; i++) {
            if(A[i] != v.A[i])
                return false;
        }
    return true;
}

int& Vettore::operator[](unsigned int k) const{
    return A[k];
}

unsigned int Vettore::getSize() const {
    return size;
}

std::ostream& operator<<(std::ostream&, const Vettore& v) {
    for(unsigned int k=0; k<; k++) {
        ;
    }
}

Vettore::~Vettore() {
    if(A != nullptr)
        delete[] A;
}

Vettore Vettore::operator+(const Vettore& v) const {        //DA SISTEMARE
    Vettore aux(size + v.size);
    unsigned int k=0;
    for(; k<size; k++) {
        aux.A[k] = A[k];
    }
    for(;k<v.size; k++){
        aux.A[k] = v.A[k-size];
    }
    return aux;
}

void Vettore::append(const Vettore& v) {     //assegnazione profonda
    *this = this->operator+(v);
}    

//diversi studi mostrano come oggi chi vive in una famiglia agiata abbia una chance in più per recuperare le lacune di un sistema scolastico appiattito al ribasso, mentre gli studenti dotati di minori risorse vengono danneggiati da un insegnamento che non dovesse per premiare il merito