#ifndef CLASS_SELECTION_WIDGET_H
#define CLASS_SELECTION_WIDGET_H

#include "Cards/AbstractCard.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class ClassSelectionWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* gridLayout;
    QPushButton* hunter_button;
    QPushButton* warrior_button;
    QPushButton* thief_button;
    QPushButton* mage_button;
    QPushButton* sorcerer_button;
    AbstractCard::Classe classe;

public:
    ClassSelectionWidget(QWidget *parent = nullptr);

signals:
    void HunterButtonClick();
    void WarriorButtonClick();
    void ThiefButtonClick();
    void MageButtonClick();
    void SorcererButtonClick();

public slots:
    void SetHunter();
    void SetWarrior();
    void SetThief();
    void SetMage();
    void SetSorcerer();

};


#endif //CLASS_SELECTION_WIDGET_H