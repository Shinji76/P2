#ifndef SORTING_H
#define SORTING_H

#include "../Cards/AbstractCard.h"

#include <vector>

class Sorting {

private:
public:
    Sorting();
    ~Sorting();
    static bool sortByNameAscending(const AbstractCard* card1, const AbstractCard* card2);
    static bool sortByNameDescending(const AbstractCard* card1, const AbstractCard* card2);
    static bool sortByManaCostAscending(const AbstractCard* card1, const AbstractCard* card2);
    static bool sortByManaCostDescending(const AbstractCard* card1, const AbstractCard* card2);
};

#endif //SORTING_H

