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

---------------------------------------------------------------------CAST---------------------------------------------------------------

Conversioni implicite "safe", quindi senza Cast, quelle ammesse sono:
    T& => T;            //NON VICEVERSA
    T[] => T*;
    T* => void*;        //void* è un tipo puntatore generico
    T => const T;       //int x = 5; const int y = x; funziona perchè la uso in sola lettura
    const NPR => NPR;   //NPR= Non Puntatore o Riferimento, mi consente di fare const int x = 5; int y = x;
    T* => const T*;     //int *p = &x; const int* q = p; Non vale il viceversa
    T => const T&;      //int x = 4; const int& r = x;

In più ci sono quelle dei tipi primitivi:

    bool => int;
    float => double => long double;
    char => short int => int => long int;
    unsigned char =>...=> unsigned long;

--------------------------------------------------------------STATIC CAST---------------------------------------------------------------

//NARROW CONVERSION
double d = 3.14;
int x = static_cast<int>(d);

//WIDE CONVERSION
char c = 'a';
int x = static_cast<int>(c);

//CONVERSIONE T* => VOID*
void* p;
p=&d;

--------------------------------------------------------------CONST CAST---------------------------------------------------------------

Const cast permette di convertire un puntatore o un riferimento ad un tipo const T ad un puntatore o riferimento a T (perdendo lattributo di const)

    const int i=5;
    int*p = const_cast<int*>(&i);

    void F(const C& x) {
        x.metodoCostante();
        const_cast<C&>(x).metodoCostante();
    }

    int j=7;
    const int*q = &j;       //OK: cast implicito

Quello che ho fatto è dichiarare un int i costante, poi dichiaro un puntatore p con const_cast che toglie il const ad i e permette attraverso il puntatore di modificare un valore const int, può essere utile ma allo stesso tempo pericoloso;

-----------------------------------------------------------REINTERPRET CAST-------------------------------------------------------------
Serve a interpretare la sequenza di bit con cui è rappresentato a basso livello un puntatore;

----------------------------------------------------------TEMPLATE----------------------------------------------------------------------

template <class T>      //in alternativa template <typename T> */
T min(T a, T b) {
    return a < b ? a : b
}

Quando vado ad istanziare il template su un tipo devo assicurarmi che il tipo su cui viene effettuata l istanziazione supporti le operazioni definite nel template, in questo caso l operazione <

--------------------------------------------------------ISTANZIAZIONE IMPLICITA--------------------------------------------------------------------

L istanziazione viene fatta con l istanziazione IMPLICITA:
k = min(i, j);
t = min(r, s);

Nell istanziazione implicita il tipo di ritorno non viene mai specificato. Quello che succede è che il compilatore istanzia il template con il tipo dei parametri, esegue l operazione (in questo caso min(i, j);) e se i parametri dell operazione hanno lo stesso tipo l operazione viene eseguita e poi viene assegnata alla variabile (in questo caso k), il tipo di k non deve per forza essere lo stesso di i e j, deve però essere disponibile una conversione di tipo, o standard o definita da utente

I parametri di un template possono essere:
-PARAMETRI DI TIPO: si possono istanziare con un tipo qualsiasi (molto più diffusi).
-PARAMETRI VALRORE di qualche tipo: si possono istanziare con un valore costante del tipo indicato.

Il template non viene MAI compilato dal compilatore, viene compilata solo l istanziazione del template
Per la deduzione degli argomenti del template l algoritmo esamina tutti i parametri passati al template da sx verso dx, tutti in modo univoco devono avere lo stesso tipo, altrimenti il codice non compila.
ESEMPIO:
int main() {
    int i; double e, d;
    e = min(d, i);
}
Guarda il tipo di d, poi di i essendo un double e un int i tipi sono discordi e il codice non compila.
In questo algoritmo ci sono 4 eccezioni:
1- Conversione da lvalue a rvalue (T& a T)
2- Da array a puntatore (T[] a T*)
3- Conversione di qualificazione costante (T a constT)
4- Conversione da rvalue a riferimento costante (t a const T&)

--------------------------------------------------------ISTANZIAZIONE ESPLICITA--------------------------------------------------------------------

L istanziazione ESPLICITA:
k = min<int>(i, j);
t = min<orario>(r, s);

dove i tipi <int> e <orario> vengono esplicitati.

---------------------------------------------------COMPILAZIONE PER INCLUSIONE----------------------------------------------------------
Non esiste il concetto di compilazione separata per i template, comporta 2 problemi:
1- Information hiding
2- Istanze multiple di template

Se per la prima non ci sono soluzioni perchè la definizione del template deve essere visibile all utilizzatore del template, per la seconda basta ricorrere alla dichiarazione esplicita di template per evitare un "bloat"

DICHIARAZIONE ESPLICITA:

template<class Tipo>
Tipo min(Tipo a, Tipo b) {
    return a < b ? a : b;
}

dichiaro esplicitamente:
template int min(int, int);

e al momento della compilazione aggiungo il flag " -fno-implicit-templates " per evitare che il compilatore istanzi il template implicitamente e multiple volte.

Il template va messo in un file header, nonostante vada dichiarato e definito nell header è good practice separare la dichiarazione di template e la sua definizione.

--------------------------------------------------------------TEMPLATE DRAWBACKS-------------------------------------------------------------------

1- CODE BLOAT: bisogna stare attenti alle istanziazioni multiple dei template che potrebbero far "esplodere" il codice
2- DEBUGGING: l uso di template rende difficile l operazione di debugging, si potrebbero avere bug nei template o addirittura solo in specifiche istanziazioni dei template, quindi la programmazione generica con template è più complessa.
3-NESTING: Fare il nesting di template all interno di altri template è difficoltoso
4-INFORMATION HIDING: non è possibile fare l information hiding
5-BUILD: essendo contenuto nell header ogni minimo cambio del template richiede il rebuilding di tutti i file

--------------------------------------------------------------TEMPLATE DI CLASSE-------------------------------------------------------------------

Se io volessi usare sia code di interi che code di stringhe dovrei scrivere 2 definizioni distinte della classe e con 2 nomi diversi, per evitare questo posso scrivere un TEMPLATE DI CLASSE che mi permetta di "risparmiare" codice. 

template <class T>
class queue {
public:
    Queue();
    ~Queue();
    bool empty() const;
    void add(const T&);
    T remove();
private:
}

Una definizione di classe può essere premessa dal template class T
Il parametro T può essere usato ovunque all'interno della classe, campi dati, funzioni, classi annidate ecc...

Per istanziare un template di classe BISOGNA fare un istanziazione ESPLICITA.
Ad esempio:
Queue <int> qi;
Queue <bolletta> qb;
Queue <string> qs;

Posso definire dei valori di default per i template. ESEMPIO:

template <class Tipo = int, unsigned int size = 1024>
class Buffer {

};

Buffer<> ib;                    //istanzia un Buffer con i valori di default <int, 1024>
Buffer <string> sb;             //istanzia un Buffer con il tipo definito e la size di default <string, 1024>
Buffer <string, 500> sbs;       //istanzia un Buffer con sia tipo e size definita da utente <string, 500>

template <class T>
class QueueItem {
public:
    QueueItem(const T&);
    T info;
    QueueItem* next;
};

template <class T>
class Queue {
public:
    Queue();
    ~Queue();
    bool empty() const;
    void add(const T&);
    T remove();
private:
    QueueItem<T>* primo;        //NB non metto QueueItem ma QueueItem<T>
    QueueItem<T>* ultimo;
};

Nella dichiarazione o definizione di template possono comparire sia nomi di istanze sia no

NB: il compilatore genera un istanza di template solo quando streattamente necessario, ad esempio se il template da istanziare restituisce un puntatore, non mi serve l istanza intera per controllare la correttezza e quindi il compilatore non istanzia il template.

--------------------------------------------------------------METODI DI TEMPLATE-------------------------------------------------------------------

In un template di classe è possibile di definire metodi inline, NON è consigliato, ma si può fare.
La definizione consigliata per i metodi è quella esterna

template <class T>
class Queue {
    ...
public:
    Queue();
    ...
}

Queue() {

}