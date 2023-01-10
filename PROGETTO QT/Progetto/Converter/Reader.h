#ifndef CONVERTER_JSON_READER_H
#define CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>

#include "IReader.h"

class Reader: public IReader {
private:
	std::map<unsigned int, AbstractItem*> cache;
	AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;

public:
	const std::map<unsigned int, AbstractItem*>& getCache() const;
	Reader& clear();
	virtual AbstractCard* read(const QJsonObject& object);
};

#endif //CONVERTER_JSON_READER_H