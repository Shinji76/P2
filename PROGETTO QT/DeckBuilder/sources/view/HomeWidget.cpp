#include "HomeWidget.h"
#include "MainWindow.h"

#include <QHBoxLayout>

HomeWidget::HomeWidget(QWidget *parent) : QWidget(parent) {
    QPushButton* createDeckButton = new QPushButton("Crea mazzo", this);
    connect(createDeckButton, &QPushButton::clicked, this, &HomeWidget::handleCreateDeckButtonClick);

    QPushButton* openDeckButton = new QPushButton("Apri mazzo", this);
    connect(openDeckButton, &QPushButton::clicked, this, &HomeWidget::handleOpenDeckButtonClick);

    QHBoxLayout *layout = new QHBoxLayout(this);    //decidere se cambiare in Verticale
    layout->addWidget(createDeckButton);
    layout->addWidget(openDeckButton);
}

void HomeWidget::handleCreateDeckButtonClick()
{
    createDeckButton->addAction(newDeck);
}

void HomeWidget::handleOpenDeckButtonClick()
{
    openDeckButton->addAction(openDeck);
    // Aggiungere il codice "Apri mazzo".
}