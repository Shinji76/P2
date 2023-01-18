/*
Si assumano le seguenti specifiche riguardanti la libreria Qt (ATTENZIONE: non si tratta di codice da definire!).
• Qwidget è la classe base di tutte le classi Gui della libreria Qt.
    — La classe Qwidget ha il distruttore virtuale.
   
    — La classe Qwidget rende disponibile un metodo virtuale QSize sizeHint() const; con il seguente comportamento:
    w.sizeHint() ritorna un oggetto di tipo QSize che rappresenta la dimensione raccomandata per il widget w.
    È disponibile l'operatore esterno di uguaglianza bool operator==(const QSize&, const QSize&) che testa l'uguaglianza tra oggetti di QSize.
   
    — La classe Qwidget rende disponibile un metodo virtuale di clonazione Qwidget* clone() con l'usuale contratto di "costruttore di copia polimorfo": pw->clone() ritorna un puntatore polimorfo ad un nuovo oggetto Qwidget che è una copia polimorfa di *pw.
    Ogni sottoclasse di Qwidget definisce quindi il proprio overriding di clone().

• La classe QAbstractButton deriva direttamente e pubblicamente da Qwidget ed è la classe base astratta di tutti i button widgets.
    — Le classi QCheckBox e QPushButton derivano direttamente e pubblicamente da QAbstractButton.
    Le classi QCheckBox e QPushButton definiscono il proprio overriding di QWidget::sizeHint().

• La classe QAbstractSlider deriva direttamente e pubblicamente da Qwidget ed è la classe base astratta di tutti gli slider widgets.
    — Le classi QScrollBar e QSIider derivano direttamente e pubblicamente da QAbstractSlider.
    Entrambe le classi definiscono il proprio overriding di Qwidget::sizeHint().

Definire una funzione vector<QAbstractButton*> fun(list<QWidget*>&, const QSize&, vector<const Qwidget*>&) con il seguente comportamento:
in ogni invocazione fun(list, sz, w), per ogni puntatore p elemento (di tipo Qwidget*) della lista list:
    
    (a) Se p non è nullo e *p ha una dimensione raccomandata uguale a sz allora inserisce nel vector w un puntatore ad una copia di *p:

    (b) Se p non è nullo, *p non è uno slider widget e ha una dimensione raccomandata uguale a sz allora rimuove dalla lista list il puntatore p e dealloca l'oggetto *p;
    
    (c) Se p non è nullo, p non è già stato rimosso al precedente punto (b) e *p è un QCheckBox oppure un QPushButton allora rimuove dalla lista list il puntatore p e lo inserisce nel vector di QAbstractButton* che la funzione deve ritornare;

La funzione infine ritorna il vector di QAbstractButton* che è stato popolato come specificato al punto (c). 
*/
#include "3Appello_fun.h"
#include <vector>
#include <list>
using std::vector;
using std::list;

vector<QAbstractButton*> fun(list<QWidget*>& list, const int& sz, vector<const QWidget*>& w) {
    vector<QAbstractButton*> aux;
    for(auto it = list.begin(); it != list.end(); it++) {
        QWidget* p = *it;
        if(p) {
            if((p)->sizeHint() < sz) {
                w.push_back((p)->clone());
            }
            if( !(dynamic_cast<QSlider*>((p))) && (p)->sizeHint() == sz ) {
                list.erase(it);
                delete p;
                it--;
            }
            else if( dynamic_cast<QCheckBox*>(p) || dynamic_cast<QPushButton*>(p) ) {
                QAbstractButton* temp = nullptr;
                temp = static_cast<QAbstractButton*>(p);
                list.erase(it);
                aux.push_back(temp);
            }
        }
    }
    return aux;
}