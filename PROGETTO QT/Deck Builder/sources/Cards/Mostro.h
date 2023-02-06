#ifndef MOSTRO_H
#define MOSTRO_H

#include "AbstractCard.h"

class Mostro : public AbstractCard {
public:
	enum Razza {
		Comune, Bestia, Demone, Drago, Elementale, Murloc, Pirata
	};
private:
	Razza razza;
	unsigned int attacco;
	unsigned int difesa;

public:
	//costruttore magia
	Mostro(
		const unsigned int ID,
		const std::string nome,
		const std::string effetto,
		const unsigned int mana,
		const Rarita rarita,
		const Classe classe,
        const std::string image_path,
		const Razza razza,
		const unsigned int attacco,
		const unsigned int difesa
	);
 
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
    
	Razza getRazza() const;
	unsigned int getAttacco() const;
	unsigned int getDifesa() const;    
	
};

#endif // MOSTRO_H