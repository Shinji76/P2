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
}

void ClassSelectionWidget::HunterClick() {
    classe = AbstractCard::Classe::Cacciatore;
    emit classEmitter(classe);
}

void ClassSelectionWidget::WarriorClick() {
    classe = AbstractCard::Classe::Guerriero;
    emit classEmitter(classe);
}

void ClassSelectionWidget::ThiefClick() {
    classe = AbstractCard::Classe::Ladro;
    emit classEmitter(classe);
}

void ClassSelectionWidget::MageClick() {
    classe = AbstractCard::Classe::Mago;
    emit classEmitter(classe);
}

void ClassSelectionWidget::SorcererClick() {
    classe = AbstractCard::Classe::Stregone;
    emit classEmitter(classe);
}