/*
Si consideri il seguente modello concernente gli specialisti ICT(Information and Communication Technology) che lavorano per la internet company Amazonia©.
(A) Definire la seguente gerarchia di classi.

1. Definire una classe base polimorfa astratta ICTstaff i cui oggetti rappresentano uno specialista ICT che lavora in Amazonia.  Ogni ICTStaff è caratterizzato da uno stipendio fisso mensile contrattato individualmente, dal titolo di laurea posseduto e dal possedere una laurea triennale o magistrale, dove il titolo di laurea è un valore del seguente tipo enumerativo: enum Laurea{ Informatica, Ingegneria, Altro};
La classe è astratta in quanto prevede i seguenti metodi virtuali puri:
    • Un metodo di “clonazione” con l’usuale contratto di “costruzione di copia polimorfa”.
    • Un metododouble salary() con il seguente contratto: p->salary() ritorna lo stipendio mensile per il mese corrente di*p.

2. Definire una classe concreta SwEngineer derivata da ICTStaff i cui oggetti rappresentano un ingegnere software che lavora in Amazonia.
Ogni SwEngineer è caratterizzato dall’occuparsi di sicurezza oppure no. La classe SwEngineer implementa i metodi virtuali puri di ICTStaff come segue:
    • Implementazione del metodo di clonazione specifica del tipoSwEngineer;
    • Per ogni puntatore p a SwEngineer, l’invocazione p->salary() ritorna lo stipendio fisso mensile di *p, aumentato di 500€ se *p si occupa di sicurezza software.

3. Definire una classe concreta HwEngineer derivata da ICTStaff i cui oggetti rappresentano un ingegnere hardware che lavora in Amazonia.
Ogni HwEngineer è caratterizzato dal numero di trasferte di lavoro effettuate nel mese corrente.
La classe HwEngineer implementa i metodi virtuali puri di ICTStaff come segue:
    • Implementazione del metodo di clonazione specifica del tipoHwEngineer;
    • Per ogni puntatore p a HwEngineer, l’invocazione p->salary() ritorna lo stipendio fisso mensile di *p, aumentato di 300€ per ogni trasferta di lavoro effettuata da *p nel mese corrente.

(B) Definire una classe Amazonia i cui oggetti rappresentano gli specialisti ICT che correntemente lavorano in Amazonia.
La classe Amazonia deve soddisfare le seguenti specifiche:

4. È definita una classe annidata SmartP i cui oggetti rappresentano un puntatore polimorfo smart a ICTStaff.
    • La classe annidata SmartP deve essere dotata di un costruttore SmartP(ICTstaff*) con il seguente comportamento:
    SmartP(q) costruisce un oggetto SmartP il cui puntatore polimorfo punta ad una copia dell’oggetto *q.
    • La classe SmartP ridefinisce costruttore di copia profonda, assegnazione profonda e distruttore profondo.
    • La classe SmartP ridefinisce gli operatori di dereferenziazione* e di accesso mediante freccia-> nell’usuale modo che permetta di usare i puntatori smart di SmartP come puntatori ordinari.

5. Un oggetto di Amazonia è caratterizzato da un contenitore di oggetti di tipo SmartP che memorizza i puntatori smart a tutti e soli gli specialisti ICT che lavorano in Amazonia.

6. La classe Amazonia rende disponibili i seguenti metodi: 
    6.1 Un metodo bool insert(SwEngineer*, unsigned int) con il seguente comportamento: una invocazione am.insert(p,k) inserisce un puntatore smart ad una copia di *p nel contenitore di am se il numero di ingegneri software di Amazonia che si occupano di sicurezza è minore di k, altrimenti non viene effettuato l’inserimento;
        Se l’inserimento viene effettuato allora si ritorna true, altrimenti false.
    6.2 Un metodo vector<HwEngineer> fire(double) con il seguente comportamento: una invocazione am.fire(s) elimina dal contenitore di am tutti gli specialisti ICT di Amazonia che hanno uno stipendio mensile maggiore di s;
    inoltre ritorna un vector di HwEngineer che contiene tutti e soli gli ingegneri hardware eliminati.
    6.3 Un metodo vector<SwEngineer*> masterInf() con il seguente comportamento: una invocazione am.masterInf() ritorna un vector di puntatori ordinari a SwEngineer contenente tutti e soli gli ingegneri software di Amazonia in possesso di una LaureaMagistrale in Informatica.
*/

