#include "Box.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

void Box::visit(const Mostro& mostro) {
    add_button = nullptr;
    remove_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("box-mostro");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(mostro.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/Assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    add_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")), "");        //sistemare url
    add_button->setObjectName("add-button");
    actions->addWidget(add_button);

    remove_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")), "");   //sistemare url
    remove_button->setObjectName("remove-button");
    actions->addWidget(remove_button);

    QLabel* link = new QLabel(QString::fromStdString("<a href=\"" + mostro.getUrl() + "\">" + web_page.getName() + "</a>"));
    link->setObjectName("link");
    link->setWordWrap(false);
    link->setTextFormat(Qt::RichText);
    link->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse);
    link->setOpenExternalLinks(true);
    vbox->addWidget(link);
}

void Box::visit(const Magia& magia) {
    add_button = nullptr;
    remove_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("box-magia");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(magia.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/Assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    add_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plis.svg")), "");
    add_button->setObjectName("add-button");
    actions->addWidget(add_button);

    remove_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")), "");
    remove_button->setObjectName("delete-button");
    actions->addWidget(remove_button);

    details->addStretch();

    QLabel* availability = new QLabel(QString::number(magia.getAvailability()) + " available");
    availability->setObjectName("availability");
    details->addWidget(availability);
}

void Box::visit(const Segreto& segreto) {
    add_button = nullptr;
    remove_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("box-segreto");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(segreto.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/Assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    add_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")), "");
    add_button->setObjectName("add-button");
    actions->addWidget(add_button);

    remove_button = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")), "");
    remove_button->setObjectName("remove-button");
    actions->addWidget(remove_button);

    details->addStretch();

/*
    QLabel* availability = new QLabel(QString::number(segreto.getAvailability()) + " downloadable");
    availability->setObjectName("availability");
    details->addWidget(availability);
*/  //CAMBIARE INSERENDO VINCOLO NUMERO COPIE
}

QWidget* Box::getWidget() const {
    return widget;
}

QPushButton* Box::getAddButton() const {
    return add_button;
}

QPushButton* Box::getRemoveButton() const {
    return remove_button;
}
