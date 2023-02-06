#include "Json.h"


Json::Json(IReader& reader) : reader(reader) {}

const IReader& Json::getReader() const {
    return reader;
}

QJsonObject Json::fromObject(const AbstractCard& card) const {
    JsonVisitor json_visitor;
    card.accept(json_visitor);
    return json_visitor.getObject();
}

AbstractCard* Json::toObject(const QJsonObject& json) const {
    return reader.read(json);
}
