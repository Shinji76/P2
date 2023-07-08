#ifndef F_VECTOR_H
#define F_VECTOR_H

#include <exception>

#include <iostream>

template <class T>
class FixedVector {
private:
    static const unsigned int SIZE = 50;
    int capacity;
    T data[SIZE];
public:
    FixedVector();
    ~FixedVector();
    
    int getSize() const;
    int getCapacity() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    void push_back(const T& value);
    T& operator=(const T& copy);

    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* ptr) : ptr(ptr) {}

        T& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator& compare) const;
    };

    class constIterator {
    private:
        const T* ptr;
    public:
        constIterator(const T* ptr) : ptr(ptr) {}

        const T& operator*() const;
        constIterator& operator++();	
		constIterator operator++(int);
        bool operator!=(const constIterator& compare) const;
    };

    constIterator begin() const;
    constIterator end() const;
    Iterator begin();
    Iterator end();
};

template<class T>
FixedVector<T>::FixedVector() : capacity(0) {
    for(int i = 0; i < SIZE; ++i) {
        data[i] = 0;
    }
}

template<class T>
FixedVector<T>::~FixedVector() {
    if (data) {
        for (int i = 0; i < SIZE; i++) {
            data[i].~T(); 
        }
        delete(data);
    }
}

template<class T>
int FixedVector<T>::getSize() const {
    return SIZE;
}

template<class T>
int FixedVector<T>::getCapacity() const {
    return capacity;
}

template<class T>
T& FixedVector<T>::operator[](int index) {
    return data[index];
}

template<class T>
const T& FixedVector<T>::operator[](int index) const {
    return data[index];
}

template<class T>
void FixedVector<T>::push_back(const T& value) {
    if (capacity < SIZE) {
        data[capacity++] = value;
        capacity++;
    } else {
        throw std::out_of_range("exceeded vector capacity");
    }
}

template<class T>
T& FixedVector<T>::operator=(const T& copy) {
    for(int i = 0; i < SIZE; i++) {
        data[i] = copy[i];
    }
}

template<class T>
T& FixedVector<T>::Iterator::operator*() {
    return *ptr;
}

template<class T>
typename FixedVector<T>::Iterator& FixedVector<T>::Iterator::operator++() {
    ptr++;
    return *this;
}

template<class T>
typename FixedVector<T>::Iterator FixedVector<T>::Iterator::operator++(int) {
    ptr++;
    return *this;
}

template<class T>
bool FixedVector<T>::Iterator::operator!=(const FixedVector<T>::Iterator& compare) const {
    return ptr != compare.ptr;
}

template<class T>
bool FixedVector<T>::constIterator::operator!=(const FixedVector<T>::constIterator& compare) const {
    return ptr != compare.ptr;
}

template<class T>
typename FixedVector<T>::Iterator FixedVector<T>::begin() {
    return Iterator(data);
}

template<class T>
typename FixedVector<T>::Iterator FixedVector<T>::end() {
    return Iterator(data + SIZE);
}


template<class T>
const T& FixedVector<T>::constIterator::operator*() const {
    return *ptr; 
}

template<class T>
typename FixedVector<T>::constIterator& FixedVector<T>::constIterator::operator++() {
    ptr++;
    return *this;
}

template<class T>
typename FixedVector<T>::constIterator FixedVector<T>::constIterator::operator++(int) {
    ptr++;
    return *this;
}

template<class T>
typename FixedVector<T>::constIterator FixedVector<T>::begin() const {
    return constIterator(data);
}

template<class T>
typename FixedVector<T>::constIterator FixedVector<T>::end() const {
    return constIterator(data + SIZE);
}

#endif //F_VECTOR_H
