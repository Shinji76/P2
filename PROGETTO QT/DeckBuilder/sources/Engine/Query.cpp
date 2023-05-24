#include "Query.h"

Query::Query(
    const std::string filter,
    const unsigned int offset,
    const unsigned int size) : filter(filter), offset(offset), size(size) {}

const std::string& Query::getFilter() const {
    return filter;
}

unsigned int Query::getOffset() const {
    return offset;
}

unsigned int Query::getSize() const {
    return size;
}