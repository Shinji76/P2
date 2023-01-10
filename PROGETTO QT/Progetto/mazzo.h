#ifndef MAZZO_H
#define MAZZO_H

#include "vector_template.h"
#include "AbstractCard.h"
#include "Album.h"
#include <iostream>

class Mazzo {
private:
	Fixed_vector<int> numCopie;		//creare getsize di album
	unsigned int counter;

public:
	Mazzo() : numCopie(), counter(0) {}
	
	void upCounter();
	
	void downCounter();
	
	void addCard(const Carta&);
	
	void removeCard(const Carta&);
};

#endif  //MAZZO_H