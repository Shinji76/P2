#ifndef ALBUM_H
#define ALBUM_H

#include "vector_template.h"
#include "carta.h"

class Album {
private:
	Fixed_vector<Carta> cards;
	const unsigned int ASize = cards.getSize();
public:
	unsigned int getASize() const;
    Album();
    ~Album();
};

#endif //ALBUM_H