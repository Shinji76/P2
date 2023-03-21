#include "ClassSelectionWidget.h"

ClassSelectionWidget::ClassSelectionWidget(QWidget *parent) : QWidget(parent) {
	gridLayout = new QGridLayout(this);

	hunterButton = new QPushButton("Cacciatore", this);
	connect(hunterButton, &QPushButton::clicked, this, &ClassSelectionWidget::HunterButtonClick);
	gridLayout->addWidget(hunterButton, 0, 0);

	warriorButton = new QPushButton("Guerriero", this);
	connect(warriorButton, &QPushButton::clicked, this, &ClassSelectionWidget::WarriorButtonClick);
	gridLayout->addWidget(warriorButton, 0, 1);

	thiefButton = new QPushButton("Ladro", this);
	connect(thiefButton, &QPushButton::clicked, this, &ClassSelectionWidget::ThiefButtonClick);
	gridLayout->addWidget(thiefButton, 0, 2);

	mageButton = new QPushButton("Mago", this);
	connect(mageButton, &QPushButton::clicked, this, &ClassSelectionWidget::MageButtonClick);
	gridLayout->addWidget(mageButton, 1, 0);

	sorcererButton = new QPushButton("Stregone", this);
	connect(sorcererButton, &QPushButton::clicked, this, &ClassSelectionWidget::SorcererButtonClick);
	gridLayout->addWidget(sorcererButton, 1, 1);
}

void ClassSelectionWidget::HunterButtonClick()
{
}

void ClassSelectionWidget::WarriorButtonClick()
{
	// In questa funz
}

void ClassSelectionWidget::ThiefButtonClick()
{
	// In questa funzione, puoi chiamare il metodo setter e la ricerca scritti in una classe esterna.
}

void ClassSelectionWidget::MageButtonClick()
{
	// In questa funzione, puoi chiamare il metodo setter e la ricerca scritti in una classe esterna.
}

void ClassSelectionWidget::SorcererButtonClick()
{
    
}