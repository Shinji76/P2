#include<iostream>
#include<fstream>
#include<typeinfo>
using namespace std;

class C {
public:
    virtual ~C() {}
};

main() {
    ifstream f("pippo");
    fstream g("pluto"), h("zagor");
    iostream* p = &h;
    C c1, c2;
    cout << Fun(&cout, cin) << endl;
    cout << Fun(&cout, cerr) << endl;
    cout << Fun(p, h) << endl;
    cout << Fun(&f, *p) << endl;
    cout << Fun(&g, h) << endl;
    cout << Fun(&c1, c2) << endl;
}

template <class T1, class T2>
bool Fun(T1* p, T2& r) {
    return typeid(T1) == typeid(T2) &&
        typeid(*p) == typeid(r) && dynamic_cast<ios*>(&r);
}