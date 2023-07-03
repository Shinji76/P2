#include "JsonFile.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

JsonFile::JsonFile(const std::string& path, Json& converter) : path(path), converter(converter) {}

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

// @todo modificare metodo per memorizzare classe del mazzo e counter
JsonFile& JsonFile::store(const Mazzo mazzo) {
    QJsonValue nome_mazzo(QString::fromStdString(mazzo.getNomeMazzo()));
    QJsonValue counter(mazzo.getCounter());
    QJsonValue classe(mazzo.getClasse());

	QJsonArray json_cards;
    for(auto cit = mazzo.getNumCopie().begin(); cit != mazzo.getNumCopie().end(); ++cit) {
        json_cards.push_back(*cit);
	}
	QJsonDocument document(json_cards);
	QFile json_file(path.c_str());
	json_file.open(QFile::WriteOnly);
	json_file.write(document.toJson());
	json_file.close();
	return *this;
}

// @todo modificare metodo per caricare classe del mazzo e counter
Mazzo JsonFile::load() {
	FixedVector<int, 50> json_vector;
	QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);

    std::string json_nome = document.object().value("Nome").toString().toStdString();

    AbstractCard::Classe json_classe;
    switch (document.object().value("Classe").toInt()) {
        case 0:
            json_classe = AbstractCard::Neutrale;
            break;
        case 1:
            json_classe = AbstractCard::Cacciatore;
            break;
        case 2:
            json_classe = AbstractCard::Guerriero;
            break;
        case 3:
            json_classe = AbstractCard::Ladro;
            break;
        case 4:
            json_classe = AbstractCard::Mago;
            break;
        case 5:
            json_classe = AbstractCard::Stregone;
            break;
    }

    unsigned int json_counter = document.object().value("Counter").toInt();
	QJsonArray json_cards = document.array();

	for(int i = 0; i < json_cards.size(); ++i) {
		QJsonValue json_value = json_cards.at(i);
		json_vector.push_back(json_value.toInt());
	}
    Mazzo mazzo(json_nome, json_classe, json_vector, json_counter);
	return mazzo;
};
