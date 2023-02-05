#ifndef QUERY_H
#define QUERY_H

#include <string>

class Query {
private:
    const std::string text;
    const std::string filter;
    const unsigned int offset;
    const unsigned int size;

public:
    Query(
        const std::string text,
        const std::string filter,
        const unsigned int offset,
        const unsigned int size
    );

    const std::string& getText() const;
    const std::string& getFilter() const;
    unsigned int getOffset() const;
    unsigned int getSize() const;
};

#endif  //QUERY_H