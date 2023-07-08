#ifndef JSON_CONVERTER_READER_H
#define JSON_CONVERTER_READER_H

#include "IReader.h"
#include "../../Vector_template.h"

#include <QJsonObject>

class Reader: public IReader {
private:
    FixedVector<AbstractCard*> cache;
	
    AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;

public:
	const FixedVector<AbstractCard*>& getCache() const;
	AbstractCard* read(const QJsonObject& object);
	//Reader& clear();
};

#endif //CONVERTER_JSON_READER_H
