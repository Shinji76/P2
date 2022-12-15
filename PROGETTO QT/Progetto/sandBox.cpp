#include <iostream>
#include "vector_template.h"

int main() {
	Fixed_vector<int> prova;

	Fixed_vector<int> prova2(5);

	std::cout << prova.getSize() << std::endl;
	std::cout << prova2.getSize() << std::endl;

	std::cout << prova.checkIfNull() << std::endl;
	std::cout << prova2.checkIfNull() << std::endl;
}