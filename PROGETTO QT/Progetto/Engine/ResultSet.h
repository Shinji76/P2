#ifndef ENGINE_RESULT_SET_H
#define ENGINE_RESULT_SET_H

#include "../Cards/AbstractCard.h"

#include <vector>

class ResultSet {
private:
    const unsigned int total;
    std::vector<AbstractCard> cards;

public:
    ResultSet(const unsigned int total);
    unsigned int getTotal() const;
    const std::vector<AbstractCard>& getCards() const;
    ResultSet& add(const AbstractCard card);
};

#endif