#include "JsonAlbum.h"

JsonAlbum::JsonAlbum(IReader& reader) : reader(reader) {}

const IReader& JsonAlbum::getReader() const {
    return reader;
}

AbstractCard* JsonAlbum::toObject(const QJsonObject& json) const {
    return reader.read(json);
}
