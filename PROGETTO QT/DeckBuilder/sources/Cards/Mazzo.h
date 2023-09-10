#ifndef MAZZO_H
#define MAZZO_H

#include "../Vector_template.h"
#include "AbstractCard.h"
#include <string>

class Mazzo {
private:
    std::string nome;
	AbstractCard::Classe classe;
    FixedVector<int> numCopie;
	int counter = 0;

public:
    Mazzo();
    Mazzo(std::string nome, AbstractCard::Classe classe, FixedVector<int> numCopie, unsigned int counter);
    
    void setClasse(AbstractCard::Classe set);
	
    std::string getNome() const;
    void setNome(std::string nome);
    AbstractCard::Classe getClasse() const;
    FixedVector<int> getNumCopie() const;
    int getCounter() const;

    void clear();
	void addCard(unsigned int id);
	void removeCard(unsigned int id);

    bool isFull(const AbstractCard* card);
};

#endif  //MAZZO_H
