#ifndef HOME_WIDGET_H
#define HOME_WIDGET_H

#include "ClassSelectionWidget.h"

#include <QLabel>
#include <QWidget>
#include <QPushButton>

class HomeWidget : public QWidget {
Q_OBJECT
private:
    QWidget* widget;
    QPushButton* createDeckButton;
    QPushButton* openDeckButton;

public:
    explicit HomeWidget(QWidget *parent = nullptr);

signals:
    void createDeck();
    void openDeck();

public slots:
    void createDeckHandler();
    void openDeckHandler();
};

#endif // HOME_WIDGET_H
