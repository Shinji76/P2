#include "ClassSelectionWidget.h"

ClassSelectionWidget::ClassSelectionWidget(QWidget *parent) : QWidget(parent) {
	gridLayout = new QGridLayout(this);

	hunter_button = new QPushButton("Cacciatore", this);
	gridLayout->addWidget(hunter_button, 0, 0);

	warrior_button = new QPushButton("Guerriero", this);
	gridLayout->addWidget(warrior_button, 0, 1);

	thief_button = new QPushButton("Ladro", this);
	gridLayout->addWidget(thief_button, 0, 2);

	mage_button = new QPushButton("Mago", this);
	gridLayout->addWidget(mage_button, 1, 0);

	sorcerer_button = new QPushButton("Stregone", this);
	gridLayout->addWidget(sorcerer_button, 1, 1);

    connect(hunter_button, SIGNAL(clicked()), this, SLOT(hunterClick()));
    connect(warrior_button, SIGNAL(clicked()), this, SLOT(warriorClick()));
    connect(thief_button, SIGNAL(clicked()), this, SLOT(thiefClick()));
    connect(mage_button, SIGNAL(clicked()), this, SLOT(mageClick()));
    connect(sorcerer_button, SIGNAL(clicked()), this, SLOT(sorcererClick()));
    connect(this, SIGNAL(classEmitter(AbstractCard::Classe)), parentWidget(), SLOT(setClass(AbstractCard::Classe)));
}

void ClassSelectionWidget::hunterClick() {
    classe = AbstractCard::Classe::Cacciatore;
    emit classEmitter(classe);
}

void ClassSelectionWidget::warriorClick() {
    classe = AbstractCard::Classe::Guerriero;
    emit classEmitter(classe);
}

void ClassSelectionWidget::thiefClick() {
    classe = AbstractCard::Classe::Ladro;
    emit classEmitter(classe);
}

void ClassSelectionWidget::mageClick() {
    classe = AbstractCard::Classe::Mago;
    emit classEmitter(classe);
}

void ClassSelectionWidget::sorcererClick() {
    classe = AbstractCard::Classe::Stregone;
    emit classEmitter(classe);
}