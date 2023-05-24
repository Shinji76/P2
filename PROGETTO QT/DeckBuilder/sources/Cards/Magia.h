#ifndef MAGIA_H
#define MAGIA_H

#include "AbstractCard.h"

class Magia : public AbstractCard {
public:
    //costruttore magia
    Magia(
        const unsigned int ID,
        const std::string nome,
        const std::string effetto,
        const unsigned int mana,
        const Rarita rarita,
        const Classe classe,
        std::string image_path
    );
    
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);

};


#endif // MAGIA_H
