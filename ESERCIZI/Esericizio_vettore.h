/*
Definire una classe VETTORE i cui oggetti rappresentano array di interi. Vettore deve includere:
-un costruttore di default
-una operazione di concatenazione che restituisce un nuovo vettore
-un operazione di append
-overloading di uguaglianza
-overloading operatore di output
-overloading operatore di indicizzazione
-costruttore copia profonda
-assegnazione profonda
-distruzione profonda
*/
#include <iostream>

class Vettore {
private:
    int* A; 
    unsigned int size;
    int* copia() const {
        int* B = new int(size);
        if(size == 0)
            return nullptr;
        for(unsigned int k=0; k<size; k++)
        {
            B[k] = A[k];
        }
        return B;
    }
    //vettore vuoto IFF A == nullptr && size == 0.
public:
    //blocco la conversione da unsigned int => vettore con explicit
    explicit Vettore(int = 0, unsigned int = 0);

    Vettore(const Vettore&);       //costruttore di copia profonda

    Vettore& operator=(const Vettore&);
    
    ~Vettore();

    Vettore operator+(const Vettore&) const;

    bool operator==(const Vettore& v) const;

    unsigned int getSize() const;

    int& operator[](unsigned int k) const;

    void append(const Vettore&);   //assegnazione profonda
};