#include "Progetto/AbstractCard.h"
#include "Engine/ResultSet.h"
#include <vector>

class Memory {
private:
	std::vector<const AbstractCard*> cards;

public:
	Memory();
	virtual ~Memory();
	virtual Memory& add(const AbstractCard* card);
	virtual Memory& remove(const AbstractCard* card);
	virtual Memory& clear();
	virtual ResultSet search(const Query& query) const;
};