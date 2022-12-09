#ifndef ALBUM_H
#define ALBUM_H

#include<vector>
#include "carta.h"

class Album {
private:
    std::vector<Carta*> cards;
    unsigned int size;
public:
    unsigned int getSize() const;
};

#endif //ALBUM_H