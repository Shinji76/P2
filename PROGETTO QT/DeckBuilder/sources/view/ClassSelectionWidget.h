#ifndef CLASS_SELECTION_WIDGET_H
#define CLASS_SELECTION_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class ClassSelectionWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* gridLayout;
    QPushButton* hunterButton;
    QPushButton* warriorButton;
    QPushButton* thiefButton;
    QPushButton* mageButton;
    QPushButton* sorcererButton;

public:
    ClassSelectionWidget(QWidget *parent = nullptr);

signals:
    void HunterButtonClick();
    void WarriorButtonClick();
    void ThiefButtonClick();
    void MageButtonClick();
    void SorcererButtonClick();
};


#endif //CLASS_SELECTION_WIDGET_H