#include "Vector_template.h"
#include "Album.h"

Album::Album() : album(FixedVector<AbstractCard*>()) {

}

Album::Album(FixedVector<AbstractCard*> album) : album(album) {

}

FixedVector<AbstractCard*> Album::getAlbum() {
    return album;
}

const AbstractCard& Album::getCardFromID(int ID) const {
    return *album[ID];
}
