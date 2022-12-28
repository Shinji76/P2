/* 
L'operatore di telefonia mobile PAO offre ai clienti due tipologie di SIM denominate Tel e Dati con diversa tariffazione.
Le SIM PAO permettono telefonate e connessione dati. 
(A) Definire una classe SIM i cui oggetti rappresentano una SIM PAO. Ogni SIM è caratterizzata da:
	il tempo totale (in secondi) delle telefonate sinora effettuate nel mese corrente;
	il traffico dati totale (in MB) sinora effettuato nel mese corrente.
	Per tutte le SIM PAO, il costo delle telefonate è fissato in 0.03€ al secondo ed il costo del traffico dati è fissato in 0.04€ per MB. La classe SIM dichiara un metodo virtuale puro double costoMeseCorrente() che prevede il seguente contratto:
	una invocazione s.costoMeseCorrente() ritorna il costo attualmente da pagare per il mese corrente dalla SIM s.
	
(B) Definire una classe Tel derivata da SIM i cui oggetti rappresentano una SIM PAO con tariffazione Tel. 
Ogni SIM con tariffazione Tel prevede uno specifico costo base di abbonamento mensile in € (che può quindi variare per diverse SIM Tel).
La classe Tel implementa costoMeseCorrente() nel seguente modo:
	una invocazione t.costoMeseCorrente() ritorna il costo base di abbonamento mensile di t sommato al costo del traffico dati sinora effettuato da t nel mese corrente. 
	
(C) Definire una classe Dati derivata da SIM i cui oggetti rappresentano una SIM PAO con tariffazione Dati. Tutte le SIM con tariffazione Dati prevedono uno stesso costo base di abbonamento mensile di 13.99€. La classe Dati implementa costoMeseCorrente() nel seguente modo:
	una invocazione d.costoMeseCorrente() ritorna il costo base di abbonamento mensile di d sommato al costo delle telefonate sinora effettuate da d nel mese corrente.
	
(D) Definire una classe PAO i cui oggetti modellano l'insieme delle SIM gestiti da una filiale PAO e sono rappresentati da una lista di tipo std::list<const SIM*>. Devono essere disponibili nella classe PAO le seguenti funzionalità: 
	• Un metodo std::vector<Dati> fun1(double) con il seguente comportamento:
		una invocazione p.fun1(x) ritorna un vettore di oggetti Dati contenente tutti e soli i puntatori a SIM gestite dalla filiale PAO p che abbiano una tariffazione Dati e un traffico dati sinora effettuato nel mese corrente >= x MB. 
	• Un metodo std::list<Tel*>fun2() con il seguente comportamento: una invocazione p.fun3() ritorna una lista di puntatori Tel* contenente tutti e soli i puntatori a SIM gestite dalla filiale PAO p che abbiano una tariffazione Tel ed un costo attualmente da pagare per il mese corrente maggiore del doppio del loro specifico costo base di abbonamento mensile.
*/

#include <iostream>
#include <list>
#include <vector>

class SIM {
private:
	unsigned int tempoTelefonate;
	unsigned int trafficoDati;
	double const static costoTelefonate;
	double const static costoDati;
public:
	unsigned int getTrafficoDati() const {return trafficoDati;}
	unsigned int getTempoTelefonate() const {return tempoTelefonate;}
	double getCostoDati() const {return costoDati;}
	double getCostoTelefonate() const {return costoTelefonate;}
	virtual double costoMeseCorrente() const = 0;
};

double const SIM::costoTelefonate = 0.03;
double const SIM::costoDati = 0.04;

class Tel : public SIM {
private:
	double costoBaseMensile;
public:
    double geCostoBaseMensile() const {return costoBaseMensile;}
	double costoMeseCorrente() const override {
		return costoBaseMensile + getCostoDati() * getTrafficoDati();
	}
};

class Dati : public SIM {
private:
	static const double costoBaseMensile; 
public:
	double costoMeseCorrente() const override {
		return costoBaseMensile + getTempoTelefonate() * getCostoTelefonate();
	}
};

const double Dati::costoBaseMensile = 13.99;

class PAO {
private:
	std::list<const SIM*> sim;
public:
	std::vector<Dati> fun1(double x) {
		std::vector<Dati> aux;
		for(auto cit = sim.begin(); cit != sim.end(); cit++) {
			const Dati* p = dynamic_cast<const Dati*>(*cit);
			if(p && p->getTrafficoDati() > x) {
				aux.push_back(*p);
			}
		}
		return aux;
	}

	std::vector<Tel*> fun2() {
        std::vector<Tel*> v;
        for(auto cit = sim.begin(); cit != sim.end(); cit++) {
            const Tel* t = dynamic_cast<const Tel*>(*cit);
            if(t && t->costoMeseCorrente() > 2*t->geCostoBaseMensile())
                v.push_back(const_cast<Tel*>(t));
        }
        return v;
	}
};