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
private:		//PRIVATE dLIST
    class nodo {
    public:		//PUBLIC NODO
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
		if(!f && !s)	//se passo il primo check vuol dire che una delle 2 non è vuota, altrimenti do FALSE
			return false;
		if(!f)			//se f non è vuota vuol dire che s è vuota e ritorno TRUE 
			return true;
		if(!s)			//se arrivo qua vuol dire per forza che f è vuota e quindi FALSE
			return false;
		//CASO COMPLESSO
		if(f->info < s->info)
			return true;
		if(f->info > s->info)
			return false;
		return f->info == s->info && lessic_compare(f->next, s->next);
	}

public:			//PUBLIC dLIST
    dList(const T&);
	~dList();
	void insertFront(const T&);
	void insertBack(const T&);
	bool operator<(const dList) const;
	dList(unsigned int, const T&);
	dList& operator=(const dList& d);

	class const_iterator {
		friend class dList<T>;
	private:
		const nodo* ptr;
		bool EndFlag;
		//iteratore indefinito IFF  ptr == nullptr && EndFlag == false
		const_iterator(const nodo* p, bool ef=false) : ptr(p), EndFlag(ef) { }
	public:
		const_iterator();
	
		const_iterator& operator++();	
		const_iterator operator++(int);
		const_iterator& operator--();
		const_iterator operator--(int);

		const T& operator*() const;
		const T* operator->() const;
	};

	const_iterator begin() const;
	const_iterator end() const;
};

template <class T>
dList<T>::dList(const T& d) : copy(d.first, first, last) {}

template <class T>
dList<T>::~dList() {
	if(first) 
		destroy(first);
}

template <class T>
dList<T>::dList(const T& d) : copy(d.first, first, last) {}
	
template <class T>
void dList<T>::insertFront(const T& t) {
	first = new nodo(t, nullptr, first);
	if(last == nullptr)
		last = first;
	if(first->next != nullptr)
		first->next->prev = first;
}

template <class T>
void dList<T>::insertBack(const T& t) {
	last = new nodo(t, last, nullptr)
	if(first == nullptr)
		first == last;
	if(last->prev != nullptr)
		last->prev->next = last;
}

template <class T>
bool dList<T>::operator<(const dList d) const {
	return lessic_compare(first, d.first);
}

template <class T>
dList<T>::dList(unsigned int k, const T& t) : first(nullptr), last(nullptr) {
	for(unsigned int i=0; i<k; i++)
		insertFront(t);
}

template <class T>
dList<T>& dList<T>::operator=(const dList& d) {
	if(this != &d) {
		destroy(first);
		copy(d.first, first, last);
	}
	return *this;
}

template <class T>
dList<T>::const_iterator::const_iterator() : ptr(nullptr), EndFlag(false) { }

template <class T>
dList<T>::const_iterator& dList<T>::const_iterator::operator++() {		
	//const_iterator indefinito non faccio azioni
	if(ptr && !EndFlag) {
		if(ptr->next == nullptr) {
			ptr = ptr+1;
			EndFlag = true;
		}
		else {
			ptr = ptr->next;
		}
	}
	return *this;
}
	
template <class T>
dList<T>::const_iterator dList<T>::const_iterator::operator++(int) {
	const_iterator tmp(*this);
	if(ptr && !EndFlag) {
		if(ptr->next == nullptr) {
			ptr = ptr+1;
			EndFlag = true;
		}
		else {
			ptr = ptr->next;
		}
	}
	return tmp;
}

template <class T>
dList<T>::const_iterator& dList<T>::const_iterator::operator--() {
	if(ptr) {
		if(ptr->prev == nullptr)
			ptr = nullptr;
		else if(EndFlag == true) {
			ptr = ptr-1;
			EndFlag =false;
		}
		else
			ptr = ptr->prev;					
	}
	return *this;	
}

template <class T>
dList<T>::const_iterator dList<T>::const_iterator::operator--(int) {
	const_iterator tmp(*this);
	if(ptr) {
		if(ptr->prev == nullptr)
			ptr = nullptr;
		else if(EndFlag == true) {
			ptr = ptr-1;
			EndFlag =false;
		}
		else
			ptr = ptr->prev;					
	}
	return tmp;
}

template <class T>
const T& dList<T>::const_iterator::operator*() const {
	return ptr->info;
}

template <class T>
const T* dList<T>::const_iterator::operator->() const {
	return &(ptr->info);
}

template <class T>
dList<T>::const_iterator dList<T>::begin() const {
	if(first != nullptr)					//Caso lista vuota
		return const_iterator(first);
	return const_iterator();				//Caso lista non vuota
}

template <class T>
dList<T>::const_iterator dList<T>::end() const {
	if(first == nullptr)					//Caso lista vuota
		return const_iterator();
	return const_iterator(last+1, true);	//Caso lista non vuota
}	

#endif