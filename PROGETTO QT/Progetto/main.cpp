#include "AbstractCard.h"
#include "Magia.h"
#include "Segreto.h"
#include "Mostro.h"

int main() {

}


/*
DOMANDE:
1. Per popolare il mio JSON per la prima volta devo chiamare a mano i costruttori inserendo i dati che voglio? Questo popolamento deve essere fatto e poi cancellato, oppure lasciato in un qualche file che abbia la condizione di essere eseguito solo se non fatto in precedenza? (Forse attraverso singleton)
2. Nella gerarchia di interfaccia + classi derivate, possono esistere 2 derivate che differiscono solo per il contenuto della stringa oppure è necessario trovare un parametro non in comune fra loro perchè la gerarchia abbia senso?
3. Nel mio caso specifico, avendo un app per creare mazzi di carte di Heartstone, è sensato avere una permanenza dei dati "asincrona", ossia aggiornare il JSON solo quando finisco di creare interamente o parzialmente il mazzo, oppure è necessario un Observer che simuli un MVC per un aggiornamento just-in-time?
4. Il file JSON creato deve essere unico o possono essere molteplici? E se deve essere unico, come indico la parte specifica da cui leggere? ES: ho all'inizio del file tutto l'album di carte, e di seguito tutti i mazzi che ho salvato, come capisco dove leggere?
5. Le Enum per la classe/rarità dove vanno dichiarate? Privatamente ma statiche? Pubbliche?
6. è possibile usare std::vector in alcune parti e il vector definito da me in altre?


8. Per usare sort per implementare la funzione di ordinamento conviene creare un vettore da tenere in memoria con i nomi delle carte corrispondenti all ID oppure conviene crearsi ogni volta che usiamo il programma un vettore di appoggio.
9. è necessario creare namespace per ogni cartella o serve solo per chiarezza?
10. Ha senso definire dei getter virtuali puri e poi overridarli nella derivata?
11. Come gestisco i getter? si possono fare virtuali puri e overridare o è nonsense?
12. Perchè c'è l'interfaccia IEngine? Non basta la classe concreta direttamente?
13. Nella conversione in "Reader.cpp", le enum vanno convertite in unsigned int o stringhe?
14. Come creo dei mock?
15. In FilterVisitor come posso fare ricerca per interi? e come devo comportarmi con le enum?
16. Per aggiungere le funzioni di ordinamento devo usare un visitor?
*/