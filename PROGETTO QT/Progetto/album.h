#ifndef ALBUM_H
#define ALBUM_H

#include<vector>
#include "carta.h"

class Album {
private:
	std::vector<Carta*> cards;
	const unsigned int size = 50;
public:
	unsigned int getSize() const;
};

#endif //ALBUM_H