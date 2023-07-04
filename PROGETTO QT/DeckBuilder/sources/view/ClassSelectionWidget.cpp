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

	connect(hunter_button, &QPushButton::clicked, this, &ClassSelectionWidget::setHunter);
	connect(warrior_button, &QPushButton::clicked, this, &ClassSelectionWidget::SetWarrior);
	connect(thief_button, &QPushButton::clicked, this, &ClassSelectionWidget::SetThief);
	connect(mage_button, &QPushButton::clicked, this, &ClassSelectionWidget::SetMage);
	connect(sorcerer_button, &QPushButton::clicked, this, &ClassSelectionWidget::SetSorcerer);
}

void ClassSelectionWidget::SetHunter() {
    classe = AbstractCard::Classe::Cacciatore;
}

void ClassSelectionWidget::SetWarrior() {
    classe = AbstractCard::Classe::Guerriero;
}

void ClassSelectionWidget::SetThief() {
    classe = AbstractCard::Classe::Ladro;
}

void ClassSelectionWidget::SetMage() {
    classe = AbstractCard::Classe::Mago;
}

void ClassSelectionWidget::SetSorcerer() {
    classe = AbstractCard::Classe::Stregone;
}