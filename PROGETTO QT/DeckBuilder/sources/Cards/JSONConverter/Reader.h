#ifndef JSON_CONVERTER_READER_H
#define JSON_CONVERTER_READER_H

#include "IReader.h"

#include <QJsonObject>
#include <map>

class Reader: public IReader {
private:
    FixedVector<AbstractCard*, 50> cache;
	
    AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;

public:
	const FixedVector<AbstractCard*>& getCache() const;
	AbstractCard* read(const QJsonObject& object) override;
	Reader& clear();
};

#endif //CONVERTER_JSON_READER_H
