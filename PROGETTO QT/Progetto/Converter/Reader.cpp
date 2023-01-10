#include "Reader.h"
#include "../Mostro.h"
#include "../Magia.h"
#include "../Segreto.h"

#include <stdexcept>
//#include <QJsonArray>


const std::map<unsigned int, AbstractCard*>& Reader::getCache() const {
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

AbstractCard* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("type");
    if (type.isUndefined()) {
        Service::Logger::Singleton::get().error("Missing item type.");
        throw std::invalid_argument("Missing item type.");
    }

    const unsigned int identifier = object.value("id").toInt();
    if (cache.count(identifier) > 0) {
        return cache[identifier];
    }
    else if (type.toString().compare("mostro") == 0) {
        cache[identifier] = readMostro(object);
    }
    else if (type.toString().compare("magia") == 0) {
        cache[identifier] = readMagia(object);
    }
    else if (type.toString().compare("segreto") == 0) {
        cache[identifier] = readSegreto(object);
    }
    return cache[identifier];
}

AbstractCard* Reader::readMostro(const QJsonObject& object) const {
    return new Mostro(
        object.value("ID").toUnsignedInt(),
        object.value("nome").toString().toStdString(),
        object.value("effetto").toString().toStdString(),
        object.value("mana").toUnsignedInt(),
        object.value("rarita").toString().toStdString(),    //da sistemare con enum
        object.value("classe").toString().toStdString(),    //da sistemare con enum
        object.value("attacco").toUnsignedInt(),
        object.value("difesa").toUnsignedInt(),
    );
}

AbstractCard* Reader::readMagia(const QJsonObject& object) const {
    return new Magia(
        object.value("ID").toUnsignedInt(),
        object.value("nome").toString().toStdString(),
        object.value("effetto").toString().toStdString(),
        object.value("mana").toUnsignedInt(),
        object.value("rarita").toString().toStdString(),    //da sistemare con enum
        object.value("classe").toString().toStdString(),    //da sistemare con enum
    );
}

AbstractCard* Reader::readSegreto(const QJsonObject& object) const {
    return new Segreto(
        object.value("ID").toUnsignedInt(),
        object.value("nome").toString().toStdString(),
        object.value("effetto").toString().toStdString(),
        object.value("mana").toUnsignedInt(),
        object.value("rarita").toString().toStdString(),    //da sistemare con enum
        object.value("classe").toString().toStdString(),    //da sistemare con enum
    );
}

