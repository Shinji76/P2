/* ESERCIZIO:
Definire un template di classe dList<T> i cui gli oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly linked list) per elementi di uno stesso tipo T.
Il template dList<T> deve soddisfare i seguenti vincoli:
1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList(unsigned int k, const T& t) che costruisce una lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t.

3. dList<T> permette l’inserimento in testa ed in coda ad una lista in tempo O(1) (cioe` costante):
    -- Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento: dl.insertFront(t) inserisce l’elemento t in testa a dl in tempo O(1).
    -- Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento: dl.insertBack(t) inserisce l’elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l’ordinamento lessico-grafico (ad esempio, si ricorda che per l'ordinamento lessico-grafico tra stringhe abbiamo che "campana" < "cavolo" e che "buono" < "ottimo").

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::const_iterator i cui oggetti permettono di iterare sugli elementi di una lista. */

#ifndef TEMPLATE_DLIST
#define TEMPLATE_DLIST

template <class T>
class dList {
private:
    class nodo {
    public:
        T info;
        nodo *prev;
        nodo *next;
        nodo(const T& i, nodo* p = 0, nodo* n = 0) : info(i), prev(p), next(n) { }
    
    };
	nodo* first;
	nodo* last;

	//basta passare un solo puntatore per la destroy e non entrambi perchè scorro la lista
	static void destroy(nodo *f) {
		if(f!=nullptr) {
			destroy(f->next);
			delete f;
		}
	}

	static void copy(nodo* fst, nodo*& f, nodo*& l) {
		//caso base lista vuota
		if(fst == nullptr)
			f = l = nullptr;
			return;
		else {
			nodo* tmp = fst;
			f = l = new nodo(tmp->info, nullptr, nullptr);
			while(fst->next) {
				tmp = tmp->next;
				l->next = new nodo(tmp->info, l, nullptr);
				l = l->next;
			}
		}
	}

	static bool lessic_compare(nodo* f, nodo* s) {
		/*
		1 CASO BASE: vuota < vuota => falso
		2 CASO BASE: vuota < !vuota => true
		3 CASO BASE: !vuota < vuota => falso
		*/
		if(!f && !s)
			return false;
		if(!f)		//se passo il primo check vuol dire che la seconda è vuota quindi true
			return true;
		if(!s)
			return false;
		//CASO COMPLESSO
		if(f->info < s->info)
			return true;
		if(f->info > s->info)
			return false;
		return f->info == s->info && lessic_compare(f->next, s->next);
	}

public:
    dList(const T& d) : copy(d.first, first, last) { }

	~dList() {
		if(first) 
			destroy(first);
	}
	
	void insertFront(const T& t) {
		first = new nodo(f, nullptr, first);
		if(last == nullptr)
			last = first;
		if(first->next != nullptr)
			first->next->prev = first;
	}

	void insertBack(const T& t) {

	}

	bool operator<(const dList d) const {
		//1 CASO BASE: vuota < vuota => falso
		//2 CASO BASE: vuota < !vuota => true
		//3 CASO BASE: !vuota < vuota => falso
		return lessic_compare(first, d.first);
	}

	dList(unsigned int k, const T& t) : first(nullptr), last(nullptr) {
		for(unsigned int i=0; i<k; i++)
			insertFront(t);
	}
	
	dList& operator=(const dList& d) {
		if(this != &d) {
			destroy(first);
			copy(d.first, first, last);
		}
		return *this;
	}

	class const_iterator {
	private:
		const nodo* ptr;
		bool EndFlag;
	public:

	}
	
};


#endif