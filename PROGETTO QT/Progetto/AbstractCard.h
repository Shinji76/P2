#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include <iostream>

class AbstractCard {
public:     //definisco enum
    enum Rarita {
        comune, raro, epico, leggendario
    };
    enum Classe {
        Guerriero, Ladro, Cacciatore, Mago, 
        Paladino, Sciamano, Druido, Stregone, Sacerdote
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

    virtual unsigned int getID() const = 0;
    virtual std::string getNome() const = 0;
    virtual std::string getEffetto() const = 0;
    virtual unsigned int getManaCost() const = 0;
    virtual Rarita getRarita() const = 0;
    virtual Classe getClasse() const = 0;

};

#endif // CARD_H