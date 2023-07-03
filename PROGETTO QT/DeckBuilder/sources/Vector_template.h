#ifndef F_VECTOR_H
#define F_VECTOR_H
#include <iostream>

template <class T, int N>
class FixedVector {
private:
    T data[N];
    int size;
public:
    FixedVector() : size(N) {}

    int getSize() const;
    int capacity() const;
    T& operator[](int index);
    void push_back(const T& value);

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

        const T& operator*();
        constIterator& operator++();	
		constIterator operator++(int);
        bool operator!=(const constIterator& compare) const;
    };

    constIterator begin() const;
    constIterator end() const;
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
T& FixedVector<T,N>::operator[](int index) {
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
typename FixedVector<T,N>::Iterator FixedVector<T,N>::Iterator::operator++(int) {
    ptr++;
    return *this;
}

template<class T, int N>
bool FixedVector<T,N>::Iterator::operator!=(const FixedVector<T,N>::Iterator& compare) const {
    return ptr != compare.ptr;
}

template<class T, int N>
bool FixedVector<T,N>::constIterator::operator!=(const FixedVector<T,N>::constIterator& compare) const {
    return ptr != compare.ptr;
}

template<class T, int N>
typename FixedVector<T,N>::Iterator FixedVector<T,N>::begin() {
    return Iterator(data);
}

template<class T, int N>
typename FixedVector<T,N>::Iterator FixedVector<T,N>::end() {
    return Iterator(data + size);
}


template<class T, int N>
const T& FixedVector<T,N>::constIterator::operator*() {
    return *ptr;
}

template<class T, int N>
typename FixedVector<T,N>::constIterator& FixedVector<T,N>::constIterator::operator++() {
    ptr++;
    return *this;
}

template<class T, int N>
typename FixedVector<T,N>::constIterator FixedVector<T,N>::constIterator::operator++(int) {
    ptr++;
    return *this;
}

template<class T, int N>
typename FixedVector<T,N>::constIterator FixedVector<T,N>::begin() const {
    return constIterator(data);
}

template<class T, int N>
typename FixedVector<T,N>::constIterator FixedVector<T,N>::end() const {
    return constIterator(data + size);
}

#endif //F_VECTOR_H
