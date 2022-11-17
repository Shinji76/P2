/* Definire un template di classe albero<T> i cui oggetti rappresentano un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 3 figli (invece dei 2 figli di un usuale albero binario).
Il template albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto.
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output
*/
#ifndef TMP_ALBERO
#define TMP_ALBERO
#include<iostream>

template <class T>
class albero {
private:
    class nodo {
    public:
        T info;
        nodo *sx, *cx, *dx;
        nodo(const T& t, nodo* s = nullptr, nodo* c = nullptr, nodo* d = nullptr):
            info(t), sx(s), cx(c), dx(d) { }
    };

    static nodo<T>* copy(nodo<T>* p) {
        if(p == nullptr)
            return nullptr;
        else
            return new root(p->info, copy(p->sx), copy(p->cx), copy(p->dx));
    }

    static void destroy(nodo<T>* p) {
        if(p != nullptr) {
            destroy(p->sx);
            destroy(p->cx);
            destroy(p->dx);
            delete p;
        }   
    }

    static bool rec_search(const T& t, nodo <T>* p) {
        if(p == nullptr)
            return false;
        else
            return (t==p->info) || (rec_search(t->sx)) || (rec_search(t->cx)) || (rec_search(t->dx)); 
    }

    static bool equal(nodo* n1, nodo* n2) {
        
    }
    nodo<T>* root;
public:
    albero() : root(nullptr) { }
    albero(const albero& a) : root(copy(a.root)) { }
    albero& operator==(const albero& a) {
        if(this != &a) {
            destroy(root);
            root = copy(a.root);
        }
        return *this;
    }

    ~albero() {
        if(root != nullptr) 
            destroy(root);
    }

    void insert(const T& t) {
        root = new nodo(t, copy(root), copy(root), root);
    }

    bool search(const T& t) const {
        return rec_search(t.root);
    }

    bool operator==(const albero& a) const {
        return 
    }
};

template <class T>
std::ostream& operator<<(std::ostream& t, const albero<T>& a) {
    return t << "Figlio sx: " << a.sx() << " Figlio cx: " << a.cx() << " Figlio dx: " << a.dx() << std::endl;
}

#endif