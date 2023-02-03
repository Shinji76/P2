class A {
public:
    virtual A* f() const =0;
};

class B: public A {

};

class C: public B {
public:
    B* f() const {return new C;}
};

class D: public B {

};

class E: public B {
public:
    A* f() const {return new E();}
};

class F: public C, public D, public E {
public:
    D* f() const {return new F();}
};
