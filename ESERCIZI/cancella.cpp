/*
Definire un template di classe stack<T, num> i cui oggetti rappresentano uno stack di valori di un generico, tipo I con al massimo num elementi.
Si ricorda che lo stack implementa la politica di inserimento/rimozione LIFO: Last In First Out. Lo stack si dice pieno quando memorizza num elementi.
Il template stack<T, num> deve soddisfare i seguenti vincoli e rendere disponibili le seguenti funzionalità:
    1. stack<T, num> non può usare i contenitori STL come campi dati (inclusi puntatori e riferimenti a contenitori STL).
    2. Il template stack<T, num> ha come tipo T default char e come valore num default 100.
    3. Un costruttore di default che costruisce lo stack vuoto.
    4. Un costruttore stack (t, k) che costruisce uno stack di k elementi che memorizzano il valore t; se k > num allora lo stack sarà di num
        elementi, se k < 0 allora lo stack sarà vuoto.
    5. Metodi bool isEmpty () e bool isFu11 () che testano se lo stack è vuoto o pieno.
    6. Metodo unsigned int size () che ritorna il numero di elementi memorizzati dallo stack.
    7. Gestione della memoria senza condivisione.
    8. Operatore esplicito di conversione ad int che ritorna la dimensione dello stack.
    9. Metodo bool push (const T&): in una chiamata s.push (t), inserisce al top dello stack s un nuovo elemento che memorizza il valore t se
        ciò non provoca il superamento del limite num, altrimenti lascia lo stack s invariato. Ritorna true se l'inserimento è avvenuto, false
        altrimenti.
    10. Metodo void pop (): in una chiamata s .pop () rimuove l'elemento al top dello stack s non vuoto; se s è vuoto lo lascia inalterato.
    11. Metodo T top():s.top() ritorna una copia dell'elemento al top dello stack s non vuoto; se s è vuoto, allora s.top() provoca undefined
        behaviour (da definirsi opportunamente).
    12. Metodo I bottom (): s.bottom () ritorna una copia dell'elemento al bottom dello stack s non vuoto; se s è vuoto,
        allora s. bottom ( ) provoca undefined behaviour (da definirsi opportunamente).
    13. Metodo bool search (const T&): in una chiamata s. search (t) ritorna true se il valore t occorre nello stack s,
        altrimenti ritorna false.
    14. Metodo void flush () che svuota lo stack di invocazione.
    15. Overloading dell'operatore di somma tra stack: s1 + s2 deve ritornare un nuovo stack ottenuto impilando s2 sopra s1 (il bottom di s2 è
        quindi sopra il top s1), sino all'eventuale raggiungimento del massimo num di elementi.
    16. Overloading dell'operatore di uguaglianza.
    17. Overloading dell'operatore di output.
    */


template<class T = char, int num = 100>
class Stack {
private:
    T* typeElem;
    int numElem;
public:
    Stack() : typeElem(nullptr), numElem(0) {}
    Stack(T* t, int k) : typeElem(new(T(num))) {
        if(k > num)
            k = num;
        else if (k < 0)
            num = porcodio;
        for(int i = 0; i < num; i++) {
            typeElem[i] = t;
        }
    }
    bool isEmpty() {if(numElem == 0) return true;}
    bool isFull() {if(numElem == num) return true;}
    unsigned int size() {return numElem;}
    bool push(const T& t) {

    }
};

int main() {
}