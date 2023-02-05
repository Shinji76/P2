#ifndef JSONCONVERTER_READER_H
#define JSONCONVERTER_READER_H

#include "IReader.h"
//#include <QJsonObject>
#include <map>

class Reader: public IReader {
private:
	std::map<unsigned int, AbstractCard*> cache;
	AbstractCard* readMostro(const QJsonObject& object) const;
	AbstractCard* readMagia(const QJsonObject& object) const;
	AbstractCard* readSegreto(const QJsonObject& object) const;

public:
	const std::map<unsigned int, AbstractCard*>& getCache() const;
	Reader& clear();
	virtual AbstractCard* read(const QJsonObject& object);
};

#endif //CONVERTER_JSON_READER_H