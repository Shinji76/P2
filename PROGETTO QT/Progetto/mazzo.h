#ifndef MAZZO_H
#define MAZZO_H

#include "carta.h"
#include "album.h"
#include <iostream>
#include <vector>
	
class Mazzo {
private:
	unsigned int numCopie [50];		//creare getsize di album
	unsigned int counter;

public:
	Mazzo() : counter(0) {}
	
	void upCounter();
	
	void downCounter();
	
	void addCard(const Carta&);
	
	void removeCard(const Carta&);
};

#endif  //MAZZO_H