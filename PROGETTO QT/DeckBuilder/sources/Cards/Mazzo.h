#ifndef MAZZO_H
#define MAZZO_H

#include "../vector_template.h"
#include "AbstractCard.h"
#include <string>

class Mazzo {
private:
    std::string nome;
	AbstractCard::Classe classe;
    FixedVector<int> numCopie;
	int counter;

public:
    Mazzo();
    Mazzo(std::string nome, AbstractCard::Classe classe, FixedVector<int> numCopie, unsigned int counter);
	
    std::string getNomeMazzo() const;
    void setNomeMazzo(std::string);
    
	AbstractCard::Classe getClasse() const;
    void setClasse(AbstractCard::Classe set);
    
    FixedVector<int> getNumCopie() const;
    int getCounter() const;

	void addCard(unsigned int id);
	void removeCard(unsigned int id);

    bool isFull(const AbstractCard* card);
};

#endif  //MAZZO_H
