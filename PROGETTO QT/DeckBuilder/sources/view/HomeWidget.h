#ifndef HOME_WIDGET_H
#define HOME_WIDGET_H

#include "MainWindow.h"
#include "ClassSelectionWidget.h"

#include <QWidget>
#include <QPushButton>

class HomeWidget : public QWidget {
Q_OBJECT
private:
    MainWindow* mainWindow;
    QWidget* widget;
    QPushButton* createDeckButton;
    QPushButton* openDeckButton;
    ClassSelectionWidget* classSelectionWidget;

public slots:
    void createDeckHandler();

public:
    explicit HomeWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

signals:
    void CreateDeck();
    void OpenDeck();
};

#endif // HOME_WIDGET_H
