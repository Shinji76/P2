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
    unsigned int dimension;
public:
    virtual ~QWidget() {}
    virtual unsigned int sizeHint() const {}
    virtual QWidget* clone() const {}
};

class QAbstractButton : public QWidget {
public:
    QWidget* clone() const override {}
};

    class QCheckBox : public QAbstractButton {
    public:
        unsigned int sizeHint() const override {} 
    };

    class QPushButton : public QAbstractButton {
    public:
        unsigned int sizeHint() const override {} 
    };


class QAbstractSlider : public QWidget {
public:
    QWidget* clone() const override {}
};

    class QScrollBar : public QAbstractSlider {
    public:
        unsigned int sizeHint() const override {}
    };

    class QSlider : public QAbstractSlider {
    public:
        unsigned int sizeHint() const override {}
    };

#endif