#include "Grid.h"

Grid::Grid(const unsigned int row_size) : row_size(row_size) {}

void Grid::render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    for (cit = result.getCards().begin(); cit != result.getCards().end(); cit++) {
        it->getCards()->accept(card);
        QWidget* widget = box.getWidget();
        grid->addWidget(widget, index / row_size, index % row_size);
        lookup->push_back(WidgetLookup(
            it->getCards(),
            widget,
            card.getAddButton(),
            card.getRemoveButton()
        ));
        index++;
    }
}
