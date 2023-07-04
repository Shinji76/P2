#ifndef JSON_ALBUM_H
#define JSON_ALBUM_H

#include "IReader.h"
#include "../AbstractCard.h"
#include "JsonVisitor.h"

#include <QJsonObject>

class JsonAlbum {
private:
	IReader& reader;
    
public: 
	JsonAlbum(IReader& reader);
	const IReader& getReader() const;
	QJsonObject fromObject(const AbstractCard& card) const;
	AbstractCard* toObject(const QJsonObject& json) const;
};

#endif //JSON_ALBUM_H
