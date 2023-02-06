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
    return new Mostro(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        object.value("Rarita").toInt(),     //da sistemare con enum
        object.value("Classe").toInt(),     //da sistemare con enum
        object.value("Razza").toInt(),      //da sistemare con enum
        object.value("Attacco").toInt(),
        object.value("Difesa").toInt(),
    );
}

AbstractCard* Reader::readMagia(const QJsonObject& object) const {
    return new Magia(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        object.value("Rarita").toInt(),    //da sistemare con enum
        object.value("Classe").toInt(),    //da sistemare con enum
    );
}

AbstractCard* Reader::readSegreto(const QJsonObject& object) const {
    return new Segreto(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        object.value("Rarita").toInt(),    //da sistemare con enum
        object.value("Classe").toInt(),    //da sistemare con enum
    );
}

