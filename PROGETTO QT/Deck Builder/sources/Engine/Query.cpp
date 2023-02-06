#include "Query.h"

Query::Query(
    const std::string text,
    const std::string filter,
    const unsigned int offset,
    const unsigned int size,
    const unsigned int numeric_search) : text(text), filter(filter), offset(offset), size(size), numeric_search(numeric_search) {}

const std::string& Query::getText() const {
    return text;
}

const std::string& Query::getFilter() const {
    return filter;
}

unsigned int Query::getOffset() const {
    return offset;
}

unsigned int Query::getSize() const {
    return size;
}

unsigned int Query::getNumericSearch() const {
    return numeric_search;
}

void Query::setNumericSearch(unsigned int set) {
    numeric_search = set;
}