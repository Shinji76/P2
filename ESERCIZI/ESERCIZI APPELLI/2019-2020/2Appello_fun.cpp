/*
Definire  un  template  di  classe Vettore<T,sz> i cui oggetti rappresentano un array di tipo T e dimensione sz ≥ 0.
Il template di classe Vettore<T,sz> deve includere:
	un costruttore Vettore(const T& x) che costruisce un array in cui tutte le celle memorizzano il valore x;
	un costruttore di default Vettore() che costruisce un array in cui tutte le celle memorizzano il valore di default T() del tipo T;
	ridefinizione di costruttore di copia profonda, assegnazione profonda e distruzione profonda;
	overloading degli operatori operator* di dereferenziazione e operator[] di indicizzazione con comportamento analogo ai corrispondenti operatori disponibili per gli array ordinari;
	overloading dell’operatore di output.
	Ad esempio, il seguente codice dovrà compilare correttamente e l’esecuzione dovrà provocare esattamente le stampe riportate nei commenti.
*/
#include <iostream>

template <class T = int, unsigned int size = 0>
class Vettore {
private:
	T* ptr;

public:
	Vettore(const T& x = T()) : ptr(size == 0 ? nullptr : new T[size]) {
		for(int i = 0; i < size; i++) {
			ptr[i] = x; 
		}
	}
	
	Vettore(const Vettore& v) : ptr(size == 0 ? nullptr : new T[size]) {
		for(int i = 0; i< size; i++) {
			ptr[i] = v.ptr[i];
		}
	}
	
	Vettore& operator=(const Vettore& v) {
		if(this != &v) {
			delete[] ptr;
			ptr = size == 0 ? nullptr : new T[size];
			for(int i = 0; i < size; i++) {
				ptr[i] = v.ptr[i];
			}
		}
		return *this;
	}
	
	~Vettore() {
		if(ptr)
			delete ptr;
	}
	
	const T& operator*() const {
		return ptr[0];
	}
	
	T& operator*() {
		return ptr[0];
	}

	const T& operator[](unsigned int x) const {
		return ptr[x];
	}
	
	T& operator[](unsigned int x) {
		return ptr[x];
	}

};

template<class T, unsigned int size>
std::ostream& operator<<(std::ostream& s, const Vettore<T,size> v) {
	for(int i = 0; i < size; ++i) {
		s << v[i] << ' ';
	}
	return s;
}

int main() {
	Vettore<int,4> v1(2);
	Vettore< Vettore<int,3> ,3> v2(3);
	Vettore<int,4> v3(v1);
	Vettore<int,4> v4;
	v3[2] = 6;
	*v1 = 9;
	v4 = v1;
	v4[3] = 5;
	std::cout << v1 << std::endl;	// 9 2 2 2
	std::cout << v2 << std::endl;	// 3 3 3  3 3 3  3 3 3
	std::cout << v3 << std::endl;	// 2 2 6 2
	std::cout << v4 << std::endl;	// 9 2 2 5
}