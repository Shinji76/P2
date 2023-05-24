#ifndef GRID_H
#define GRID_H

#include "IResultLayoutStrategy.h"

#include "../ResultsWidget.h"
#include "../CardLayout/Box.h"

class Grid: public IResultLayoutStrategy {
private:
    const unsigned int row_size;
    Box card;

public:
    Grid(const unsigned int row_size);
    virtual void render(QGridLayout* grid, ResultSet& result, QVector<WidgetLookup>* lookup);
};

#endif  //GRID_H