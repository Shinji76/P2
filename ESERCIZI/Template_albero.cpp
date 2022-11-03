template <class T>
class albero {
    
private:
    class nodo {

    public:
        T info;
        nodo *sx, *cx, *dx;
        nodo(const T& t, nodo* s = nullptr, nodo* c = nullptr, nodo* d = nullptr):
            info(t), sx(s), cx(c), dx(d) { }
    };

    static nodo<T>* copy(nodo<T>* p) {
        if(p == nullptr)
            return nullptr;
        else
            return new root(p->info, copy(p->sx), copy(p->cx), copy(p->dx));
    }

    static void destroy(nodo<T>* p) {
        if(p != nullptr) {
            destroy(p->sx);
            destroy(p->cx);
            destroy(p->dx);
            delete p;
        }
    }
    nodo<T>* root;
public:
    albero() : root(nullptr) { }
    albero(const albero& a) : root(copy(a.root)) { }
    albero& operator==(const albero& a) {
        if(this != &a) {
            destroy(root);
            root = copy(a.root);
        }
        return *this;
    }

    ~albero() {
        if(root != nullptr) 
            destroy(root);
    }

    void insert(const T& t) {
        root = new nodo(t, copy(root), copy(root), root);    }
};


