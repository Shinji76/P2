#ifndef JSON_CONVERTER_READER_H
#define JSON_CONVERTER_READER_H

#include "IReader.h"
#include "../Mostro.h"
#include "../Magia.h"
#include "../Segreto.h"
#include <QJsonObject>
#include <map>

class Reader: public IReader {
private:
	std::map<unsigned int, AbstractCard*> cache;
	
    AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;

public:
	const std::map<unsigned int, AbstractCard*>& getCache() const;
	virtual AbstractCard* read(const QJsonObject& object);
	Reader& clear();
};

#endif //CONVERTER_JSON_READER_H