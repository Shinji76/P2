#ifndef MAZZO_H
#define MAZZO_H

#include "../Vector_template.h"
#include "AbstractCard.h"
#include <string>

class Mazzo {
private:
	AbstractCard::Classe classe;
    FixedVector<int> numCopie;
	int counter = 0;

public:
    Mazzo();
    Mazzo(AbstractCard::Classe classe, FixedVector<int> numCopie, unsigned int counter);
    
	AbstractCard::Classe getClasse() const;
    void setClasse(AbstractCard::Classe set);
    
    FixedVector<int> getNumCopie() const;
    int getCounter() const;

	void addCard(unsigned int id);
	void removeCard(unsigned int id);

    bool isFull(const AbstractCard* card);
};

#endif  //MAZZO_H
