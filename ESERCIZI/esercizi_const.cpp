#include "esercizi_const.h"

C::C(int n) {
    x = n;
}

C C::F(C obj) {
    C r;
    r.x = obj.x +x;
    return r;
}

C C::G(C obj) const {
    C r;
    r.x = obj.x +x;
    return r;
}

C C::H(C& obj) {
    obj.x += x;
    return obj;
}

C C::I(const C& obj) {
    C r;
    r.x = obj.x +x;
    return r;
}

C C::J(const C& obj) const {
    C r;
    r.x = obj.x +x;
    return r;
}

int main() {
    C x, y(1), z(2);
    const C v(2);
    z = x.F(y); /* x è un oggetto di tipo C che viene creato con il costruttore di default ridefinito, chiamo il metodo F sull'oggetto C, il metodo F richiede come parametro un oggetto C passato per valore quindi il tipo va bene. */
    v.F(y); /* v è un oggetto di tipo const C, mentre il metodo F richiede come parametro un oggetto C passato per valore, non tipa perchè verrebbe perso il const e restituisce ERRORE */
    v.G(y); /* v è un oggetto di tipo const C, G è un metodo che richiede una variabile di tipo C */
}