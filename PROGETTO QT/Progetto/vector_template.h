#ifndef F_VECTOR_H
#define F_VECTOR_H
#include <iostream>

template <class T>
class Fixed_vector {
private:
	T* V;
	unsigned int size;

	T* copy() const {
		T* tmp = new T(size);
	if(size == 0)
		return nullptr;
	for(unsigned int i=0; i<size; i++) {
		tmp[i] = V[i];
	}
	return tmp;
	}
public:
	Fixed_vector();

	Fixed_vector(unsigned int);

	~Fixed_vector();
	
	Fixed_vector(const Fixed_vector&);

	Fixed_vector& operator=(const Fixed_vector&);
	
	T& operator[](unsigned int);
	
	bool checkIfNull();
	
	unsigned int getSize();
};

template <class T>
Fixed_vector<T>::Fixed_vector() : V(new T[50]), size(50) {}

template <class T>
Fixed_vector<T>::Fixed_vector(unsigned int s)
	: V(s == 0 ? nullptr : new T[s]), size(s) {
		for(unsigned int i = 0; i<size; i++)
			V[i] = 0;
	}

template <class T>
Fixed_vector<T>::~Fixed_vector() {
	if(V != nullptr)
		delete V;
}

template <class T>
Fixed_vector<T>::Fixed_vector(const Fixed_vector& v): V(v.copy()), size(v.size) {}

template <class T>
T& Fixed_vector<T>::operator[](unsigned int k) {
	return V[k];
}

template <class T>
Fixed_vector<T>& Fixed_vector<T>::operator=(const Fixed_vector& v) {
	if(this != &v) {        //controllo che siano diversi per evitare copie inutili
		delete V;
		size = v.size;
		V = v.copy();
	}
	return *this;
}

template <class T>
bool Fixed_vector<T>::checkIfNull() {
	if(this->V != nullptr)
		return false;
	return true;
}

template <class T>
unsigned int Fixed_vector<T>::getSize() {
	return size;
}

#endif //F_VECTOR_H