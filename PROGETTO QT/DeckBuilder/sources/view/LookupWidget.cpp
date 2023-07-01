#include "LookupWidget.h"

LookupWidget::LookupWidget(
    const AbstractCard* card,
    QWidget* widget,
    QPushButton* add_button,
    QPushButton* remove_button
    ) : card(card), widget(widget), add_button(add_button), remove_button(remove_button) {}

const AbstractCard* LookupWidget::getCard() const {
    return card;
}

QWidget* LookupWidget::getWidget() const {
    return widget;
}

QPushButton* LookupWidget::getAddButton() const {
    return add_button;
}

QPushButton* LookupWidget::getRemoveButton() const {
    return remove_button;
}
