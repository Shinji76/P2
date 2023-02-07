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
	const std::map<unsigned int, AbstractCard*>& getCache() const;
public:
	virtual AbstractCard* read(const QJsonObject& object);
	std::map<unsigned int, AbstractCard*> cache;
	Reader& clear();

private:
	AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;
};

#endif //CONVERTER_JSON_READER_H