#ifndef I_VISITOR_H
#define I_VISITOR_H

class Mostro;
class Magia;
class Segreto;

class IVisitor {
  public:
    virtual ~IVisitor() {};
    virtual void visit(Mostro& mostro) = 0;
    virtual void visit(Magia& magia) = 0;
    virtual void visit(Segreto& segreto) = 0;
};


#endif  //I_VISITOR_H