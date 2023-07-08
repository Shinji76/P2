#include "../Cards/AbstractCard.h"
#include "ResultSet.h"
#include "FilterVisitor.h"

#include <vector>

class Memory {
private:
	std::vector<const AbstractCard*> memory;

public:
	Memory();
	Memory(std::vector<const AbstractCard*>);
	virtual ~Memory();
	//virtual Memory& clear();
	virtual ResultSet& search(const Query& query) const;
  	std::vector<const AbstractCard*> getMemory();
};