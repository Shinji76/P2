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
    QWidget* getWidget() const;
    QPushButton* getAddButton() const;
    QPushButton* getRemoveButton() const;
    void enableAddButton();
    void enableRemoveButton();
    void disableAddButton();
    void disableRemoveButton();
};

#endif //LOOKUP_WIDGET_H
