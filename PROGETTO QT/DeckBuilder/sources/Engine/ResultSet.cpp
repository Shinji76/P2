#include "ResultSet.h"

ResultSet::ResultSet(const unsigned int total) : total(total) {}

unsigned int ResultSet::getTotal() const {
    return total;
}

const std::vector<const AbstractCard*>& ResultSet::getResult() const {
    return result;
}

ResultSet& ResultSet::add(const AbstractCard* card) {
    result.push_back(card);
    return *this;
}
