#include "BoxWidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

BoxWidget::BoxWidget(QWidget *parent) {
    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(card->getPath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/Assets/images/not_found.svg");
    }

    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    vbox->addWidget(image, 0, Qt::AlignHCenter);

    remove_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")), "");
    remove_button->setObjectName(QString::number(card->getID()) + '-');
    remove_button->setEnabled(false);
    hbox->addWidget(remove_button);

    add_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")), "");
    add_button->setObjectName(QString::number(card->getID()) + '+');
    hbox->addWidget(add_button);

    connect(this, SIGNAL(addEmitter(AbstractCard*)), parentWidget()->parentWidget(), SLOT(addCard(AbstractCard*)));
    connect(this, SIGNAL(removeEmitter(AbstractCard*)), parentWidget()->parentWidget(), SLOT(removeCard(AbstractCard*)));
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

void BoxWidget::setCard(const AbstractCard& setter) {
    card = &setter;
}
