#include "HomeWidget.h"
#include <QHBoxLayout>

HomeWidget::HomeWidget(MainWindow* mainWindow, QWidget *parent)
    : mainWindow(mainWindow), QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);    //decidere se cambiare in Verticale
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPushButton* createDeckButton = new QPushButton(
        QIcon(QPixmap((":/Assets/Icons/new.svg"))),
        "Crea mazzo"
    );
    hbox->addWidget(createDeckButton);

    QPushButton* openDeckButton = new QPushButton(
        QIcon(QPixmap((":/Assets/Icons/open.svg"))),
        "Apri mazzo"
    );
    hbox->addWidget(openDeckButton);

    connect(createDeckButton, &QPushButton::clicked, this, &HomeWidget::createDeckHandler);
    connect(openDeckButton, &QPushButton::clicked, mainWindow, OpenDeck);
}

void HomeWidget::createDeckHandler() {
    ClassSelectionWidget* classSelectionWidget = new ClassSelectionWidget(this);
    classSelectionWidget->show();
}

