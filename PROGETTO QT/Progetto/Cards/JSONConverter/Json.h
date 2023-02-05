#ifndef JSON_H
#define JSON_H

#include "IReader.h"
#include "../AbstractCard.h"
//#include <QJsonObject>
class Json {
private:
	IReader& reader;

public:
	Json(IReader& reader);
	const IReader& getReader() const;
	QJsonObject fromObject(const AbstractCard& card) const;
	AbstractCard* toObject(const QJsonObject& json) const;
};

#endif //JSON_H