#ifndef MAZZO_H
#define MAZZO_H

#include "carta.h"
#include "album.h"
#include <iostream>
#include <vector>
	
class Mazzo {
private:
	unsigned int numCopie [5] = {0};		//creare getsize di album
public:
	void addCard(const Carta&);
	
	void removeCard(const Carta&);
};

#endif  //MAZZO_H