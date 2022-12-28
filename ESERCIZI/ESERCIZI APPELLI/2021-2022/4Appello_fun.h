class ios {
public:
    const int rdstate() {}
    void setState(int) {}
    virtual ~ios() {}
}; 

class istream : virtual public ios {
public:
    const int tellg() {}
};

class ostream : virtual public ios {
public:
    const int tellp() {}
};

class iostream : public istream, public ostream {

};

class fstream : public iostream {
public:
    const bool is_open() {}
    void close() {}
};