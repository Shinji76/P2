#ifndef SEGRETO_H
#define SEGRETO_H

#include "AbstractCard.h"

class Segreto : public AbstractCard {
public:
Segreto(
    const unsigned int ID,
    const std::string nome,
    const std::string effetto,
    const unsigned int mana,
    const Rarita rarita,
    const Classe classe
    );

virtual void accept(IConstVisitor& visitor) const;
virtual void accept(IVisitor& visitor);

};

#endif  //CARTA_SEGRETO_H