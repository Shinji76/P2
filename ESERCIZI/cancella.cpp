#include "ESERCIZI APPELLI/2021-2022/1Appello_fun.h"
#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;

vector<QWidget> fun(const vector<const QPaintDevice*>& v) {
    vector<QWidget> aux;
    for(auto cit = v.begin(); cit != v.end(); cit++) {
        const QPaintDevice *ptr = *cit;
        if(dynamic_cast<const QWidget*>(ptr)->width() > 80)
            throw QString("TooBig");
        else if(dynamic_cast<const QWidget*>(ptr)->width() < 80 && static_cast<const QWidget*>(ptr)->hasFocus())
            static_cast<QWidget*>(const_cast<QPaintDevice*>(ptr))->clearFocus();
        if(dynamic_cast<const QAbstractButton*>(ptr))
            static_cast<QAbstractButton*>(const_cast<QPaintDevice*>(ptr))->setText("Button");
        if(!dynamic_cast<const QAbstractButton*>(ptr) && dynamic_cast<const QWidget*>(ptr)) {
            QWidget *insert = new QWidget();
            insert = static_cast<QWidget*>(const_cast<QPaintDevice*>(ptr));
            aux.push_back(*insert);
        }
    }
    return aux;
}
