/*
Si richiamano i seguenti fatti concernenti la libreria di I/O standard.
• ios è la classe base astratta e virtuale della gerarchia di tipi della libreria di I/O;
la classe istream é derivata direttamente e virtualmente da ios;
la classe ifstream è derivata direttamente da istream.
• ios rende disponibile un metodo costante e non virtuale bool fail() con il seguente comportamento:
	una invocazione s.fail() ritorna true se e solo se lo stream s è in uno stato di fallimento (cioè, il fail bit di s vale 1).
• istream rende disponibile un metodo non costante e non virtuale long tellg() con il seguente comportamento:
	una invocazione s.tellg():
		1. se s è in uno stato di fallimento allora ritorna -1;
		2. se s non è in uno stato di fallimento, ritorna la posizione della testina di input di s.
• ifstream rende disponibile un metodo costante e non virtuale bool is_open() con il seguente comportamento:
	una invocazione s.is_open() ritorna true se e solo se il file associato allo stream s è aperto.
Definire una funzione long Fun(const ios&) con il seguente comportamento:
una invocazione Fun(s):
	(1) se s è in uno stato di fallimento lancia una eccezione di tipo Fallimento, dove la classe Fallimento va esplicitamente definita;
	(2) se s non è in uno stato di fallimento allora:
		(a) se s non è un ifstream ritorna -2;
		(b) se s è un ifstream ed il file associato non è aperto ritorna -1;
		(c) se s è un ifstream ed il file associato è aperto ritorna la posizione della cella corrente di input di s.
*/
#include "3Appello_io.h"
#include <iostream>
#include <typeinfo>

class Fallimento {
public:
	Fallimento() {
		std::cout << "ho fallito";
	}
};

long Fun(const ios& s) {
	if(const_cast<ios&>(s).fail()) {
		std::cout << "sistemare";
		throw Fallimento();
	}
	if(typeid(s) != typeid(ifstream)) {
		return -2;
	}
    else if(typeid(s) == typeid(ifstream) && !(dynamic_cast<ifstream&>(const_cast<ios&>(s))).is_open()) {
        return -1;
    }
    else if(typeid(s) == typeid(ifstream) && (dynamic_cast<ifstream&>(const_cast<ios&>(s))).is_open()) {
        return (dynamic_cast<istream&>(const_cast<ios&>(s))).tellg();
    }
}
