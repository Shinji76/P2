#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include <QJsonObject>
#include "../AbstractCard.h"
#include "IReader.h"

class Json {
private:
	IReader& reader;

public:
	Json(IReader& reader);
	const IReader& getReader() const;
	QJsonObject fromObject(const AbstractCard& item) const;
	AbstractCard* toObject(const QJsonObject& json) const;
};

#endif //CONVERTE_JSON_H