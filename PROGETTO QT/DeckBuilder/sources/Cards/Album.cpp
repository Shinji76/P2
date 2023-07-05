#include "Vector_template.h"
#include "Album.h"

Album::Album() : album(FixedVector<AbstractCard*,50>()) {

}

Album::Album(FixedVector<AbstractCard*, 50> album) : album(album) {

}

const AbstractCard* Album::getCardFromID(int ID) const {
    return album[ID];
}
