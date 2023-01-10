#include <string>
using std::string;

class ios {
public:
    bool fail() const {}
    virtual ~ios();
};

class istream : public ios {
public:
    long tellg() const {}
};

class ifstream : public istream {
public:
    bool is_open() const {}
};

class Fallimento {
public:
    Fallimento() {}
};