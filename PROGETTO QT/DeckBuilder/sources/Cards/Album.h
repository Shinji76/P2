#ifndef ALBUM_H
#define ALBUM_H

#include "../Vector_template.h"
#include "AbstractCard.h"

class Album {
private:
    FixedVector<AbstractCard*, 50> album;
public:
    Album();
    Album(FixedVector<AbstractCard*, 50>);
    ~Album();

    const AbstractCard* getCardFromID(int ID) const;
};

#endif //ALBUM_H
