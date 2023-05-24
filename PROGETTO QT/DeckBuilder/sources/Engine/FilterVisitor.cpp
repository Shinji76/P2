#include "FilterVisitor.h"

FilterVisitor::FilterVisitor(const Query& query) : query(query), match(false) {}

const Query& FilterVisitor::getQuery() const {
	return query;
}

bool FilterVisitor::hasMatch() const {
	return match;
}

void FilterVisitor::visit(const Mostro& mostro) {
	match = mostro.getNome().find(query.getFilter()) != std::string::npos;
}

void FilterVisitor::visit(const Magia& magia) {
	match = magia.getNome().find(query.getFilter()) != std::string::npos;
}

void FilterVisitor::visit(const Segreto& segreto) {
	match = segreto.getNome().find(query.getFilter()) != std::string::npos;
}
