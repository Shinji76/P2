#include "FilterVisitor.h"

#include "../Cards/AbstractCard.h"

FilterVisitor::FilterVisitor(const Query& query) : query(query), match(false), numeric_filter() {}

const Query& FilterVisitor::getQuery() const {
    return query;
}

bool FilterVisitor::hasMatch() const {
    return match;
}

void FilterVisitor::visit(const Mostro& mostro) {
    match = mostro.getNome().find(query.getFilter()) != std::string::npos
        || mostro.getClasse().find(query.getFilter()) != std::string::npos
        || mostro.getAttacco().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Magia& magia) {
    match = magia.getNome().find(query.getFilter()) != std::string::npos
        || magia.getDescription().find(query.getFilter()) != std::string::npos
        || magia.getSku().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Segreto& segreto) {
    match = segreto.getNome().find(query.getFilter()) != std::string::npos
        || segreto.getDescription().find(query.getFilter()) != std::string::npos
        || segreto.getSku().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Bundle& bundle) {
    match = bundle.getName().find(query.getFilter()) != std::string::npos
        || bundle.getDescription().find(query.getFilter()) != std::string::npos
        || bundle.getSku().find(query.getFilter()) != std::string::npos
    ;
    if (match) {
        return;
    }
    for (
        std::vector<const Item::AbstractProduct*>::const_iterator it = bundle.getProducts().begin();
        it != bundle.getProducts().end();
        it++
    ) {
        (*it)->accept(*this);
        if (match) {
            return;
        }
    }
}
