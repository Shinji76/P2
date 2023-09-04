#include "HomeWidget.h"
#include <QHBoxLayout>

HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)   
{
    QVBoxLayout *vbox = new QVBoxLayout(this);    //decidere se cambiare in Verticale

    QLabel* title = new QLabel("Inizia il tuo percorso");
    vbox->addWidget(title);
    title->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout *hbox = new QHBoxLayout(this);    //decidere se cambiare in Verticale
    vbox->addLayout(hbox);

    QPushButton* createDeckButton = new QPushButton(
        QIcon(QPixmap((":/Assets/Icons/new.svg"))),
        "Crea mazzo"
    );
    createDeckButton->setMinimumSize(300, 250);
    createDeckButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    hbox->addWidget(createDeckButton);

    QPushButton* openDeckButton = new QPushButton(
        QIcon(QPixmap((":/Assets/Icons/open.svg"))),
        "Apri mazzo"
    );
    openDeckButton->setMinimumSize(300, 250);
    openDeckButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    hbox->addWidget(openDeckButton);

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