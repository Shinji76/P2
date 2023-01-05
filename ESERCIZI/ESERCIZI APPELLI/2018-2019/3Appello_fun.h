#ifndef APPELLO_FUN_H
#define APPELLO_FUN_H

#include <iostream>

class QSize {
private:
    unsigned int size;
public:
    unsigned int getSize() const {return size;}
};

class QWidget {
private:
    QSize dimension;
public:
    virtual ~QWidget() {}
    virtual QSize sizeHint() const {}
    virtual QWidget* clone() {}
};

class QAbstractButton : public QWidget {
public:
    virtual ~QAbstractButton() {}
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
    virtual ~QAbstractSlider() {}
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