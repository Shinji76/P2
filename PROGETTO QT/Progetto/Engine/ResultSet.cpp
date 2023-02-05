#include "ResultSet.h"

ResultSet::ResultSet(const unsigned int total) : total(total) {}

unsigned int ResultSet::getTotal() const {
    return total;
}

const std::vector<AbstractCard>& ResultSet::getCards() const {
    return cards;
}

ResultSet& ResultSet::add(const AbstractCard card) {
    cards.push_back(card);
    return *this;
}
