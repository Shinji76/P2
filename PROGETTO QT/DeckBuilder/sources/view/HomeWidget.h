#ifndef HOME_WIDGET_H
#define HOME_WIDGET_H

#include "ClassSelectionWidget.h"

#include <QWidget>
#include <QPushButton>

class HomeWidget : public QWidget {
Q_OBJECT
private:
    QWidget* widget;
    QPushButton* createDeckButton;
    QPushButton* openDeckButton;
    ClassSelectionWidget* classSelectionWidget;

public:
    explicit HomeWidget(QWidget *parent = nullptr);

signals:
    void CreateDeck();
    void OpenDeck();

public slots:
    void createDeckHandler();
};

#endif // HOME_WIDGET_H
