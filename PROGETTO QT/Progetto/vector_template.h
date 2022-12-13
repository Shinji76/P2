#ifndef F_VECTOR_H
#define F_VECTOR_H
#include <iostream>

template <class T>
class Fixed_vector {
private:
	T info;
	unsigned int size;
public:
	Fixed_vector();

	~Fixed_vector();
	
	Fixed_vector(const Fixed_vector&);

	Fixed_vector operator=(const Fixed_vector&);
	
	Fixed_vector operator[](const Fixed_vector&);
	
};


template <class T>
Fixed_vector<T>::Fixed_vector() : info(0), size(1) {}

template <class T>
Fixed_vector<T>::~Fixed_vector() {

}

template <class T>
Fixed_vector<T>::Fixed_vector(const Fixed_vector& v) {

}
	
#endif //F_VECTOR_H