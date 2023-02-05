#ifndef ENGINE_FILTER_VISITOR_H
#define ENGINE_FILTER_VISITOR_H

#include "Query.h"
#include "../Cards/Magia.h"
#include "../Cards/Mostro.h"
#include "../Cards/Segreto.h"

class FilterVisitor: public IConstVisitor {
private:
    const Query& query;
    bool match;

 public:
    FilterVisitor(const Query& query);
    const Query& getQuery() const;
    bool hasMatch() const;
    virtual void visit(const Mostro& mostro);
    virtual void visit(const Magia& magia);
    virtual void visit(const Segreto& segreto);
};

#endif