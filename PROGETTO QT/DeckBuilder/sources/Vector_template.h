#ifndef F_VECTOR_H
#define F_VECTOR_H
#include <iostream>

/*
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
Fixed_vector<T>::Fixed_vector(const Fixed_vector& v) : V(v.copy()), size(v.size) {}

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
*/

template <class T, int N>
class FixedVector {
private:
    T data[N];
    int size;
public:
    FixedVector() : size(N) {}

    int getSize() const;
    int capacity() const;
    T& operator[](int index) const;
    void push_back(const T& value);

    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* ptr) : ptr(ptr) {}

        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

template<class T, int N>
int FixedVector<T,N>::getSize() const {
    return size;
}

template<class T, int N>
int FixedVector<T,N>::capacity() const {
    return N;
}


template<class T, int N>
T& FixedVector<T,N>::operator[](int index) const {
    return data[index];
}

template<class T, int N>
void FixedVector<T,N>::push_back(const T& value) {
    if (size < N) {
        data[size++] = value;
    } else {
        //qualche errore
    }
}

template<class T, int N>
T& FixedVector<T,N>::Iterator::operator*() {
    return *ptr;
}

template<class T, int N>
typename FixedVector<T,N>::Iterator& FixedVector<T,N>::Iterator::operator++() {
    ptr++;
    return *this;
}

template<class T, int N>
bool FixedVector<T,N>::Iterator::operator!=(const FixedVector<T,N>::Iterator& other) const {
    return ptr != other.ptr;
}

template<class T, int N>
typename FixedVector<T,N>::Iterator FixedVector<T,N>::begin() {
    return Iterator(data);
}

template<class T, int N>
typename FixedVector<T,N>::Iterator FixedVector<T,N>::end() {
    return Iterator(data + size);
}

/*
int main() {
    FixedVector<int, 5> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}
*/

#endif //F_VECTOR_H