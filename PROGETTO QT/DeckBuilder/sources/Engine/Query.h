#ifndef QUERY_H
#define QUERY_H

#include "Sorting.h"

#include <string>

class Query {
private:
    const std::string name_filter;
    const unsigned int mana_filter;
    const std::string type_filter;
    const unsigned int sorting_type;
    const unsigned int offset;

public:
    Query(
        const std::string name_filter,
        const unsigned int mana_filter,
        const std::string type_filter,
        const unsigned int sorting_type,
        const unsigned int offset
    );

    const std::string& getName() const;
    unsigned int getMana() const;
    const std::string& getType() const;
    unsigned int getSort() const;
    unsigned int getOffset() const;
};

#endif  //QUERY_H
