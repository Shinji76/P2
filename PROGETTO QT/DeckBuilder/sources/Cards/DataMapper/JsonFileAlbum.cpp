#include "JsonFileAlbum.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

JsonFileAlbum::JsonFileAlbum(const std::string& path, JsonAlbum& converter) : path(path), converter(converter), album() {}

JsonFileAlbum& JsonFileAlbum::fromPath(const std::string& path) {
	Reader reader;
	JsonAlbum converter(reader);
    JsonFileAlbum* data_mapper = new JsonFileAlbum(path, converter);
	return *data_mapper;
}

const std::string& JsonFileAlbum::getPath() const {
	return path;
}

const JsonAlbum& JsonFileAlbum::getConverter() const {
	return converter;
}

const Album& JsonFileAlbum::loadAlbum() {
	Album* album = new Album();
	QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);
	QJsonArray json_album = document.array();

	for(const QJsonValue& value : json_album) {
		QJsonObject json_object = value.toObject();
		album->getAlbum().push_back(converter.toObject(json_object));
	}
	return *album;
}

const std::vector<const AbstractCard*>& JsonFileAlbum::loadClass(AbstractCard::Classe classe) const {
    auto cards = new std::vector<const AbstractCard*>;
    QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_album = document.array();

    for(const QJsonValue& value : json_album) {
        QJsonObject json_object = value.toObject();
        if(json_object.value("Classe") == classe || json_object.value("Classe") == 0) {
            cards->push_back(converter.toObject(json_object));
        }
    }
    return *cards;
}
