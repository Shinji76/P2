#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include "IConstVisitor.h"
#include "IVisitor.h"
#include <string>

class AbstractCard {
public:
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
    unsigned int mana;
    Rarita rarita;
    Classe classe;
    std::string image_path;
    
public:
    AbstractCard(
        unsigned int ID,
        std::string nome,
        std::string effetto,
        unsigned int mana,
        Rarita rarita,
        Classe classe,
        std::string image_path
    );

    virtual ~AbstractCard() = 0;

    virtual void accept(IConstVisitor& visitor) const = 0;
    virtual void accept(IVisitor& visitor) = 0;

    virtual unsigned int getID() const;
    virtual std::string getNome() const;
    virtual std::string getEffetto() const;
    virtual unsigned int getManaCost() const;
    virtual Rarita getRarita() const;
    virtual Classe getClasse() const;
    virtual const std::string getPath() const;
};

#endif // ABSTRACT_CARD_H
