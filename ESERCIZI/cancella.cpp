#include "2020-2021/2Appello_fun.h"
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;

list<QFrame*> Fun(vector<QWidget*>& v) {
    list<QFrame*> aux;
    for(auto it = v.begin(); it != v.end(); it++) {
        if(dynamic_cast<QLabel*>(*it)) {
            static_cast<QLabel*>(*it)->setWordWrap(false);
            static_cast<QFrame*>(*it)->setLineWidth(8);
        }
        if(dynamic_cast<QLCDNumber*>(*it)) {
            static_cast<QLCDNumber*>(*it)->setDigitCount(3);
        if(dynamic_cast<QFrame*>(*it) && !dynamic_cast<QSplitter*>(*it) && (*it)->heightDefault() < 10)
            aux.push_back(static_cast<QFrame*>(*it));
        }
    }
    return aux;
}