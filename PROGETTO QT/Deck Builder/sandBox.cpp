#include "sources/vector_template.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int counter = 1;
	FixedVector<int, 50> prova;
	FixedVector<int, 20> prova2;

    for(auto it = prova2.begin(); it != prova2.end(); ++it) {
        cout << prova2[counter];
        cout << *it << endl;
        cout << counter << endl;
        counter++;
    }
    counter = 101;
    for(auto it = prova.begin(); it != prova.end(); ++it) {
        //cout << *it << endl;
        cout << counter << endl;
        counter++;
    }
}
