#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>
#include <QPushButton>

class HomeWidget : public QWidget {
Q_OBJECT
private:
    QPushButton* createDeckButton;
    QPushButton* openDeckButton;

public:
    explicit HomeWidget(QWidget *parent = nullptr);

private slots:
    void handleCreateDeckButtonClick();
    void handleOpenDeckButtonClick();
};

#endif // HOMEWIDGET_H