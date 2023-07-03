#ifndef MAZZO_H
#define MAZZO_H

#include "../vector_template.h"
#include "AbstractCard.h"
#include <string>

class Mazzo {
private:
    std::string nome;
	AbstractCard::Classe classe;
    FixedVector<int, 50> numCopie;
	int counter;

public:
    Mazzo(std::string nome, AbstractCard::Classe classe, FixedVector<int, 50> numCopie, unsigned int counter);
	
    std::string getNomeMazzo() const;
    void setNomeMazzo(std::string);
	AbstractCard::Classe getClasse() const;
    void setClasse(AbstractCard::Classe set);
    FixedVector<int, 50> getNumCopie() const;
    int getCounter() const;

	void addCard(const AbstractCard&);
	void removeCard(const AbstractCard&);
};

#endif  //MAZZO_H
