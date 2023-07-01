#ifndef RECAP_WIDGET_H
#define RECAP_WIDGET_H

#include <QWidget>

class RecapWidget: public QWidget {
Q_OBJECT
private:

public:
    
public slots:
    void addCard();
    void removeCard();
};

#endif //RECAP_WIDGET_H
