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
    void classEmitter(AbstractCard::Classe classe);

public slots:
    void hunterClick();
    void warriorClick();
    void thiefClick();
    void mageClick();
    void sorcererClick();

};


#endif //CLASS_SELECTION_WIDGET_H