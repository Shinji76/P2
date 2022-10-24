#ifndef bolletta_h
#define bolletta_h
#include <iostream>
#include "telefonata.h"

class bolletta {
public:
    bolletta();
    bool Vuota() const;
    void Aggiungi_telefonata(const telefonata&);
    void Togli_telefonata(const telefonata&);
    telefonata Estrai_una();
    bolletta& operator= (const bolletta&);
    bolletta (const bolletta&);          //ridefinizione costtruttore di copia
    ~bolletta();        //distruttore bolletta (~ = alt+1+2+6)
private:
    class nodo {        //classe annidata nodo
    public:
        nodo();
        nodo(const telefonata&, nodo*);
        telefonata info;
        nodo* next;
        ~nodo();
    };
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