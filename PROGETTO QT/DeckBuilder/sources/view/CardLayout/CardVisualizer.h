#ifndef VIEW_ITEM_RENDERER_I_ITEM_RENDERER_H
#define VIEW_ITEM_RENDERER_I_ITEM_RENDERER_H

#include <QWidget>
#include <QPushButton>

#include "../../Cards/AbstractCard.h"
#include "../../Cards/IConstVisitor.h"


class CardVisualizer: public IConstVisitor {
public:
    virtual QWidget* getWidget() const = 0;
    virtual QPushButton* getAddButton() const = 0;
    virtual QPushButton* getRemoveButton() const = 0;
};

#endif