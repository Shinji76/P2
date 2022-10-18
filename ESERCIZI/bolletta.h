#ifndef bolletta_h
#define bolletta_h
#include "telefonata.h"

class bolletta {
public:
    bolletta();
    bool Vuota() const;
    void Aggiungi_telefonata(const telefonata&);
    void Togli_telefonata(const telefonata&);
    telefonata Estrai_una();
private:
    class nodo {        //classe annidata nodo
    public:
        nodo();
        nodo(const telefonata&, nodo*);
        telefonata info;
        nodo* next;
    };
    nodo* first;
    static nodo* copia(nodo*);
    static void distruggi(nodo*);
};
#endif

/* Essendo nella parte private della classe bolletta, la classe nodo non è accessibile all'esterno sia che sia nel private di nodo, sia che sia nel public, quindi possiamo lasciare tutto in public. 
*/