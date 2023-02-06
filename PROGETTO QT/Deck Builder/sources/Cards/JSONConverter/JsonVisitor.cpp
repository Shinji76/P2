#include "JsonVisitor.h"

#include <QJsonArray>

QJsonObject JsonVisitor::getObject() const {
    return object;
}

void JsonVisitor::visit(const Mostro& mostro) {
    QJsonObject mostro_object;
    mostro_object.insert("Type", QJsonValue::fromVariant("Mostro"));
    mostro_object.insert("ID", QJsonValue::fromVariant(mostro.getID()));
    mostro_object.insert("Nome", QJsonValue::fromVariant(mostro.getNome().c_str()));
    mostro_object.insert("Effetto", QJsonValue::fromVariant(mostro.getEffetto().c_str()));
    mostro_object.insert("Mana", QJsonValue::fromVariant(mostro.getManaCost()));
    mostro_object.insert("Rarita", QJsonValue::fromVariant(mostro.getRarita().c_str()));
    mostro_object.insert("Classe", QJsonValue::fromVariant(mostro.getClasse().c_str()));
    mostro_object.insert("Razza", QJsonValue::fromVariant(mostro.getRazza().c_str()));
    mostro_object.insert("Attacco", QJsonValue::fromVariant(mostro.getAttacco()));
    mostro_object.insert("Difesa", QJsonValue::fromVariant(mostro.getDifesa()));
    object = mostro_object;
}

void JsonVisitor::visit(const Magia& magia) {
    QJsonObject magia_object;
    magia_object.insert("Type", QJsonValue::fromVariant("Magia"));
    magia_object.insert("ID", QJsonValue::fromVariant(magia.getID()));
    magia_object.insert("Nome", QJsonValue::fromVariant(magia.getNome().c_str()));
    magia_object.insert("Effetto", QJsonValue::fromVariant(magia.getEffetto().c_str()));
    magia_object.insert("Mana", QJsonValue::fromVariant(magia.getManaCost()));
    magia_object.insert("Rarita", QJsonValue::fromVariant(magia.getRarita().c_str()));
    magia_object.insert("Classe", QJsonValue::fromVariant(magia.getClasse()));
    object = magia_object;
}

void JsonVisitor::visit(const Segreto& segreto) {
    QJsonObject segreto_object;
    segreto_object.insert("Type", QJsonValue::fromVariant("Segreto"));
    segreto_object.insert("ID", QJsonValue::fromVariant(segreto.getID()));
    segreto_object.insert("Nome", QJsonValue::fromVariant(segreto.getNome().c_str()));
    segreto_object.insert("Effetto", QJsonValue::fromVariant(segreto.getEffetto().c_str()));
    segreto_object.insert("Mana", QJsonValue::fromVariant(segreto.getManaCost()));
    segreto_object.insert("Rarita", QJsonValue::fromVariant(segreto.getRarita().c_str()));
    segreto_object.insert("Classe", QJsonValue::fromVariant(segreto.getClasse()));
    object = segreto_object;
}
