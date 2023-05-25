#ifndef LOOKUP_WIDGET_H
#define LOOKUP_WIDGET_H

#include <QWidget>
#include <QPushButton>

#include "../Cards/AbstractCard.h"

class LookupWidget {
private:
    const AbstractCard* card;
    QWidget* widget;
    QPushButton* add_button;
    QPushButton* remove_button;

public:
    LookupWidget(
        const AbstractCard* card,
        QWidget* widget,
        QPushButton* add_button,
        QPushButton* remove_button
    );

    const AbstractCard* getCard() const;
    QPushButton* getWidget() const;
    QPushButton* getAddButton() const;
    QPushButton* getRemoveButton() const;
};

#endif //LOOKUP_WIDGET_H
