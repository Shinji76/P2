------------------------------------------------------COSTRUTTORE STANDARD-------------------------------------------------------------
Crea un oggetto con un campo dati costruito di default senza inizializzarlo
NB: se definisco un costruttore esplicitamente, il costruttore standard non esiste più, va quindi ridefinito manualmente
è good practice mettere sempre un costruttore senza argomenti perchè spesso serve

------------------------------------------------------COSTRUTTORE DI COPIA-------------------------------------------------------------
Non bisogna confonderlo con l assegnazione con cui condivide una sintassi simile

orario copia;               //costruttore di default
copia = adesso;             //assegnazione
orario copia1 = adesso;     //costruttore di copia
orario copia2(adesso);      //costruttore di copia con sintassi MIGLIORE

Il costruttore di copia è fornito dal linguaggio in versione standard, costruisco un oggetto creando una copia field by field
Nel caso dell assegnazione invece viene sostituito il valore di un campo dati già esistente con un altro, l oggetto è quindi già stato
creato.
Il costruttore di copia chiede come tipo C(const C&), con l assegnazione invece diventa C& operator = (const C&)
Molto importante il tipo riferimento C&.
-------------------------------------------------COSTRUTTORE CONVERTITORE DI TIPO--------------------------------------------------------
NB: vale SOLO per costruttore ad 1 argomento
Il costruttore prende un parametro di tipo T e costruisce un tipo C, in pratica scrivendo C(T) prendo un tipo T=>C
ad esempio:

orario s;
s = 8;

1) viene invocato il costruttore orario(int) che crea un temporaneo anonimo, quindi senza L valore
2) viene assegnato il temporaneo anonimo all oggetto s
3) viene deallocato il temporaneo

-----------------------------------------------ARGOMENTI DI DEFAULT NELLE FUNZIONI-------------------------------------------------------
Posso definire dei valori di default nelle funzioni, questo è importante per poterlo mettere nei costruttori
Devo ricordare che se assegno un valore di default ad un parametro, tutti quelli successivi devono avere un valore di default per forza
ad esempio: 

orario (int ore, int min=0, int sec);        //ERRORE: sec deve avere valore di default
orario (int ore, int min=0, int sec=0);        //OK

NB: i valori di default vanno messi al momento della scrittura della classe, se vengono messi nella chiamata del costruttore
il compilatore restituisce un errore.

-------------------------------------------------OPERATORE ESPLICITO DI CONVERSIONE-----------------------------------------------------
Voglio convertire un tipo definito da utente, ad esempio una classe, ad un altro tipo qualsiasi, che sia esso primitivo (int, double)...
o definito da utente.
Questo viene fatto attraverso la keyword operator int();
ad esempio:

class orario {
    public:
        operator int();
};

orario o(14,37);
int x = o;

Quello che succede è che viene chiamato il metodo int() su o

-------------------------------------------------------SIDE EFFECT-----------------------------------------------------------------------
class orario {
    public:
    orario UnOraPiuTardi();
    void AvanzaUnOra();
}

La differenza che ci si aspetta è che nel primo caso l oggetto di invocazione rimanga invariato, nel secondo che ci sia un side effect e
che quindi l orario passato come parametro venga cambiato 
Implementiamo i 2 metodi:

orario orario::UnOraPiuTardi () {
    orario aux;
    aux.sec = (sec+3600) % 86400;       //sec viene usato solo come R valore, non subisce modifiche
    return aux;
}

void orario::AvanzaUnOra() {
    sec = (sec+3600) % 86400;           //sec è a sinistra dell'assegnazione, viene modificato per forza
}

NB: se io voglio che AvanzaUnOra non provochi un side effect devo marcarlo con const

Un oggetto può essere dichiarato come const, questa ha 2 effetti, non posso assegnarlo, e non posso invocare su di esso un metodo che non
sia marcato come const, quindi BISOGNA ricordarsi di marcare const

-------------------------------------------------------CONST-----------------------------------------------------------------------
Il posizionamento del const cambia il suo significato:

int* const p = &x;          //il const in questo caso è riferito al puntatore, quindi non posso cambiare l'inidirizzo puntato

const int* p = &x;          //In questo caso è un puntatore ad int costante, quindi non posso cambiare il valore attraverso il puntatore
*p = 5;             //ILLEGALE
x = 5;              //LEGALE, perchè cambio il valore ma non attraverso il puntatore p

-------------------------------------------------------RIFERIMENTO CONST---------------------------------------------------------------
Il riferimento costante serve principalmente per il passaggio del parametro,

-------------------------------------------------------CAMPI STATIC---------------------------------------------------------------
La dichiarazione dei campi dati static viene fatta all interno della classe,
l inizializzazione dei campi static viene fatta SEMPRE all esterno della classe ed è SEMPRE richiesta.
I campi dati statici vengono dichiarati in una porzione di memoria chiamata "memoria statica" 
Se il campo dato dichiarato static viene usato in sola lettura, bisogna ricordarsi il const
as esempio:

static const int Sec_di_un_ora = 3600;

Va marcato const perchè non voglio che venga mai cambiato

-------------------------------------------------------ESEMPIO STATIC---------------------------------------------------------------

class C {
    int dato;
    public:
        C(int);
        static int cont;
};

int C::cont = 0;
C::C(int n) {cont++; dato = n}

int main() {
    C c1(1), c2(2);
    cout << C::cont << endl;
}

-------------------------------------------------------OVERLOADING SOMMA---------------------------------------------------------------
Senza fare overloading dell operatore dovrei definire un oggetto somma che riceve in input un orario

orario orario::Somma(orario o) const {
    orario aux;
    aux.sec = (sec + o.sec) & 86400;
    return aux;
}
int main () {
    ora = ora.Somma(Due_ore_un_quarto);
}

Per evitare di dover scrivere ora.Somma devo fare overloading dell operatore +, si usa la keywoerd "operator"

class orario {
    public:
    orario operator+(orario) const;
};

orario orario::operator+(orario o) const {
    orario aux;
    aux.sec = (sec + o.sec) & 86400;
    return aux;
}

int main () {
    ora = ora + Due_ore_un_quarto;
}

-------------------------------------------------------COSTRUTTORE DI COPIA--------------------------------------------------------------
Il costruttore di copia viene invocato in 3 casi:
1- Quando un oggetto viene dichiarato ed inizializzato con un altro oggetto della stessa classe.
ES: 
orario adesso(15,41);
orario copia = adesso;
2- Quando un oggetto viene passato come parametro ad una funzione per valore 
ES: ora = ora.Somma(Due_ore_un_quarto);
3- Quando ritorno un oggetto per valore da una funzione con return;

--------------------------------------------------MODULARIZZAZIONE DELLE CLASSI----------------------------------------------------------
Ci sono varie tecniche di modularizzazione delle classi, la prima è la relazione "Has-a" 
La relazione has-a di un oggetto avviene quando un campo dati di un certo è un tipo definito da utente, in altre parole quando un
oggetto ha come parametro un tipo non primitivo.
Ad esempio creiamo una classe telefonata che ha bisogno della classe orario.

class telefonata {
private:
    orario inizio, fine; //relazione has-a
public:
    telefonata(orario, orario, int);
    telefonata();
    orario Inizio() const;
    orario Fine() const;
    int Numero() const; 
    bool operator== (const telefonata&) const;
};

--------------------------------------------------AGGIORNARE CON LEZ MANCANTI----------------------------------------------------------


--------------------------------------------------COSTRUTTORE DI DEFAULT STANDARD-------------------------------------------------------
C() : x1(),...,xk() {
    
}
--------------------------------------------------COSTRUTTORE DI COPIA STANDARD-------------------------------------------------------
C(const C& obj) : x1(obj.x1),...,xk(obj.xk) {
    
}

