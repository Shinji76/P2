#include "Sorting.h"
#include <algorithm>

Sorting::Sorting() {
}

Sorting::~Sorting() {
}

bool Sorting::sortByNameAscending(const AbstractCard* card1, const AbstractCard* card2) {
        return card1->getNome() < card2->getNome();
}

bool Sorting::sortByNameDescending(const AbstractCard* card1, const AbstractCard* card2) {
        return card1->getNome() > card2->getNome();
}
    
bool Sorting::sortByManaCostAscending(const AbstractCard* card1, const AbstractCard* card2) {
    return card1->getManaCost() < card2->getManaCost();
}
    
bool Sorting::sortByManaCostDescending(const AbstractCard* card1, const AbstractCard* card2) {
    return card1->getManaCost() > card2->getManaCost();
}
