/*
Si ricordano le seguenti specifiche riguardanti la libreria standard di IO.

(1)	La classe ios è la classe base polimorfa della gerarchia di tipi per I/O. 
	Un oggetto di ios rappresenta un generico stream. Lo stato di uno stream è un intero in [0,7], dove lo stato 0 significa stato privo di errori, mentre lo stato 2 significa stato di fallimento recuperabile. 
	ios rende disponibile un metodo costante int rdstate() con il comportamento: s.rdstate() ritorna lo stato di s.
	Inoltre ios rende disponibile un metodo void setState (int) con il comportamento: 
	s.setState(x) modifica al valore x lo stato di s.

(2)	La classe istream è derivata direttamente e virtualmente da ios ed i suoi oggetti rappresentano un generico stream di input.
	La classe istream rende disponibile un metodo costante int tellg() con il seguente comportamento:
	i.tellg() ritorna la posizione della testina di input nello stream di input i.

(3)	La classe ostream è derivata direttamente e virtualmente da ios ed i suoi oggetti rappresentano un generico stream di output. 
	La classe ostream rende disponibile un metodo costante int tellp() con il seguente comportamento: 
	o.tellp() ritorna la posizione della testina di output nello stream di output o.

(4)	La classe iostream è derivata direttamente per ereditarietà multipla da istream e ostream ed i suoi oggetti rappresentano uno stream di input/output.

(5)	La classe fstream è derivata direttamente da iostream ed i suoi oggetti rappresentano un generico file stream di I/O.
	La classe fstream rende disponibile un metodo costante bool is_open () con il seguente comportamento: 
	f.is_open() ritorna true se il file stream f è associato a qualche file, altrimenti ritorna false. 
	Inoltre la classe fstream rende disponibile un metodo void close() con il seguente comportamento: 
	f.close() disassocia il file correntemente associato al file stream f, mentre se f non è associato ad alcun file allora non provoca effetti. 

Definire una funzione vector<fstream*> Fun(const vector<const ios*>&) con il seguente comportamento: 
in ogni invocazione Fun(v) la funzione deve soddisfare le seguenti specifiche:
	(a)	A tutti gli stream di input/output puntati da un puntatore contenuto nel vector v che abbiano la posizione della testina di input maggiore della posizione della testina di output, modifica lo stato in uno stato di fallimento recuperabile.

	(b)	ritorna un vector di puntatori a file stream contenente tutti e soli i puntatori a file stream contenuti nel vector v che sono in uno stato privo di errori e che hanno un qualche file a loro associato; tali file stream devono inoltre essere disassociati al file a loro associato.
	Se invece non vi è nessun file stream privo di errori e che ha un qualche file associato allora viene sollevata una eccezione di tipo std::exception.
*/

#include<vector>
#include<iostream>
#include "4Appello_fun.h"
using std::vector;

vector<fstream*> Fun(const vector<const ios*>& v) {
	auto cit = v.begin();
	vector<fstream*> aux;
	for(cit; cit != v.end(); cit++) {
		//if tellg > tellp
		if( (dynamic_cast<istream*>(const_cast<ios*>(*cit)))->tellg() < (dynamic_cast<ostream*>(const_cast<ios*>(*cit)))->tellp() ) {
			const_cast<ios*>(*cit)->setState(2);
		}
	}
	for(cit; cit != v.end(); cit++) {
		ios* i = const_cast<ios*>(*cit);
		if( i->rdstate() != 2 && dynamic_cast<fstream*>(i)->is_open() ) {
			aux.push_back(dynamic_cast<fstream*>(i));
			dynamic_cast<fstream*>(i)->close();
		}
		else if(!dynamic_cast<fstream*>(i)->is_open()) {
			throw std::exception();
		}
	}
	return aux;
}

int main() {
	
}