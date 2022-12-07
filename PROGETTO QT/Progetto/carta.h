#ifndef CARTA_H
#define CARTA_H

#include <iostream>

class Carta {
public:     //definisco enum
    enum Rarita {
        comune, raro, epico, leggendario
    };
    enum Classe {
        Guerriero, Ladro, Cacciatore, Mago, 
        Paladino, Sciamano, Druido, Stregone, Sacerdote
    };
private:
    unsigned int ID;
    std::string nome;
    std::string effetto;
    unsigned int mana_cost;
    Rarita rarita;
    Classe classe;

public:
    //costruttore carta
    Carta(
        const unsigned int ID,
        const std::string nome,
        const std::string effetto,
        const unsigned int mana,
        const Rarita rarita,
        const Classe classe
    );

    virtual ~Carta() = 0;

    unsigned int getID() const;
};

#endif // CARTA_H