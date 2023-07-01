#include <algorithm>

#include "Memory.h"
#include "Sorting.h"


Memory::Memory() {
}

Memory::~Memory() {
}

Memory& Memory::add(const AbstractCard* card) {
    cards.push_back(card);
    return *this;
}

Memory& Memory::remove(const AbstractCard* card) {
    auto position = std::find(cards.begin(), cards.end(), card);
    if(position != cards.end()) {
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
    std::vector<const AbstractCard*> results;

    for(auto cit = cards.begin(); cit != cards.end(); cit++) {
        (*cit)->accept(filter_visitor);
        if(filter_visitor.hasMatch()) {
            results.push_back(*cit);
        }
    }

    if(query.getSort() == 1) {
        std::sort(results.begin(), results.end(), Sorting::sortByNameAscending);
    }
    else if(query.getSort() == 2) {
        std::sort(results.begin(), results.end(), Sorting::sortByNameDescending);
    }
    else if(query.getSort() == 3) {
        std::sort(results.begin(), results.end(), Sorting::sortByManaCostAscending);    
    }
    else if(query.getSort() == 4) {
        std::sort(results.begin(), results.end(), Sorting::sortByManaCostDescending);    
    }

    ResultSet result_set(results.size());
    for(unsigned int i = query.getOffset(); i < query.getOffset() + 9; i++) {
        if(results.size() <= i) {
            break;
        }
        result_set.add(results[i]);
    }
    return result_set;
}
