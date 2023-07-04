#include "JsonFileAlbum.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

JsonFileAlbum::JsonFileAlbum(const std::string& path, JsonAlbum& converter) : path(path), converter(converter), album() {}

JsonFileAlbum JsonFileAlbum::fromPath(const std::string& path) {
	Reader reader;
	JsonAlbum converter(reader);
    JsonFileAlbum data_mapper(path, converter);
	return data_mapper;
}

const std::string& JsonFileAlbum::getPath() const {
	return path;
}

const JsonAlbum& JsonFileAlbum::getConverter() const {
	return converter;
}

std::vector<AbstractCard*> JsonFileAlbum::loadAlbum() const {
	std::vector<AbstractCard*> album;
	QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);
	QJsonArray json_album = document.array();

	for(const QJsonValue& value : json_album) {
		QJsonObject json_object = value.toObject();
		album.push_back(converter.toObject(json_object));
	}
	return album;
}

FixedVector<AbstractCard*, 50> JsonFileAlbum::loadClass(AbstractCard::Classe classe) const {
    FixedVector<AbstractCard*, 50> cards;
    QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);
	QJsonArray json_album = document.array();

    for(const QJsonValue& value : json_album) {
        QJsonObject json_object = value.toObject();
        if(json_object.value("Classe") == classe || json_object.value("Classe") == 0) {
            cards.push_back(converter.toObject(json_object));
        }
    }
    return cards;
}
