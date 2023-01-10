class ios {
public:
    int rdstate() const {}
    void setState(int) {}
    virtual ~ios() {}
}; 

class istream : virtual public ios {
public:
    int tellg() const {}
};

class ostream : virtual public ios {
public:
    int tellp() const {}
};

class iostream : public istream, public ostream {

};

class fstream : public iostream {
public:
    bool is_open() const {}
    void close() {}
};