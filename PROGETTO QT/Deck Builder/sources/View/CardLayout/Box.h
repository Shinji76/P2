#ifndef VIEW_ITEM_RENDERER_CARD_H
#define VIEW_ITEM_RENDERER_CARD_H

#include "CardVisualizer.h"
#include "../../Cards/Mostro.h"
#include "../../Cards/Magia.h"
#include "../../Cards/Segreto.h"

#include "../ResultsWidget.h"


class Box: public CardVisualizer {
private:
    QWidget* widget;
    QPushButton* add_button;
    QPushButton* remove_button;

public:
    virtual void visit(const Mostro& mostro);
    virtual void visit(const Magia& magia);
    virtual void visit(const Segreto& segreto);

    virtual QWidget* getWidget() const;
    virtual QPushButton* getAddButton() const;
    virtual QPushButton* getRemoveButton() const;
};

#endif