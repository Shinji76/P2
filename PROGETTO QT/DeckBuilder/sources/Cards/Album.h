#ifndef ALBUM_H
#define ALBUM_H

#include "../Vector_template.h"
#include "AbstractCard.h"

class Album {
private:
    FixedVector<AbstractCard*> album;
public:
    Album();
    Album(FixedVector<AbstractCard*>);
    ~Album();

    FixedVector<AbstractCard*> getAlbum();
    const AbstractCard& getCardFromID(int ID) const;
};

#endif //ALBUM_H
