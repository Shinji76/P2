#include <algorithm>

#include "Memory.h"
#include "ItemDecorator.h"
#include "ScoreVisitor.h"
#include "FilterVisitor.h"

namespace Engine {

Memory::Memory() {
}

Memory::~Memory() {
}

Memory& Memory::add(const AbstractCard* card) {
    cards.push_back(card);
    return *this;
}

Memory& Memory::remove(const AbstractCard* card) {
    std::vector<const AbstractCard*>::iterator position = std::find(cards.begin(), cards.end(), card);
    if (position != cards.end()) {
        cards.erase(position);
    }
    return *this;
}

Memory& Memory::clear() {
    cards.clear();
    return *this;
}

ResultSet Memory::search(const Query& query) const {
    FilterVisitor filter_visitor(query);
    std::vector<AbstractCard> results;

    for (auto cit = cards.begin(); cit != cards.end(); cit++) {
        (*cit)->accept(filter_visitor);
        if (filter_visitor.hasMatch()) {
            results.push_back(*(*cit));
        }
    }
    std::sort(results.begin(), results.end());

    // Populates result set
    ResultSet result_set(results.size());
    for (unsigned int i = query.getOffset(); i < query.getOffset() + query.getSize(); i++) {
        if (results.size() <= i) {
            break;
        }
        result_set.add(results[i]);
    }
    return result_set;
}

}