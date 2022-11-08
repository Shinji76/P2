#ifndef queue_h
#define queue_h

template <class T>
class QueueItem {
public:
    QueueItem(const T&);
    T info;
    QueueItem* next;
}; 

template <class T>
class Queue {
public:
    Queue();
    bool empty() const;
    void add(const T&);
    T remove();
    ~Queue();
    Queue(const Queue&);
    Queue& operator=(const Queue&);

private:
    QueueItem<T>* primo;
    QueueItem<T>* ultimo;
};

template <class T>
Queue<T>::Queue() : primo(0), ultimo(0) {}

template <class T>
bool Queue<T>::empty() const {
    return (primo == 0);
}

template <class T>
void Queue<T>::add(const T& val) {
    if(empty())
        primo = ultimo = new QueueItem<T>(val);
    else {
        ultimo->next = new QueueItem <T> (val);
        ultimo = ultimo->next;
    }
}

template <class T>
T Queue<T>::remove() {
    if(empty()) {
        std::cerr << "remove() su coda vuota" << std::endl;
        //exit(1);        //BAD PRACTICE, si usano le eccezioni
    }
    QueueItem<T>* p = primo;
    primo = primo->next;
    if(primo == 0)
        ultimo = primo;
    T aux = p->info;
    delete p;
    return aux;
}

template <class T>
Queue<T>::~Queue() {
    while(!empty())
        remove();
}

#endif