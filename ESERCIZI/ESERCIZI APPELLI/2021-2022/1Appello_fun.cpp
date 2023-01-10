/*
Si assumano le seguenti specifiche riguardanti la libreria Qt.
(a) Un oggetto della classe QString rappresenta una stringa e fornisce un costruttore QString(const char*) con il seguente comportamento: QString(str) costruisce una QString inizializzata con l'array di char str.
(b) QPaintDevice è la classe base polimorfa di tutti gli oggetti che possono essere "dipinti". La classe QPaintDevice rende disponibile un metodo int width() const con il seguente comportamento: pd.width() ritorna la larghezza in pixel del QPaintDevice pd.
(c) Qwidget è una sottoclasse di QPaintDevice i cui oggetti rappresentano delle componenti di un' interfaccia grafica Qt. La classe Qwidget rende disponibile un metodo bool hasFocus() const con il seguente comportamento: w.hasFocus() ritorna true quando la componente w detiene il keyboard focus. Inoltre Qwidget rende disponibile un metodo void clearFocus() con il seguente comportamento: w.clearFocus toglie il keyboard focus alla Qwidget w.
(d) QAbstractButton è derivata direttamente da Qwidget ed è la classe base astratta dei widget pulsante. La classe QAbstractButton rende disponibile un metodo void setText(const QString&) con il seguente comportamento: b.setText(s) setta l'etichetta testuale del QAbstractButton b alla stringa s.

RICHIESTA:
Definire una funzione vector<Qwidget> fun(const vector<const QPaintDevice*>&) tale che in ogni invocazione fun(v):
(1) per ogni puntatore p contenuto nel vector v:
	- se p punta ad un oggetto che è un Qwidget con larghezza > 80 pixel allora lancia una eccezione di tipo QString che rappresenta la stringa -TooBig";
	- se p punta ad un oggetto obj che è un QWIdget con larghezza < 80 pixel che detiene il keyboard focus allora toglie il keyboard focus a obj
	- se p punta ad un oggetto obj che è un QAbstractButton allora setta l'etichetta testuale di obj alla stringa -Button".
(2) l'invocazione fun(v) deve ritornare un vector contenente una copia di tutti e soli i Qwidget che non sono un QAbstractButton puntati da un puntatore contenuto nel vector v. 
*/

#include <iostream>
#include <vector>
#include "1Appello_fun.h"
using std::vector;

vector<QWidget> fun(const vector<const QPaintDevice*>& v) {
	const QWidget* p;
	vector<QWidget> ret; 
	for(auto cit = v.begin(); cit!=v.end(); cit++) {
		p = dynamic_cast<const QWidget*>(*cit);
		if(p && (*cit)->width() > 80)
			throw QString("TooBig");
		if(p && (*cit)->width() < 80 && p->hasFocus())
			const_cast<QWidget*>(p)->clearFocus();
		if(p) {
			QAbstractButton* ab = dynamic_cast<QAbstractButton*>(const_cast<QWidget*>(p));
			if(ab)
				ab->setText("-Button");
			else
				ret.push_back(*p);
		}
	}
	return ret;
}

int main() {

}