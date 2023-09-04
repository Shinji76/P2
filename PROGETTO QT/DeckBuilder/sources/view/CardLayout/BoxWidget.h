#ifndef BOX_WIDGET_H
#define BOX_WIDGET_H

#include "../../Cards/AbstractCard.h"

#include <QObject>
#include <QWidget>
#include <QPushButton>

class BoxWidget : public QWidget {
    Q_OBJECT
private:
    const AbstractCard* card;
    QPushButton* add_button;
    QPushButton* remove_button;

public:
    BoxWidget(QWidget *parent = nullptr);
    
    QPushButton* getAddButton() const;
    QPushButton* getRemoveButton() const;
    void setCard(const AbstractCard& setter);

public slots:
    void AddClick();
    void RemoveClick();

signals:
    void addEmitter(const AbstractCard* card);
    void removeEmitter(const AbstractCard* card);
};

#endif