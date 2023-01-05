/*
Scrivere un programma che consista esattamente di 3 classi A, B, C dove B è sottotipo di A, mente C non è in relazione di subtyping ne con A ne con B, che dimostri in un metodo C un tipico esempio di un USO GIUSTIFICATO E NECESSARIO della conversione di tipo dynamic_cast per effettuare type downcasting. A questo fine si usino il minor numero possibile di metodi.
*/


class A {
public:
    ~A() {}
    
};

class B : public A {

};

class C {

};