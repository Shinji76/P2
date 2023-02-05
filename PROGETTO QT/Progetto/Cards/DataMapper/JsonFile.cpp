#include "JsonFile.h"
//#include "../../Service/Logger/Singleton.h"
#include "../JSONConverter/Reader.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>


JsonFile::JsonFile(const std::string& path, Json& converter)
    : path(path), converter(converter)
{
}

JsonFile JsonFile::fromPath(const std::string& path) {
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path, converter);
    return data_mapper;
}

const std::string& JsonFile::getPath() const {
    return path;
}

JsonFile& JsonFile::setPath(const std::string& path) {
    this->path = path;
    return *this;
}

const Json& JsonFile::getConverter() const {
    return converter;
}

// @todo check errors
JsonFile& JsonFile::store(const std::vector<AbstractCard*> cards) {
    QJsonArray json_items;
    for (auto cit = items.begin(); cit != items.end(); cit++) {
        json_items.push_back(converter.fromObject(**it));
    }
    QJsonDocument document(json_items);
    QFile json_file(path.c_str());
    json_file.open(QFile::WriteOnly);
    json_file.write(document.toJson());
    json_file.close();
    return *this;
}

// @todo check errors
std::vector<AbstractCard*> JsonFile::load() {
    std::vector<AbstractCard*> items;
    QFile json_file(path.c_str());
    json_file.open(QFile::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_items = document.array();

    for (const QJsonValue& value: json_items) {
        QJsonObject json_object = value.toObject();
        items.push_back(converter.toObject(json_object));
    }
    return items;
}
