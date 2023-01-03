#include <iostream>
using std::cout;
using std::endl;

class C{
public:
    C(){cout<<" C0 ";}
    C(const C&) { cout<<" Cc ";}
    C& operator=(const C& e){
        cout<<" C= ";
        return*this;
    }
};

class D{
public:
    C c;
    D() {cout<<" D0 ";}
    D(const D&){cout<< " Dc ";}
};

class E: public C{
public:
    C c;
    E() {cout<<" E0 ";}
    E& operator =(const E& e){
        *this=e;
        cout<<" E= "; return*this;
    }
};

class F: public C{
public:
    C* pc;
    F() {cout<<" F0 ";}
    F(const F&){ cout<< " Fc ";}
    F& operator=(const F& f){
        C::operator =(f);
        pc=f.pc;
        cout<<" E= "; return*this;
    }
};

int main(){
    C x1; cout<<endl;
    C x2; cout<<endl;
    E y1; cout<<endl;
    E y2; cout<<endl;
    F z1; cout<<endl;
    F z2; cout<<endl;
    cout<<endl;
    cout<<"01 ";
    D d1; cout<<endl;
    cout<<"02 ";
    D d2(d1); cout<<endl;
    cout<<"03 ";
    E e1; cout<<endl;
    cout<<"04 ";
    E e2=y1; cout<<endl;
    cout<<"05 non stampa";
    //y1=y2; cout<<endl;
    cout<<"06 ";
    F*pF= new F(); cout<<endl;
    cout<<"07 ";
    F f=z1; cout<<endl;
    cout<<"08 ";
    z1=z2; cout<<endl;
    cout<<"09 ";
    x1=y1; cout<<endl;
    //z1=x1; cout<<endl;
}
