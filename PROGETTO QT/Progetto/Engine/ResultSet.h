#ifndef RESULT_SET_H
#define RESULT_SET_H

#include "../Cards/AbstractCard.h"

#include <vector>

class ResultSet {
private:
    const unsigned int total;
    std::vector<const AbstractCard*> cards;

public:
    ResultSet(const unsigned int total);
    unsigned int getTotal() const;
    const std::vector<const AbstractCard*>& getCards() const;
    ResultSet& add(const AbstractCard* card);
};

#endif  //RESULT_SET_H