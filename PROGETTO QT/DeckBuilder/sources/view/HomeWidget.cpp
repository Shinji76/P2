#include "HomeWidget.h"
#include <QHBoxLayout>

HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)   
{
    QGridLayout *grid = new QGridLayout(this);

    QLabel* title = new QLabel("Inizia il tuo percorso");
    grid->addWidget(title, 0, 0, 1, 2);
    title->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QPushButton* createDeckButton = new QPushButton(QIcon(QPixmap((":/Assets/Icons/new.svg"))), "Crea mazzo");
    createDeckButton->setMinimumSize(300, 250);
    createDeckButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    grid->addWidget(createDeckButton, 1, 0);

    QPushButton* openDeckButton = new QPushButton(QIcon(QPixmap((":/Assets/Icons/open.svg"))), "Apri mazzo");
    openDeckButton->setMinimumSize(300, 250);
    openDeckButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    grid->addWidget(openDeckButton, 1, 1);

    connect(createDeckButton, SIGNAL(clicked()), this, SLOT(createDeckHandler()));
    connect(openDeckButton, SIGNAL(clicked()), this, SLOT(openDeckHandler()));
    connect(this, SIGNAL(createDeck()), parentWidget(), SLOT(newDeck()));
    connect(this, SIGNAL(openDeck()), parentWidget(), SLOT(openDeck()));
}

void HomeWidget::createDeckHandler() {
    emit createDeck();
}

void HomeWidget::openDeckHandler() {
    emit openDeck();
}
