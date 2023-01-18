
/*
Si assumano le seguenti specifiche riguardanti la libreria Qt.

– Un oggetto della classe QString rappresenta una stringa di caratteri Unicode.
La classe QString fornisce un costruttore QString(const char*) con il seguente comportamento: QString(str) costruisce una QString inizializzata con la stringa ASCII str.

– La classe QPaintDevice è la classe base di tutti gli oggetti che possono essere “dipinti” sullo schermo.
	• La classe QPaintDevice è polimorfa.
	• La classe QPaintDevice rende disponibile un metodo int height() const con il seguente comportamento: pd.height() ritorna l’altezza in pixel del QPaintDevice pd.
	É inoltre disponibile un metodo int width() const con analogo comportamento per la larghezza.

– QWidget è una sottoclasse di QPaintDevice i cui oggetti rappresentano delle componenti di una interfaccia grafica Qt.
	• La classe QWidget rende disponibile un metodo bool hasFocus() const con il seguente comportamento: w.hasFocus() ritorna true quando la componente w detiene il keyboard focus.
	• La classe QWidget rende disponibile un metodo void clearFocus() con il seguente comportamento: w.clearFocus() toglie il keyboard focus alla QWidget w.

– QAbstractButton è derivata direttamente da QWidget ed è la classe base astratta dei widget pulsante.
	• La classe QAbstractButton rende disponibile un metodo void setText(const QString&) con il seguente comportamento: b.setText(s) setta l’etichetta testuale del QAbstractButton b alla stringa s. 

Definire una funzione 
vector<QWidget> fun(const vector<QPaintDevice*>&) con il seguente comportamento, in ogni invocazione fun(v):

1. Per ogni puntatore p contenuto nel vector v:
	– se p punta ad un oggetto che è un QWidget con altezza o larghezza > a 50 pixel allora lancia una eccezione di tipo QString che rappresenta la stringa “TooBig”;

	– se p punta ad un oggetto obj che è un QWidget avente sia l’altezza che la larghezza ≤ a 50 pixel e che detiene il keyboard focus allora toglie il keyboard focus a obj;

	– se p punta ad un oggetto obj che è un QAbstractButton allora setta l’etichetta testuale di obj alla stringa “Pulsante”.

2. L’invocazione fun(v) deve ritornare un vector contenente tutti e soli gli oggetti puntati da un puntatore p contenuti nel vector v che puntano ad un QWidget che non è un QAbstractButton.
*/

#include <vector>
#include <string>
using std::vector;

class QString {
private:
	std::string str;
public:
	QString(const std::string& qs) : str(qs) {}
};

class QPaintDevice {
public:
	int height() const {}
	int width() const {}
	virtual ~QPaintDevice() {}
};

class QWidget : public QPaintDevice {
public:
	bool hasFocus() const {}
	void clearFocus() {}
};

class QAbstractButton : public QWidget {
public:
	void setText(const std::string&) {}
};

vector<QWidget> fun(const vector<QPaintDevice*>& v) {
	vector<QWidget> aux;
	for(auto cit = v.begin(); cit != v.end(); cit++) {
		auto *p = *cit;
		if(dynamic_cast<QWidget*>(p)->height() > 50 || dynamic_cast<QWidget*>(p)->width() > 50)
			throw QString("TooBig");
		if(dynamic_cast<QWidget*>(p)->height() < 50 && static_cast<QWidget*>(p)->width() < 50 && static_cast<QWidget*>(p)->hasFocus())
			static_cast<QWidget*>(p)->clearFocus();
		if(dynamic_cast<QAbstractButton*>(p))
			static_cast<QAbstractButton*>(p)->setText("Pulsante");
		if(dynamic_cast<QWidget*>(p) && !dynamic_cast<QAbstractButton*>(p))
			aux.push_back(*static_cast<QWidget*>(p));
	}
	return aux;
}

vector<QWidget> fun(vector< const QPaintDevice*>& v) {
	vector<QWidget> aux;
	for(auto cit = v.begin(); cit != v.end(); cit++) {
		auto *p = *cit;
		if(dynamic_cast<const QWidget*>(p)->height() > 50 || dynamic_cast<const QWidget*>(p)->width() > 50)
			throw QString("TooBig");
		if(dynamic_cast<const QWidget*>(p)->height() < 50 && static_cast<const QWidget*>(p)->width() < 50 && static_cast<const QWidget*>(p)->hasFocus())
			const_cast<QWidget*>(static_cast<const QWidget*>(p))->clearFocus();
		if(dynamic_cast<const QAbstractButton*>(p))
			const_cast<QAbstractButton*>(static_cast<const QAbstractButton*>(p))->setText("Pulsante");
			static_cast<QAbstractButton*> (const_cast<QPaintDevice*>(p));
		if(dynamic_cast<const QWidget*>(p) && !dynamic_cast<const QAbstractButton*>(p))
			aux.push_back(*(const_cast<QWidget*>(static_cast<const QWidget*>(p))));
	}					
	return aux;
}

vector<QWidget> fun(const vector<const QPaintDevice*>& v) {
	vector<QWidget> w;
	for(auto cit = v.begin(); cit != v.end(); ++cit) {
		QWidget* qw = dynamic_cast<QWidget*>(const_cast<QPaintDevice*>(*cit) );
		QAbstractButton* qab = dynamic_cast<QAbstractButton*>(const_cast<QPaintDevice*>(*cit));
		if(qw) {
	  		if(qw->height() > 50) throw QString("TooBig");
			// qw->height() <= 50
			if(qw->hasFocus()) qw->clearFocus();
			if(!qab) w.push_back(*qw);
		}
		if(qab) qab->setText("Pulsante");
  	}
 	return w;
}