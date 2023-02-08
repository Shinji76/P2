#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

#include "../IConstVisitor.h"
#include "../Mostro.h"
#include "../Magia.h"
#include "../Segreto.h"

#include <QJsonObject>


class JsonVisitor: public IConstVisitor {
private:
    QJsonObject object;

public:
    QJsonObject getObject() const;
    void visit(const Mostro& mostro);
    void visit(const Magia& magia);
    void visit(const Segreto& segreto);
};

#endif  //JSON_VISITOR_H