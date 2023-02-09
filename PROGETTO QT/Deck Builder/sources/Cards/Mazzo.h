#ifndef MAZZO_H
#define MAZZO_H

#include "../vector_template.h"
#include "AbstractCard.h"
#include "Album.h"

class Mazzo {
private:
	AbstractCard::Classe classe;
	Fixed_vector<int> numCopie;
	unsigned int counter;

public:
	Mazzo(AbstractCard::Classe classe, Fixed_vector<int> numCopie, unsigned int counter);
	
	AbstractCard::Classe getClasse() const;
    void setClasse(AbstractCard::Classe set);

	void addCard(const AbstractCard&);
	void removeCard(const AbstractCard&);

};

#endif  //MAZZO_H