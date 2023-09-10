#ifndef MEMORY_H
#define MEMORY_H

#include "../Cards/AbstractCard.h"
#include "ResultSet.h"

#include <vector>

class Memory {
private:
	std::vector<const AbstractCard*> memory;

public:
	Memory();
	Memory(std::vector<const AbstractCard*>);
	virtual ~Memory();
  	std::vector<const AbstractCard*> getMemory() const;
    const AbstractCard* getCardFromID(int ID) const;
};
#endif //MEMORY_H