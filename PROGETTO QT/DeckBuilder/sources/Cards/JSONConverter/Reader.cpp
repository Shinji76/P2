#include "Reader.h"
#include "Cards/Segreto.h"
#include "Cards/Magia.h"
#include "Cards/Mostro.h"

#include <stdexcept>
#include <QJsonArray>

const FixedVector<AbstractCard*>& Reader::getCache() const {
    return cache;
}

/*
Reader& Reader::clear() {
    cache.clear();
    return *this;
}
*/

AbstractCard* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("Type");
    if (type.isUndefined()) {
        throw std::invalid_argument("Missing item type.");
    }

    const unsigned int identifier = object.value("ID").toInt();
    if (type.toString().compare("Mostro") == 0) {
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
    std::string string_rarita = object.value("Rarita").toString().toStdString();
        if(string_rarita == "Comune") {
            rarita = AbstractCard::Comune;
        }
        else if(string_rarita == "Rara") {
            rarita = AbstractCard::Rara;
        }
        else if(string_rarita == "Epica") {
            rarita = AbstractCard::Epica;
        }
        else if(string_rarita == "Leggendaria") {
            rarita = AbstractCard::Leggendaria;
        }

    AbstractCard::Classe classe;
    std::string string_classe = object.value("Classe").toString().toStdString();
        if(string_classe == "Neutrale") {
            classe = AbstractCard::Neutrale;
        }
        else if(string_classe == "Cacciatore") {
            classe = AbstractCard::Cacciatore;
        }
        else if(string_classe == "Guerriero") {
            classe = AbstractCard::Guerriero;
        }
        else if(string_classe == "Ladro") {
            classe = AbstractCard::Ladro;
        }
        else if(string_classe == "Mago") {
            classe = AbstractCard::Mago;
        }
        else if(string_classe == "Stregone") {
            classe = AbstractCard::Stregone;
        }

    Mostro::Razza razza;
    std::string string_razza = object.value("Razza").toString().toStdString();
        if(string_razza == "Comune") {
            razza = Mostro::Comune;
        }
        else if(string_razza == "Bestia") {
            razza = Mostro::Bestia;
        }
        else if(string_razza == "Demone") {
            razza = Mostro::Demone;
        }
        else if(string_razza == "Drago") {
            razza = Mostro::Drago;
        }
        else if(string_razza == "Elementale") {
            razza = Mostro::Elementale;
        }
        else if(string_razza == "Murloc") {
            razza = Mostro::Murloc;
        }
        else if(string_razza == "Pirata") {
            razza = Mostro::Pirata;
        }

    return new Mostro(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,
        classe,
        object.value("Path").toString().toStdString(),
        razza,
        object.value("Attacco").toInt(),
        object.value("Difesa").toInt()
    );
}

AbstractCard* Reader::readMagia(const QJsonObject& object) const {
    AbstractCard::Rarita rarita;
    std::string string_rarita = object.value("Rarita").toString().toStdString();
        if(string_rarita == "Comune") {
            rarita = AbstractCard::Comune;
        }
        else if(string_rarita == "Rara") {
            rarita = AbstractCard::Rara;
        }
        else if(string_rarita == "Epica") {
            rarita = AbstractCard::Epica;
        }
        else if(string_rarita == "Leggendaria") {
            rarita = AbstractCard::Leggendaria;
        }

    AbstractCard::Classe classe;
    std::string string_classe = object.value("Classe").toString().toStdString();
        if(string_classe == "Neutrale") {
            classe = AbstractCard::Neutrale;
        }
        else if(string_classe == "Cacciatore") {
            classe = AbstractCard::Cacciatore;
        }
        else if(string_classe == "Guerriero") {
            classe = AbstractCard::Guerriero;
        }
        else if(string_classe == "Ladro") {
            classe = AbstractCard::Ladro;
        }
        else if(string_classe == "Mago") {
            classe = AbstractCard::Mago;
        }
        else if(string_classe == "Stregone") {
            classe = AbstractCard::Stregone;
        }
    return new Magia(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,
        classe,
        object.value("Path").toString().toStdString()
    );
}

AbstractCard* Reader::readSegreto(const QJsonObject& object) const {
AbstractCard::Rarita rarita;
    std::string string_rarita = object.value("Rarita").toString().toStdString();
        if(string_rarita == "Comune") {
            rarita = AbstractCard::Comune;
        }
        else if(string_rarita == "Rara") {
            rarita = AbstractCard::Rara;
        }
        else if(string_rarita == "Epica") {
            rarita = AbstractCard::Epica;
        }
        else if(string_rarita == "Leggendaria") {
            rarita = AbstractCard::Leggendaria;
        }
        
    AbstractCard::Classe classe;
    std::string string_classe = object.value("Classe").toString().toStdString();
        if(string_classe == "Neutrale") {
            classe = AbstractCard::Neutrale;
        }
        else if(string_classe == "Cacciatore") {
            classe = AbstractCard::Cacciatore;
        }
        else if(string_classe == "Guerriero") {
            classe = AbstractCard::Guerriero;
        }
        else if(string_classe == "Ladro") {
            classe = AbstractCard::Ladro;
        }
        else if(string_classe == "Mago") {
            classe = AbstractCard::Mago;
        }
        else if(string_classe == "Stregone") {
            classe = AbstractCard::Stregone;
        }
    return new Segreto(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        rarita,
        classe,
        object.value("Path").toString().toStdString()
    );
}

