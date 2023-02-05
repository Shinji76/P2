#ifndef JSONCONVERTER_IREADER_H
#define JSONCONVERTER_IREADER_H

//#include <QJsonObject>
#include "../Cards/AbstractCard.h"

class IReader {
  public:
    virtual ~IReader() {};
    virtual AbstractCard* read(const QJsonObject& object) = 0;
};

#endif //CONVERTER_JSON_IREADER_H