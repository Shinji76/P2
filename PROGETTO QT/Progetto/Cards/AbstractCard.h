#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include "IConstVisitor.h"
#include "IVisitor.h"
#include <string>

class AbstractCard {
public:     //definisco enum
    enum Rarita {
        Comune, Rara, Epica, Leggendaria
    };
    enum Classe {
        Neutrale, Cacciatore, Guerriero, Ladro, Mago, Stregone
    };
private:
    const unsigned int ID;
    std::string nome;
    std::string effetto;
    unsigned int manaCost;
    Rarita rarita;
    Classe classe;
public:
    //costruttore card
    AbstractCard(
        unsigned int ID,
        std::string nome,
        std::string effetto,
        unsigned int mana,
        Rarita rarita,
        Classe classe
    );

    virtual ~AbstractCard() = 0;

    virtual void accept(IConstVisitor& visitor) const = 0;
    virtual void accept(IVisitor& visitor) = 0;

    virtual unsigned int getID() const = 0;
    virtual std::string getNome() const = 0;
    virtual std::string getEffetto() const = 0;
    virtual unsigned int getManaCost() const = 0;
    virtual Rarita getRarita() const = 0;
    virtual Classe getClasse() const = 0;

};

#endif // CARD_H