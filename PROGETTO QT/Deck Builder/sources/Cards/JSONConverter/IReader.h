#ifndef JSON_CONVERTER_IREADER_H
#define JSON_CONVERTER_IREADER_H

//#include <QJsonObject>
#include "../Cards/AbstractCard.h"

class IReader {
public:
    virtual ~IReader() {};
    virtual AbstractCard* read(const QJsonObject& object) = 0;
};

#endif //JSON_CONVERTER_IREADER_H