#include "Query.h"

Query::Query(
    const std::string name_filter,
    const unsigned int mana_filter,
    const std::string type_filter,
    const unsigned int sorting_type,
    const unsigned int offset
    ) : name_filter(name_filter), mana_filter(mana_filter), type_filter(type_filter), sorting_type(sorting_type), offset(offset) {}

const std::string& Query::getName() const {
    return name_filter;
}

const std::string& Query::getType() const {
    return type_filter;
}

unsigned int Query::getOffset() const {
    return offset;
}

unsigned int Query::getSort() const {
    return sorting_type;
}

unsigned int Query::getMana() const {
    return mana_filter;
}
