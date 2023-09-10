#include "BoxWidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

BoxWidget::BoxWidget(const AbstractCard* card, QWidget *parent) : QWidget(parent), card(card) {
    
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignCenter);
    setMinimumSize(200, 200);

    QString path = QString::fromStdString(card->getPath());
    QPixmap image_object(path);
    if (!image_object) {
        image_object = QPixmap(":/Assets/Icons/not_found.svg");
    }

    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaledToWidth(150, Qt::SmoothTransformation));
    image->setScaledContents(true);
    
    image->setAlignment(Qt::AlignCenter);
    vbox->addWidget(image);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    remove_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")), "");
    remove_button->setObjectName(QString::number(card->getID()) + '-');
    remove_button->setMinimumWidth(50);
    remove_button->setStyleSheet("border: 1px solid black;");
    remove_button->setEnabled(false);
    hbox->addWidget(remove_button);

    add_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")), "");
    add_button->setObjectName(QString::number(card->getID()) + '+');
    add_button->setStyleSheet("border: 1px solid black;");
    add_button->setMinimumWidth(50);
    hbox->addWidget(add_button);

    connect(add_button, SIGNAL(clicked()), this, SLOT(AddClick()));
    connect(remove_button, SIGNAL(clicked()), this, SLOT(RemoveClick()));
    connect(this, SIGNAL(addEmitter(const AbstractCard*)), parentWidget()->parentWidget()->parentWidget()->parentWidget(), SLOT(addCard(const AbstractCard*)), Qt::UniqueConnection);
    connect(this, SIGNAL(removeEmitter(const AbstractCard*)), parentWidget()->parentWidget()->parentWidget()->parentWidget(), SLOT(removeCard(const AbstractCard*)), Qt::UniqueConnection);
}


void BoxWidget::AddClick() {
    emit addEmitter(card);
}

void BoxWidget::RemoveClick() {
    emit removeEmitter(card);
}

QPushButton* BoxWidget::getRemoveButton() const {
    return remove_button;
}

QPushButton* BoxWidget::getAddButton() const {
    return add_button;
}

