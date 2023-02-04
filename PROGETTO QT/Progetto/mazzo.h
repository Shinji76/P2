#ifndef MAZZO_H
#define MAZZO_H

#include "vector_template.h"
#include "AbstractCard.h"
#include "Album.h"
#include <iostream>

class Mazzo {
private:
	Fixed_vector<int> numCopie;
	unsigned int counter;

	void upCounter();
	void downCounter();

public:
	Mazzo(Fixed_vector<int> numCopie, unsigned int counter);
	
	void addCard(const AbstractCard&);
	
	void removeCard(const AbstractCard&);
};

#endif  //MAZZO_H