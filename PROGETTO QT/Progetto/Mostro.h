#ifndef MOSTRO_H
#define MOSTRO_H

#include "AbstractCard.h"

class Mostro : public AbstractCard {
public:
	enum Razza {
		Neutrale=0, Bestia, Demone, Drago, Elementale, Murloc, Pirata
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
		const Razza razza = Neutrale,
		const unsigned int attacco = 0,
		const unsigned int difesa = 0
	);
};

#endif // MOSTRO_H