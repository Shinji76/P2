#include "JsonFileAlbum.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

JsonFileAlbum::JsonFileAlbum(const std::string& path, Json& converter) : path(path), converter(converter) {}

JsonFileAlbum JsonFileAlbum::fromPath(const std::string& path) {
	Reader reader;
	Json converter(reader);
	JsonFileAlbum data_mapper(path, converter);
	return data_mapper;
}

const std::string& JsonFileAlbum::getPath() const {
	return path;
}

const Json& JsonFileAlbum::getConverter() const {
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
