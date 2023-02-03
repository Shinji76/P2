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
using std::list;
using std::vector;

class SIM {
private:
    unsigned int tempoTelefonateMese;
    unsigned int trafficoDatiMese;
    static double costoDati;
    static double costoTelefonate;
public:
   virtual double costoMeseCorrente() const = 0;
    double getCostoDati() const {return costoDati;}
    double getCostoTelefonate() const {return costoTelefonate;}
    unsigned int getTempo() const { return tempoTelefonateMese;}
    unsigned int getTraffico() const { return trafficoDatiMese;}
};

double SIM::costoTelefonate = 0.03;
double SIM::costoDati = 0.04;

class Tel : public SIM {
private:
    double costoBaseTel;
public:
    double getCostoBaseTel() const {return costoBaseTel;}
    double costoMeseCorrente() const override {
        return costoBaseTel + getTraffico() * getCostoDati();
    }
};

class Dati: public SIM {
private:
    static double costoBaseDati;
public:
    double costoMeseCorrente() const override {
        return costoBaseDati + getTempo() * getCostoTelefonate();
    }
};
double Dati::costoBaseDati = 13.99;

class PAO {
private:
    list<const SIM*> l;
public:
    vector<Dati> Fun1(double x) {
        vector<Dati> aux;
        for(auto cit = l.begin(); cit != l.end(); cit++) {
            if(dynamic_cast<const Dati*>(*cit) && (*cit)->getTraffico() >= x) {
                aux.push_back(*(const_cast<Dati*>(static_cast<const Dati*>(*cit))));
            }
        }
        return aux;
    }

    list<Tel*> Fun2() {
        list<Tel*> aux;
        for(auto cit = l.begin(); cit != l.end(); cit++) {
            auto *ptr = dynamic_cast<const Tel*>(*cit);
            if(ptr && ptr->costoMeseCorrente() > 2 * ptr->getCostoBaseTel())
                aux.push_back(const_cast<Tel*>(ptr));
        }
        return aux;
    }
};