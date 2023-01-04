/*
Si assuma che Abs sia una classe base astratta fissata.
Definire un template di funzione: bool Fun(T1*, T2&), dove T1 e T2 sono parametri di tipo, con il seguente comportamento.
Si consideri un'istanziazione implicita Fun(ptr, ref) dove si suppone che i parametri di tipo T1 e T2 siano istanziati a tipi polimorfi.
Allora Fun(ptr, ref) ritorna true se e soltanto se valgono le seguenti due condizioni:
	1. I parametri di tipo T1 e T2 sono istanziati allo stesso tipo;
	2. Siano D1* il tipo dinamico di ptr e D2& il tipo dinamico di ref, allora:
		(i) Di e D2 sono lo stesso tipo.
		(ii) Questo tipo è un sottotipo proprio della classe Abs.
*/
#include<typeinfo.h>

class Abs {
public:
	virtual ~Abs() {}
};

template<class T1, class T2>
bool Fun(T1* ptr, T2& ref) {
	if(typeid(T1) == typeid(T2) && ypeid(*ptr) == typeid(ref) && dynamic_cast<Abs*>(ptr))
		return true;
	return false;
}