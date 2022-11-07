/* Definire un template di classe albero<T> i cui oggetti rappresentano un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 3 figli (invece dei 2 figli di un usuale albero binario).
Il template albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto.
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output
*/

template <class T>
class albero3ario {
private:
    class nodo
    {
    private:
        int info;
        nodo* sx, cx, dx;
    public:
        nodo();
        ~nodo();
    };
    
    nodo::nodo() : info(0), *sx(nullptr), *cx(nullptr), *dx(nullptr) {}

    nodo::~nodo()
    {
		if()
    }
    nodo<T>* root;
public:
    albero3ario() : root(nullptr);
};