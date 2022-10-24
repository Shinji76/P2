#include "bolletta.h"

bolletta::nodo::nodo() : next(0) { }     //costruttore di default per campo dati info  

bolletta::nodo::nodo(const telefonata& t, nodo* s) : info(t), next(s) { }

bolletta::bolletta() : first(0) { }

bolletta::bolletta(const bolletta& b) : first(copia(b.first)) { }


bolletta::~bolletta() {
    if(first)
        delete first;
}

bolletta::nodo::~nodo() {
    if(next != 0)
        delete next;
}

bool bolletta::Vuota() const {
    return first == 0;
}

void bolletta::Aggiungi_telefonata(const telefonata& t) {
    first = new nodo(t, first);
}

void bolletta::Togli_telefonata(const telefonata& t) {
    nodo* p = first, *prec = nullptr;
    while(p && !(p->info==t)) {
        prec = p;
        p = p->next;
    }
    if (p) {
        if (!prec)
            first = p->next;
        else
            prec->next = p->next;
        delete p;
    }
}

telefonata bolletta::Estrai_una() {     //PRE: la bolletta non deve essere vuota 
    nodo* p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}

bolletta::nodo* bolletta::copia(nodo* p) {
    if (!p)
        return nullptr;
    nodo* primo = new nodo(p->info, 0);
    nodo* q = primo;
    while(p->next) {
        p = p->next;
        q->next = new nodo(p->info, 0);
        q = q->next;
    }
    return primo;
}

void bolletta::distruggi(nodo* p) {
    if(p!=nullptr) {
        nodo*q = p;
        while(p!=nullptr) {
            p = p->next;
            delete q;
            q = p;
        }
    }
}

bolletta::nodo* bolletta::copia_rec(nodo*p) {
    if(!p)
        return nullptr;
    else
        return new nodo(p->info, copia_rec(p->next));
}

void bolletta::distruggi_rec(nodo* p) {
    if(p) {
        distruggi_rec(p->next);
        delete p;
    }
}

bolletta& bolletta::operator=(const bolletta& b) {
    if(this != &b) {
        distruggi(first);
        first = copia(b.first);
    }
    return *this;
}

orario Somma_durate(bolletta b) {
    orario durata;
    while(!b.Vuota()) {
        telefonata t = b.Estrai_una();
    durata = durata + t.Fine() - t.Inizio();
    }
    return durata;
}

bolletta Chiamate_a(int num, bolletta& b) {
    bolletta selezionate, resto;
    while(!b.Vuota()) {
        telefonata t = b.Estrai_una();
        if(t.Numero() == num)
            selezionate.Aggiungi_telefonata(t);
        else
            resto.Aggiungi_telefonata(t);
    }
    b = resto;
    return selezionate;
}

int main () {
    bolletta b1;
    telefonata t1 (orario(9, 23, 12), orario(10, 4, 53), 2121212);
    telefonata t2 (orario(11, 15, 4), orario(11, 22, 1), 3131313);
    telefonata t3 (orario(12, 17, 5), orario(12, 22, 8), 2121212);
    telefonata t4 (orario(13, 46, 5), orario(14, 0, 33), 3131313);
    b1.Aggiungi_telefonata(t4);
    b1.Aggiungi_telefonata(t3);
    b1.Aggiungi_telefonata(t2);
    b1.Aggiungi_telefonata(t1);
    std::cout << b1;
    bolletta b2 = Chiamate_a(2121212, b1);
    std::cout << b1;
    std::cout << b2;
}