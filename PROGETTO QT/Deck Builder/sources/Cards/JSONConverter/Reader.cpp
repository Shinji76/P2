#include "Reader.h"

#include <stdexcept>
#include <QJsonArray>

const std::map<unsigned int, AbstractCard*>& Reader::getCache() const {
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

AbstractCard* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("Type");
    //if (type.isUndefined()) {
    //    Service::Logger::Singleton::get().error("Missing item type.");
    //    throw std::invalid_argument("Missing item type.");
    //}

    const unsigned int identifier = object.value("ID").toInt();
    if (cache.count(identifier) > 0) {
        return cache[identifier];
    }
    else if (type.toString().compare("Mostro") == 0) {
        cache[identifier] = readMostro(object);
    }
    else if (type.toString().compare("Magia") == 0) {
        cache[identifier] = readMagia(object);
    }
    else if (type.toString().compare("Segreto") == 0) {
        cache[identifier] = readSegreto(object);
    }
    return cache[identifier];
}

AbstractCard* Reader::readMostro(const QJsonObject& object) const {
    AbstractCard::Rarita rarita;
    switch (object.value("Rarita").toInt()) {
        case 0:
            rarita = AbstractCard::Comune;
            break;
        case 1:
            rarita = AbstractCard::Rara;
            break;
        case 2:
            rarita = AbstractCard::Epica;
            break;
        case 3:
            rarita = AbstractCard::Leggendaria;
            break;
    }
    AbstractCard::Classe classe;
    switch (object.value("Classe").toInt()) {
        case 0:
            classe = AbstractCard::Neutrale;
            break;
        case 1:
            classe = AbstractCard::Cacciatore;
            break;
        case 2:
            classe = AbstractCard::Guerriero;
            break;
        case 3:
            classe = AbstractCard::Ladro;
            break;
        case 4:
            classe = AbstractCard::Mago;
            break;
        case 5:
            classe = AbstractCard::Stregone;
            break;
    }
    Mostro::Razza razza;
    switch (object.value("Razza").toInt()) {
        case 0:
            razza = Mostro::Comune;
            break;
        case 1:
            razza = Mostro::Bestia;
            break;
        case 2:
            razza = Mostro::Demone;
            break;
        case 3:
            razza = Mostro::Drago;
            break;
        case 4:
            razza = Mostro::Elementale;
            break;
        case 5:
            razza = Mostro::Murloc;
            break;
        case 6:
            razza = Mostro::Pirata;
            break;
    }
    return new Mostro(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,     //da sistemare con enum
        classe,     //da sistemare con enum
        object.value("Path").toString().toStdString(),
        razza,      //da sistemare con enum
        object.value("Attacco").toInt(),
        object.value("Difesa").toInt()
    );
}

AbstractCard* Reader::readMagia(const QJsonObject& object) const {
    AbstractCard::Rarita rarita;
    switch (object.value("Rarita").toInt()) {
        case 0:
            rarita = AbstractCard::Comune;
            break;
        case 1:
            rarita = AbstractCard::Rara;
            break;
        case 2:
            rarita = AbstractCard::Epica;
            break;
        case 3:
            rarita = AbstractCard::Leggendaria;
            break;
    }
    AbstractCard::Classe classe;
    switch (object.value("Classe").toInt()) {
        case 0:
            classe = AbstractCard::Neutrale;
            break;
        case 1:
            classe = AbstractCard::Cacciatore;
            break;
        case 2:
            classe = AbstractCard::Guerriero;
            break;
        case 3:
            classe = AbstractCard::Ladro;
            break;
        case 4:
            classe = AbstractCard::Mago;
            break;
        case 5:
            classe = AbstractCard::Stregone;
            break;
    }
    return new Magia(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,    //da sistemare con enum
        classe,    //da sistemare con enum
        object.value("Path").toString().toStdString()
    );
}

AbstractCard* Reader::readSegreto(const QJsonObject& object) const {
    AbstractCard::Rarita rarita;
    switch (object.value("Rarita").toInt()) {
        case 0:
            rarita = AbstractCard::Comune;
            break;
        case 1:
            rarita = AbstractCard::Rara;
            break;
        case 2:
            rarita = AbstractCard::Epica;
            break;
        case 3:
            rarita = AbstractCard::Leggendaria;
            break;
    }
    AbstractCard::Classe classe;
    switch (object.value("Classe").toInt()) {
        case 0:
            classe = AbstractCard::Neutrale;
            break;
        case 1:
            classe = AbstractCard::Cacciatore;
            break;
        case 2:
            classe = AbstractCard::Guerriero;
            break;
        case 3:
            classe = AbstractCard::Ladro;
            break;
        case 4:
            classe = AbstractCard::Mago;
            break;
        case 5:
            classe = AbstractCard::Stregone;
            break;
    }
    return new Segreto(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,    //da sistemare con enum
        classe,    //da sistemare con enum
        object.value("Path").toString().toStdString()
    );
}

