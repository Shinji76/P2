/*
Esercizio Modellazione (NB: Per comodità di correzione, definire tutti i metodi inline) 
Si consideri il seguente modello:

Il provider Wireless Internet (WI) offre abbonamenti Internet con tariffa a soglia di tempo di connessione oppure a soglia di traffico di connessione.
(A) Definire una classe Abbonato i cui oggetti rappresentano un abbonato a WI.
	Ogni Abbonato è caratterizzato dal traffico (in MB) effettuato nel mese corrente e dal tempo di connessione (in ore) nel mese corrente.
	Per tutti gli abbonati il costo mensile base è fissato in 15€.
	Inoltre per tutti gli abbonati è fissato un extra-costo C = 5 € che viene usato per il calcolo del costo eccedente di traffico/tempo rispetto ad una soglia (si veda la descrizione delle successive classi della gerarchia).
	La classe Abbonato dichiara un metodo virtuale puro double costoMeseCorrente() che prevede il seguente contratto:
	una invocazione a.costoMeseCorrente() ritorna il costo attualmente da pagare per il mese corrente dall'abbonato a.

(B) Definire una classe AbbonatoTraffico derivata da Abbonato i cui oggetti rappresentano un abbonato a WI con tariffa mensile a soglia di traffico di connessione.
	Ogni AbbonatoTraffico è caratterizzato da una propria soglia di traffico mensile (in GB = 1024 MB) di connessione oltre la quale scatta un extra costo.
	La classe AbbonatoTraffico implementa quindi costoMeseCorrente() nel seguente modo:
	in una invocazione a.costoMeseCorrente(), se il traffico nel mese corrente effettuato dall'abbonato a è minore o uguale dalla soglia di traffico mensile per a allora ritorna il costo mensile base: altrimenti il traffico eccedente la soglia di traffico mensile comporta un ulteriore costo pari a C € per GB da aggiungersi al costo mensile base.

(C) Definire una classe AbbonatoTempo derivata da Abbonato i cui oggetti rappresentano un abbonato a WI con tariffa mensile a soglia di tempo di connessione.
	Ogni AbbonatoTempo è caratterizzato da una propria soglia di tempo mensile (in ore) di connessione oltre la quale scatta un extra costo.
	La classe AbbonatoTempo implementa quindi costoMeseCorrente() nel seguente modo:
	In una invocazione a.costoMeseCorrente() se il tempo da connessione nel mese corrente dell'abbonato a è minore o uguale alla soglia di tempo mensile per a allora ritorna il costo mensile base: altrimenti il tempo eccedente la soglia di tempo mensile comporta un ulteriore costo pari a C € all'ora da aggiungersi al costo mensile base.

(D) Definire una classe FilialeWI i cui oggetti rappresentano l'insieme di abbonati ad una filiale del provider WI.
	Una FilialeWI è inoltre caratterizzata dal numero massimo di abbonati che la filiale può accettare (per garantire una connessione di qualità). Devono essere disponibili nella classe FilialeWI le seguenti funzionalità: 
		• Un metodo void aggiungiAbbonato(cosnt Abbonato&) con il seguente comportamento: una invocazione f.aggiungiAbbonato(a) aggiunge l'abbonato a all'insieme degli abbonati alla filiale f se f non ha già raggiunto il numero massimo di abbonati: altrimenti, a non viene aggiunto tra gli abbonati di f e viene sollevata una eccezione Exc(M) dove Exc è una classe di eccezioni da definire all'uopo e M è il numero massimo di abbonati della filiale f.
		• Un metodo list<const Abbonato*> abbonatiOltreSoglia() con il seguente comportamento: una invocazione f.abbonatiOltreSoglia() ritorna la lista di tutti gli abbonati che hanno un costo attualmente da pagare per il mese corrente superiore a 50€ e degli abbonati con tariffazione mensile a soglia di tempo che hanno correntemente ecceduto la loro soglia di tempo.
*/

class Abbonato {
public:
	
};

class AbbonatoTraffico : public Abbonato {
public:

};

class AbbonatoTempo : public Abbonato {
public:

};

class FilialeWI {
public:

};