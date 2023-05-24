#ifndef ALBUM_H
#define ALBUM_H

#include "../Vector_template.h"
#include "AbstractCard.h"

class Album {
private:
	Fixed_vector<AbstractCard*> cards;
	const unsigned int ASize = cards.getSize();
public:
	unsigned int getASize() const;
    Album();
    ~Album();
};

#endif //ALBUM_H