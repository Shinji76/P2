#ifndef I_CONST_VISITOR_H
#define I_CONST_VISITOR_H

class Mostro;
class Magia;
class Segreto;

class IConstVisitor {
  public:
    virtual ~IConstVisitor() {};
    virtual void visit(const Mostro& mostro) = 0;
    virtual void visit(const Magia& magia) = 0;
    virtual void visit(const Segreto& segreto) = 0;
};


#endif  //I_CONST_VISITOR_H