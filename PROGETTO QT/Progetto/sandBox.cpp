#include <iostream>
#include "vector_template.h"
#include "album.h"

using std::cout;
using std::endl;

int main() {
	Fixed_vector<int> prova;
	Fixed_vector<int> prova2(5);
	//Album nuovo;

	cout << prova.getSize() << endl;
	cout << prova2.getSize() << endl;

	cout << prova.checkIfNull() << endl;
	cout << prova2.checkIfNull() << endl;

	cout << prova2[3];
}