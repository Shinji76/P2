#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class ClassSelectionWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* gridLayout;
    QPushButton* neutralButton;
    QPushButton* hunterButton;
    QPushButton* warriorButton;
    QPushButton* thiefButton;
    QPushButton* mageButton;
    QPushButton* sorcererButton;

public:
    ClassSelectionWidget(QWidget *parent = nullptr);

private slots:
    void NeutralButtonClick();
    void HunterButtonClick();
    void WarriorButtonClick();
    void ThiefButtonClick();
    void MageButtonClick();
    void SorcererButtonClick();
};


