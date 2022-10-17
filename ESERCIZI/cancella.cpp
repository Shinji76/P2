#include <iostream>

class C {
    int A[1000];
};

bool byValue(C x) {
    return true;
}
bool byConstReference(const C& x) {
    return true;
}

int main() {
    C obj;
    for(int i=0; i<10000000; i++)
        byValue(obj);
    for(int i=0; i<10000000; i++)
        byConstReference(obj);
}