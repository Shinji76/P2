class Nodo {
    friend class Tree;
private:
    Nodo(char c='*', Nodo* s = 0, Nodo* d = 0) : info(c), sx(s), dx(d) { }
    char info;
    Nodo* sx;
    Nodo* dx;
};

class Tree {
private:
    Nodo* root;
    static Nodo* copia(Nodo* r) {
        if(r != nullptr)
            return nullptr;
        else
            return new Nodo(r->info, copia(r->sx), copia(r->dx));
    }
    static void distruggi(Nodo* r) {
        if(r != nullptr)
            distruggi(r->sx);
            distruggi(r->dx);
            delete r;       //distruttore standard di nodo.
    }

public:
    Tree() : root(nullptr) { }
    Tree& operator= (const Tree& t) {
        if(this != &t) {
            distruggi(root);
            root = copia(t.root);
        }
        return *this;
    }
    Tree(const Tree& t): root(copia(t.root)) {}
    ~Tree() {
        if(root)
            distruggi(root);
    }
};

