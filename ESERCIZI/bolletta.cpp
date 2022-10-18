#include "bolletta.h"

bolletta::nodo::nodo() : next(0) {      //costruttore di default per campo dati info

}     

bolletta::nodo::nodo(const telefonata& t, nodo* s) : info(t), next(s) {

}

bolletta::bolletta() : first(0) {

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
    distruggi(first);
    first = copia(b.first);
    return *this;
}