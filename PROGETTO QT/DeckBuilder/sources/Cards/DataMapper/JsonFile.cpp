#include "JsonFile.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JsonFile::JsonFile(const std::string& path) : path(path) {}

const std::string& JsonFile::getPath() const {
	return path;
}

JsonFile& JsonFile::setPath(const std::string& new_path) {
	path = new_path;
	return *this;
}

JsonFile& JsonFile::store(const Mazzo mazzo) {
    QJsonObject nome;
    QJsonObject json_wrapper;
    QJsonValue counter(mazzo.getCounter());
    QJsonValue classe(mazzo.getClasse());

	QJsonArray json_cards;
    for(int i = 0; i < mazzo.getNumCopie().getSize(); ++i) {
        json_cards.push_back(mazzo.getNumCopie()[i]);
	}

    json_wrapper["nome"] = nome;
    json_wrapper["counter"] = counter; 
    json_wrapper["classe"] = classe;
    json_wrapper["numCopie"] = json_cards;
    
	QJsonDocument document(json_wrapper);
	QFile json_file(path.c_str());
	json_file.open(QFile::WriteOnly);
	json_file.write(document.toJson());
	json_file.close();
	return *this;
}

Mazzo& JsonFile::load() {
	FixedVector<int> json_vector;
    
	QFile json_file(path.c_str());
	json_file.open(QFile::ReadOnly);
	QByteArray data = json_file.readAll();
	json_file.close();
	QJsonDocument document = QJsonDocument::fromJson(data);

    QJsonObject json_object = document.object();
    
    std::string json_nome = json_object["nome"].toString().toStdString();

    AbstractCard::Classe json_classe;
    switch (json_object["classe"].toInt()) {
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

    unsigned int json_counter = json_object["counter"].toInt();
	QJsonArray json_cards = json_object["numCopie"].toArray();

	for(int i = 0; i < json_cards.size(); ++i) {
		QJsonValue json_value = json_cards.at(i);
		json_vector.push_back(json_value.toInt());
	}
    Mazzo* mazzo = new Mazzo(json_nome, json_classe, json_vector, json_counter);
	return *mazzo;
};
