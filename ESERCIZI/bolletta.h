#ifndef bolletta_h
#define bolletta_h
#include <iostream>
#include "telefonata.h"

class bolletta {
private:
    class nodo {        //classe annidata nodo
    public:
        nodo();
        nodo(const telefonata&, nodo*);
        telefonata info;
        nodo* next;
        ~nodo();
    };
public:
    class iteratore {
    friend class bolletta;
    private:
        bolletta::nodo* punt;
    public:
        bool operator== (const iteratore&) const;
        bool operator!= (const iteratore&) const;
        iteratore& operator++();        //operator++ prefisso
        iteratore operator++(int);      //operator++ postfisso
    };
    bolletta();
    ~bolletta();        //distruttore bolletta (~ = alt+1+2+6)
    bolletta (const bolletta&);          //ridefinizione costtruttore di copia
    bolletta& operator= (const bolletta&);      //assegnazione profonda
    bool Vuota() const;
    void Aggiungi_telefonata(const telefonata&);
    void Togli_telefonata(const telefonata&);
    telefonata Estrai_una();
    iteratore begin() const;
    iteratore end() const;
    telefonata& operator[] (const iteratore&) const;
    nodo* first;
    static nodo* copia(nodo*);
    static void distruggi(nodo*);
    static nodo* copia_rec(nodo*);
    static void distruggi_rec(nodo*);
};

std::ostream operator<<(std::ostream&, const bolletta&);

#endif

/* Essendo nella parte private della classe bolletta, la classe nodo non è accessibile all'esterno sia che sia nel private di nodo, sia che sia nel public, quindi possiamo lasciare tutto in public. 
*/