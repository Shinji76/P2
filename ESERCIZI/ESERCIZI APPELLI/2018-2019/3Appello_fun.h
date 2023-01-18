#ifndef APPELLO_FUN_H
#define APPELLO_FUN_H

#include <iostream>

class QSize {
private:
    unsigned int size;
public:
    virtual ~QSize() {}
    unsigned int getSize() const {return size;}
};

class QWidget {
private:
    QSize dimension;
public:
    virtual ~QWidget() {}
    virtual QSize sizeHint() const {}
    virtual QWidget* clone() const {}
};

class QAbstractButton : public QWidget {
public:
    QWidget* clone() const override {}
};

    class QCheckBox : public QAbstractButton {
    public:
        QSize sizeHint() const override {} 
    };

    class QPushButton : public QAbstractButton {
    public:
        QSize sizeHint() const override {} 
    };


class QAbstractSlider : public QWidget {
public:
    QWidget* clone() const override {}
};

    class QScrollBar : public QAbstractSlider {
    public:
        QSize sizeHint() const override {}
    };

    class QSlider : public QAbstractSlider {
    public:
        QSize sizeHint() const override {}
    };

#endif