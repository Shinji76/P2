class ios {
private:
    int failBit;
public:
    const bool fail() {
        if(failBit == 1)
            return true;
        return false;
    }
    virtual ~ios();
};


class istream : public ios {
public:
    long tellg();
};


class ifstream : public istream {
public:
    const bool is_open();
};