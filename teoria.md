# COSTRUTTORE STANDARD  

Crea un oggetto con un campo dati costruito di default senza inizializzarlo.

**N.B:** Se definisco un costruttore esplicitamente, il costruttore standard non esiste più, va quindi ridefinito manualmente.  

Un costruttore senza argomenti è spesso richiesto, ed è quindi good practice aggiungerlo ogni volta.  

# COSTRUTTORE DI COPIA

Non bisogna confonderlo con l'assegnazione con cui condivide una sintassi simile:

``` cpp
orario copia;				//costruttore di default
copia = adesso;				//assegnazione
orario copia1 = adesso;		//costruttore di copia
orario copia2(adesso);		//costruttore di copia con sintassi da prog. ad oggetti
```
Il costruttore di copia è fornito dal linguaggio in versione standard, costruisce un oggetto creando una copia _field by field_.  
Nel caso dell'assegnazione invece viene sostituito il valore di un campo dati già esistente con un altro, l'oggetto è quindi giù stato creato.  
Il costruttore di copia chiede come tipo **C(const C&)**, con l'assegnazione invece diventa **C& operator= (const C&)**.  
Il costruttore di copia viene invocato in 3 casi:
- Quando un oggetto viene passato come parametro ad un'altra funzione per valore.  

*Esempio:*

```cpp
orario adesso(15, 41);
orario copia = adesso;
```

- Quando un oggetto viene passato come parametro ad una funzione per valore.  

*Esempio:*

```cpp
ora = ora.Somma(Due_ore_un_quarto);
```

- Quando ritorno un oggetto per valore da una funzione con return.  

<br>

# COSTRUTTORE CONVERTITORE DI TIPO

**N.B:** Vale solo per costruttore ad 1 argomento.  
Il costruttore prende 1 parametro di tipo **T** e costruisce un tipo **C**, in pratica scrivendo **C(T)** converto un **T** in un **C**.  
Ad esempio:

``` cpp
orario s;
s = 8;
```

1. Viene invocato il costruttore **orario(int)** che crea un temporaneo anonimo, senza L value.  
2. Viene assegnato il temporaneo anonimo all'oggetto **s**.  
3. Viene deallocato il temporaneo anonimo.  

# ARGOMENTI DI DEFAULT NELLE FUNZIONI

Posso definire dei valori di default nelle funzioni e inserirlo direttamente nei costruttori.  
Devo ricordare che se assegno un valroe di default ad un parametro, tutti quelli successivi devono avere un valore di default obbligatoriamente.  
Ad esempio:

``` cpp
orario(int ore, int min=0, int sec);		//ERRORE: sec deve avere default value
orario(int ore, int min=0, int sec=0);		//OK
```

**N.B:** I valori di default vanno messi al momento della scrittura della classe, se vengono messi nella chiamata del costruttore il compilatore restituisce un errore.  

# OPERATORE ESPLICITO DI CONVERSIONE

Se voglio convertire un tipo definito da utente, ad esempio una classe, ad un altro tipo qualsiasi, sia definito da utente che primitivo (int, double ecc..) devo usare la keyword **operator int()**.  
Ad esempio:

``` cpp
class orario {
public:
	operator int();
};

orario o(14, 37);
int x = o;
```

Viene chiamato il metodo **operator int()** su o.

# SIDE EFFECT

Vediamo come un metodo può fare side effect sull'oggetto di invocazione:

``` cpp
//orario.h

class orario {
public:
	orario UnOraPiuTardi();
	void AvanzaUnOra();
}
```

La differenza che ci si aspetta è che nel primo caso l'oggetto di invocazione rimanga invariato, nel secondo che ci sia un side effect e che quindi l'orario passato come parametro venga cambiato.  

Implementiamo i 2 metodi:

``` cpp
//orario.cpp

orario orario::UnOraPiuTardi () {
    orario aux;
    aux.sec = (sec+3600) % 86400;		
    return aux;
}
//sec viene usato solo come R valore, non subisce modifiche

void orario::AvanzaUnOra() {
    sec = (sec+3600) % 86400;			
}
//sec è a sinistra dell'assegnazione, viene modificato per forza
```

**N.B:** Se io voglio evitare che AvanzaUnOra provochi un side effect posso marcarlo come *const*.  
Un oggetto può essere dichiarato come const, questo comporta 2 effetti, non posso eseguire assegnazioni ad esso, e non posso invocare su di esso un metodo che non
sia marcato come const, quindi BISOGNA ricordarsi di marcare const i metodi che non prevedono dei side effect.  

# CONST

A seconda del posto dove si va a collocare il const, il significato cambia:

``` cpp
int* const p = &x;
//il const in questo caso è riferito al puntatore, quindi non posso cambiare l'inidirizzo puntato

const int* p = &x;
//In questo caso è un puntatore ad int costante, quindi non posso cambiare il valore attraverso il puntatore

*p = 5;             //ILLEGALE
x = 5;              //LEGALE, perchè cambio il valore ma non attraverso il puntatore p
```

# CAMPI DATI STATIC

La dichiarazione dei campi static viene fatta all'interno della classe, l'inizializzazione dei campi static viene fatta **SEMPRE** all'esterno della classe ed è **SEMPRE** richiesta.  
I campi dati statici vengono dichiarati in una porzione di memoria chiamata *"memoria statica"*.  
Se il campo dati dichiarato statico viene usato in sola lettura, bisogna ricordarsi lo stesso il const.  
Ad esempio:

``` cpp
static const int Sec_di_un_ora = 3600; 
``` 

Va marcato costante perchè i secondi di un'ora sono per definizione sempre gli stessi e non voglio che sia possibile cambiarli.  
Esempio, creo un contatore statico che conta il numero di invocazioni del costruttore **C(int)**:  
``` cpp
//file.h
class C {
private:
    int dato;
public:
    C(int);
    static int cont;
};

//file.cpp
int C::cont = 0;
C::C(int n) {cont++; dato = n}

int main() {
    C c1(1), c2(2);
    cout << C::cont << endl;
}
```

# OVERLOADING OPERATORE DI SOMMA

Senza fare overloading dell'operatore dovrei definire un oggetto somma che riceve in input un orario, fa le operazioni necessarie e poi restituisce un'altro oggetto orario:

 ```cpp
orario orario::Somma(orario o) const {
    orario aux;
    aux.sec = (sec + o.sec) & 86400;
    return aux;
}
int main () {
    ora = ora.Somma(Due_ore_un_quarto);
}
```

Per evitare di dover scrivere **ora.Somma** devo fare overloading dell operatore +, si usa la keywoerd *"operator"* accompagnata dal simbolo da overloaddare.

``` cpp
//file.h
class orario {
public:
	orario operator+(orario) const;
};

//file.cpp
orario orario::operator+(orario o) const {
	orario aux;
	aux.sec = (sec + o.sec) & 86400;
	return aux;
}

int main () {
	ora = ora + Due_ore_un_quarto;
}
```

In questo modo posso fare operazioni di somma scrivendo **+** al posto di **orario.Somma()**.

# MODULARIZZAZIONE DELLE CLASSI

Ci sono varie tecniche di modularizzazione delle classi, la prima è la relazione ***Has-a***, le relazioni di tipo ***Has-a*** sono presenti quando l'istanza di una classe (oggetto), fa riferimento ad un'istanza di un'altra classe, o ad un'altra istanza della stessa classe.

# LISTA DI INIZIALIZZAZIONE DEL COSTRUTTORE

Al posto di inizializzare e assegnare manualmente i campi dati è good practice usare la ***lista di inizializzazione***  
Vediamo le differenze:  
``` cpp
telefonata::telefonata(orario i, orario f, int n) {
	inizio = i; fine = f; numero = n;
}
```
In questo caso vengono usati:  
- 2 costruttori di copia di orario, 1 costruttore di copia di int.
- 2 costruttori di default di orario, 1 costruttore di default per int.
- 2 assegnazione di orario, 1 assegnazione tra int.

``` cpp
telefonata::telefonata(orario i, orario f, int n) : inizio(i), fine(f), numero(n) { }
```
In questo caso vengono usati:  
- 2 costruttori di copia di orario, 1 costruttore di copia di int.
- 2 costruttori di copia di orario, 1 costruttore di copia di int.  

Più in generale in una classe **C** con lista ordinata di campi dati *x1,...,xk* un costruttore con lista di inizializzazione per i campi dati *xi1,...,xij* è definito tramite la seguente sintassi:

``` cpp
C(T1,...,Tn) : xi1(...), ... , xij(...) { /* codice*/ }
```

Quello che succede è che ordinatamente per ogni campo dati **Xi** viene richiamato un costruttore:
- Esplicitamente tramite una chiamata ad un costruttore **Xi(...)** definita nella lista di inizializzazione.  
- Implicitamente, se non appare nella lsita di inizializzazione, tramite una chiamata al costruttore di default **Xi()**.  

Questo concetto di lista di inizializzazione si può applicare sia per il costruttore di default che per il costruttore di copia, l'unica differenza è che nel costruttore di copia i parametri sono passati per riferimento costante **C(const C&)** e quindi la lista di inizializzazione per il costruttore di copia risulta:  

``` cpp
C(const C& obj) : x1(obj.x1), ... , xk(obj.xk) { }
```

# CAST

Ci sono delle conversioni implicite ammesse e *"sicure"* che vengono effettuate senza cast, quelle ammesse sono:

``` cpp
T& => T;			//NON VICEVERSA
T[] => T*;
T* => void*;		//void* è un tipo puntatore generico
T => const T;		//int x = 5; const int y = x; funziona perchè la uso in sola lettura
const NPR => NPR;	//NPR= Non Puntatore o Riferimento, mi consente di fare const int x = 5; int y = x;
T* => const T*;		//int *p = &x; const int* q = p; Non vale il viceversa
T => const T&;		//int x = 4; const int& r = x;
```

In più ci sono i cast dei tipi primitivi:  

``` cpp
bool => int;
float => double => long double;
char => short int => int => long int;
unsigned char =>...=> unsigned long;
```

Oltre ai cast impliciti e per i tipi primitivi esistono dei cast che possono essere esplicitati e sono di 4 tipi:  
- Static cast
- Const cast
- Reinterpret cast
- Dynamic cast

### STATIC CAST

	static_cast<T>(var)  

Serve per effettuare delle promozioni di tipo, come da int->double o contrario, non funziona nel caso di int->enum, lo static cast ha 3 sotto categorie che sono:  
- Narrow conversion

``` cpp
double d = 3.14;
int x = static_cast<int>(d);
```

- Wide conversion

```cpp
char c = 'a';
int x = static_cast<int>(c);
```

- Void conversion

``` cpp
void *p;
p = &d;
```

### CONST CAST

	const_cast<T*>(const_T*)  

Viene usato per "togliere" la keyword const dai puntatori, ovvero convertire un puntatore __const *p__ ad un puntatore **p** non costante o un riferimento ad un tipo **const T&** ad un tipo **T&**.  

``` cpp
const int i=5;
int*p = const_cast<int*>(&i);

void F(const C& x) {
	x.metodoCostante();
	const_cast<C&>(x).metodoCostante();
}

int j=7;
const int*q = &j;       //OK: cast implicito
```

Quello che succede è che dopo aver dichiarato un **i** costante, dichiaro un puntatore __*p__ con const cast che toglie l'attributo const ad i e permette attraverso il puntatore di modificare il valore costante.  

**N.B:** la variabile i resta costante, ho solo dato il permesso al puntatore p di andare a modificarlo, ma se provo a modificarlo in altri modi il compilatore restituisce errore in quanto la variabile è ancora costante.  
Questo tipo di cast viene poco utilizzato ed è abbastanza "pericoloso" da usare.

### DYNAMIC CAST

	dynamic_cast<T1>(T)

Questo cast è quello più diffuso in quanto è utilizzato per la conversione degli oggetti nella programmazione ad oggetti

### REINTERPRET CAST

Il reinterpret cast è il più pericoloso di tutti da usare, agisce a basso livello interpretando la sequenza di bit con cui è rappresentato un puntatore.  
Permette conversioni di tipo di puntatore da int* a double* o viceversa, ma non cambia il tipo dell'oggetto puntato.  
Ad esempio:

``` cpp
int x=20, *p=&x;
double*z=reinterpret_cast<double*>(y)
```

In questo caso **z** alloca e punta a 8 byte di memoria in quanto double, i primi 4 *byte* contengono l'R-value di x, mentre i secondi 4 *byte* contengono valori scoosciuti che potrebbero causare degli errori.

# TEMPLATE

Nella programmazione generica in C++ vengono usati i template di funzione e i template di classe per scrivere codice il più riutilizzabile possiblie.  
I template vanno spesso combinati con l'ereditarietà multipla e con l'overloading degli operatori.  

**N.B:** Il template non è codice compilabile, quella che viene compilata è l'istanziazione del template.  

Vediamo un esempio di definizione di template:  

``` cpp
//funzione min templetizzata
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
```

Questo template permette di calcolare il minimo fra 2 parametri con la sola istanziazione del template, senza la necessità di riscrivere interamente il codice.  
Prendiamo un main generico che dichiara 3 variabili di tipo *intero* e 3 variabili di tipo *orario*

``` cpp
int main() {
	int i, j, k;
	orario r, s, t;
}
``` 

L'istanziazione del template della funzione **min** può avvenire in 2 modi:  
- ***Istanziazione implicita***

``` cpp
k = min(i, j);
t = min(r, s);
```

- ***Istanziazione esplicita***

``` cpp
k = min<int>(i, j);
t = min<orario>(r, s);
```

I template possono accettare sia ***parametri di tipo*** che ***parametri valore*** di qualche tipo.  

I template come le funzioni possono avere dei valori di default.  
Ad esempio:

```cpp
template <class Tipo = int, usingned int size = 1024>
class Buffer {
	...	
};
```
Che produce questo risultato:

``` cpp
Buffer <> ib;				//Buffer <int, 1024> entrambi di default
Buffer <string> sb;			//Buffer <string, 1024>	secondo par di default
Buffer <string, 500> sbs;	//Buffer <string, 500> nessuno di default
```

Quando viene usata l'istanziazione implicita del template il tipo di ritorno dell'istanza del template non viene considerato nella *deduzione degli argomenti*.  

## ALGORITMO DI DEDUZIONE

L'***algoritmo di deduzione degli argomenti di template*** esamina da sinistra a destra i parametri attuali passati all'istanza di template, se i parametri attuali hanno tipo concorde, allora il programma compila e restituisce un tipo concorde ai parametri attuali, se i parametri non hanno tipo concorde il programma non compila.  
Ad esempio:

``` cpp
int main() {
	int i;
	double d, e;
	.
	.
	.
	e = min(d,i);
}
``` 

**d** è di tipo *double*, **i** è di tipo *int* e quindi NON compila.  

Nei template non esiste il concetto di compilazione separata, questo comporta 2 problemi:  
- Information hiding.
- Gestione delle istanze multiple di template.

Per l'information hiding non si può fare niente, con l'utilizzo di template non è possibile usare il principio dell'information hiding.  
Per risolvere l'istanziazione multipla di template invece basta usare la dichiarazione esplicita del template.  
Ad esempio:  

``` cpp
//template
template <class Tipo>
Tipo min(Tipo a, Tipo b) {
	return a < b ? a : b;
}

//istanza
template int min(int, int);
```

Devo inoltre ricordarmi di specificare al momento della compilazione il flag  
	
	-fno-implicit-templates  

che impedirà al compilatore di istanziare le dichiarazioni implicite di template, ed eviterà così che l'istanziazione dello stesso identico template venga effettuata più volte.  

**N.B:** Nonostante il template vada messo in un header file è good practice separare sempre la dichiarazione di template dalla sua definizione.  

# TEMPLATE DRAWBACKS

L'utilizzo di template come già detto ha il vantaggio principale di rendere il codice più generico e quindi riutilizzabile, ma ha anche dei grossi drawback che richiedono una maggiore attenzione in fase di scrittura rispetto ad altri tipi di programmazione.  

- CODE BLOATING: Avviene quando ci sono istanziazioni implicite multiple di template, si risolve come detto prima, ma se non gestita può far *"esplodere"* il programma.  

- DEBUGGING: l'uso di template rende difficile l'operazione di debugging, si potrebbero avere bug nei template o addirittura solo in specifiche istanziazioni dei template, quindi la programmazione generica con template è più complessa.  

- NESTING: Fare il nesting di template all interno di altri template è difficoltoso sia concettualmente che per il debugging.  

- INFORMATION HIDING: Non esiste l'information hiding se si utilizzano template.  

- BUILD: essendo contenuto nell header ogni minimo cambio del template richiede il rebuilding di tutti i file, per progetti di grosse dimensioni può essere una grossa perdita di tempo e in ogni caso aumenta la complessità.  

# QUEUE

Le code sono un particolare tipo di ADT (*Abstract Data Type*) dove le "entità" sono tenute in ordine e le 2 operazioni principali sono l'aggiunta di un dato alla coda, e la rimozione di un dato dalla testa.  
Vediamo un esempio di coda templetizzato: 

``` cpp
template <class T>
class Queue {
public:
	Queue();
	~Queue();
	bool empty() const;
	void add(const T&);
	T remove();
private:
	...
};
```

Nelle code si usa **SOLO** l'instaziazione esplicita del template di classe.  
La definizioni di metodi dei template avviene esternamente alla classe, quindi per il template della classe coda la definizione di due metodi *primo* e *ultimo*, avviene così:  

``` cpp
template <class T>
Queue<T>::Queue(): primo(0), ultimo(0) { }
```

I metodi di template di classe non vengono istanziati quando viene istanziata la classe, ma vengono istanziati solo quando strettamente necessario, ovvero se il programma usa quel metodo.  

# AMICIZIA NEI TEMPLATE

Un template può rilasciare l'amicizia ad un altro template, sia esso di funzione o di classe. Esistono 3 diversi tipi di amicizia che possono essere rilasciati:  

## DICHIARAZIONE DI AMICIZIA UNIVERSALE

In un template si possono definire delle classi o delle funzioni come "amiche" di altri classi o funzioni con l'attributo **friend**.  
Ad esempio:  

``` cpp
class A {
	...
	int fun();
	...
}

template<class T>
class C {
	friend int A::fun();
	friend class B;
	friend bool test();
}
```

Questi 3 esempi, la class **B**, la funzione **test()** e il metodo **A::fun()** della classe A sono tutti ***friend*** di TUTTE le istanze del template di classe **C**, questa viene detta ***Amicizia Universale*** ed è la più semplice.  
  

## DICHIARAZIONE DI AMICIZIA ASSOCIATA

Facciamo un esempio:  

``` cpp
template <class T1,... ,class Tn>
class C {
	friend class A<..., Tj, ...>;
	friend void fun<..., Tj, ...>(..);
// <..., Tj, ...> in classe A e in fun sono un sottoinsieme delle classi <class T1,... ,class Tn> del template di classe C
}
```

Questa dichiarazione di amicizia associata fa in modo che per una specifica istanziazione del template di classe **C**, dove vengono assegnati a *<class T1,... ,class Tn>* dei tipi, venga effettuata una corrispondente istanziazione di **A** rispettando i tipi di *class C*, e solo quella specifica istanziazione do **A** avrà l'attributo *friend*, stesso discorso vale anche per l'istanziazione di fun dove i parametri passati alla funzione saranno quelli corrispondenti all'istanziazione di **C**.  

In parole povere ad una specifica istanziazione del template di classe viene associata un'istanziazione della classe associata, e quella specifica istanziazione avrà l'amicizia.  
Vediamo un esempio:  

```cpp
template<class T>
class A {
	...
	int fun();
	...
};

template<class U, class V>
class B {
	...
};

template<class T1, class T2>
class C {
	friend int A<T1>::fun();
	friend class B<T2, T2>;
	friend bool test<T2, T1>(const C&);
};
```

La prima dichiarazione istanzia **fun()** istanziando **A** con T1, e solo quella precisa istanziazione è amica.  

La seconda dichiarazione dice che la class **B** è amica solo se è istanziata esattamente con **<T2, T2>**, questo perchè l'amicizia va data il meno possibile e solo quando strettamente necessario.  

La terza dichiarazione chiede 2 parametri **<T2, T1>** e verrà data l'amicizia solo a quella precisa istanziazione.  

## DICHIARAZIONE DI AMICIZIA NON ASSOCIATA

Da finire  (PAO 28-10-2022 time 47:23)
.  
.  
.  
.  
.  
.  


# LIBRERIA STL

La libreria **STL** (*Standard Template Library*) fa parte della libreria **STD**, è composta di:
- Classi di collezione (*Contenitori*)
- Template di funzione: (*Algoritmi generici*)  

# VECTOR

Il vettore è una forma di contenitore dinamico implementato nella libreria STL. È un template di classe che generalizza gli array dinamici.  

Caratteristiche principali di vector:  
- È un contenitore che supporta l'**accesso casuale** agli elementi.
- L'inserimento e rimozione in **coda** vengono effettuati in tempo "armonizzato" costante.
- Inserimento e rimozione **arbitraria** in tempo lineare ammortizzato.
- La capacità di un vector può variare dinamicamente.
- La gestione della memoria è **automatica**  

**Def:** *Tempo ammortizzato*  
Il tempo ammortizzato coincide con il tempo medio di n esecuzioni.  

**Vector** è un template di classe con due parametri di tipo ed un parmetro di default per il secondo parametro di tipo (*Allocatore*) ma non ci interessa per l'implementazione.  

``` cpp
template <class _Tp, class _Alloc = __STL_DEFAULT_ALLOCATOR(_TP)>
class vector {
	...
}
```

Ci sono 2 modi per utilizzare il **vector** della libreria, quello ereditario dal C e quello del C++.  

``` cpp
int a[10];				//array stile C
vector <int> v(10);		//costruttore ad 1 argomento stile C++
```

Per accedere agli elementi del **vector** invece si usa l'operator [] come nel C

``` cpp
int n = 5;
vector <int> v(n);
int a[n] = {2,4,5,2,-2};
for(int i=0; i<n; i++) {
	v[i] = a[i] + 1;
}
```
Oltre al costruttore di default ***vector(size_type)*** è disponibile un costruttore a 2 parametri ***vector(size_type n, const T& t)*** che permette di specificare un valore **t** da cui costruire di copia tutti gli altri elementi.  

# METODI DI VECTOR

### PUSH BACK

**void push_back(const T&):** È il principale metodo di inserimento in coda ad un vettore, il nuovo elemento inserito è creato con il costruttore di copia.  

``` cpp
int main() {
	vector <string> sv; string x;
	while(cin >> x)
		sv.push_back(x);
	cout << endl << "Abbiamo letto: " << endl;
	for(int i=0; i<sv.size; i++)
		cout << sv[i] << endl;
}
```

Ad ogni classe contenitore **C** della libreria **STL** sono associati 2 tipi di iteratore: 
- **C::iterator**
- **C::const_iterator**  

Il primo viene usato quando si necessita un accesso agli elementi del contenitore come *L-value*, mentre se basta un accesso come *R-value* è meglio usare l'iteratore costante.  

Gli iteratori sono bidirezionali, ossia funziona sia *i++* che *++i*  

Il const Iterator restituisce un tipo **const T&**  

Ricordo che gli iteratori non hanno costruttori, ma hanno dei metodi *begin()* e *end()* che fungono da tali.  

**N.B:** Un vettore marcato ***const*** ha bisogno per forza di un iteratore costante, mentre se ho un vettore non costante, accetta sia iteratori costanti che non.  

Su ogni tipo di iteratore di qualche istanza sono sempre disponibili le seguenti funzionalità:  

``` cpp
Cont<Tipo> x;
Cont<Tipo>::[const_]iterator i;

x.begin();
x.end();
*i;
i++;
++i;
i--;
--i;
```

Gli iteratori per contenitori **vector** e **deque** permettono di avanzare e retrocedere di un numero arbitrario di elementi in tempo costante.  
Sono disponibili anche gli operatori di confronto per questi iteratori.  

Tipicamente gli iteratori vengono usati per scorrere gli elementi di un contenitore.  

``` cpp
Cont<Tipo> x;
...
for(Cont<Tipo>::iterator i = x.begin(); i != x.end; i++) {
	...
}
```

Esiste un costruttore che permette di inizializzare un vettore copiando parte di un altro vettore.  

## INSERIMENTI IN VECTOR

Solitamente gli inserimenti negli array e vettori viene fatta in coda con la resize del vettore nel caso non sia abbastanza capiente, nonostante questo è possibile inserire in qualsiasi posizione dell'array.  
Esistono 3 overloading di *insert* per l'inserimento in posizioni diverse dalla coda.  
Si può inserire  

Le operazioni di insert possono essere più o meno efficienti a seconda dell'implementazione della classe **vector** usata.  


## RIMOZIONE IN VECTOR

Normalmente la rimozione viene fatta all'ultimo elemento del vettore con la funzione ***void pop_back()***  
Esiste anche un metodo per effettuare la rimozione di un elemento in una posizione arbitraria del vettore e si chiama ***erase(i,j)*** questa funzione è sconsigliata in quanto aumenta la complessità della rimozione da costante a lineare.  

## ACCESSO A TESTA E CODA

Esistono 2 metodi, **front()** e **back()** che servono per accedere a primo e ultimo elemento del contenitore, come per gli iteratori questi 2 metodi sono disponibili sia in versione "standard" che in versione **costante**.  
Se si prova ad accedere a front() o back() di un contenitore vuoto, il compilatore ritorna un ***Undefined Behavior***.  

## OPERATORE DI INDICIZZAZIONE

L'overloading dell'operatore di indicizzazione **operator []** è disponibile solamente per i contetitori ad accesso casuale come **vector** e **deque**.  

# CONTENITORE LIST

Il contenitore **list** definito nella libreria STL, è una lista doppiamente linkata, ovvia ha il link sia al next che al prev.  
Questo ha come vantaggio di permettere le operazioni di inserimento e rimozione in posizioni arbtrarie della lista in tempo costante.  
Un downside dell'utilizzo delle liste è che non è disponibile l'operatore **[]** quindi per arrivare ad una determinata posizione della lista bisogna scorrerla dall'inizio.  

# CONTENITORE BIDIREZIONALE "DEQUE"

Il contenitore **Deque** (*Double Ended QUEue*) unisce alcuni vantaggi delle liste e dei vettori:  
- Accesso indicizzato efficiente per lettura e scrittura
- Inserimento ed eliminazione agli estremi del contenitore sono efficienti come in una list  
- Riallocazione più efficiente rispetto a vector  

# CONTENITORE INSIEME



# CONTENITORI ASSOCIATIVI

I contenitori associativi differiscono da altri tipi di contenitore in quanto hanno 2 campi dati, il campo "info" e un campo **chiave**, differisce dalle *Hash Tables* perchè le chiavi venogno sempre mantenute ordinate, cosa che nelle Tabelle Hash non succede (*Unordered Map*).  

Nella libreria STL del c++ viene garantita un'efficienza/complessità media di **O(N logN)**.  

# FOR_EACH

Nella libreria STL esiste un template di **for_each** che permette sintassi molto compatte.  

``` cpp
for_each(InputIterator first, InputIterator last, UnaryFunction f)
//permette di fare:
std::for_each(v.begin(), v.end(), print);
```

# EREDITARIETÀ

La relazione logica fra un tipo nuovo che definiamo, e un tipo già definito da cui eredita è la stessa, il sottotipo ha anche lo stesso tipo di quello da cui eredita.  

La relazione si definisce come **IS-A**, ossia *Is Also*, quindi il tipo di un dato ad esempio **DataOra** è DataOra ma anche Orario.  

L'ereditarietà si rappresenta con la seguente sintassi:  

```cpp
class dataOra : public orario {...}
```

La vado poi a definire come una normale classe dichiarando i suoi campi privati e pubblici.  

```cpp
class dataOra : public orario {
private:
	int giorno;
    int mese;
    int anno;
public:
    int Giorno() const;
    int Mese() const;
    int Anno() const;
}
```

### TERMINOLOGIA PER LE CLASSI

Classe base **B** e classe derivata **D**.  

Sottoclasse **D** e superclasse **B**.  

Sottotipo **D** e supertipo **B**.  

Gli oggetti della classe derivata sono composti da una prima parte del sotto-oggetto e poi dai campi dati **propri** del nuovo oggetto.  

La relazione **is-a** introduce il ***Subtyping***, caratteristica fondamentale dell'ereditarietà.  
Il subtyping è una forma di polimorfismo di tipo in cui un tipo è in relazione con un altro tipo attraverso una relazione di sostituibilità.  

Se ho una funzione che richiede *orario* per fare qualcosa, quella funzione deve poter accettare anche una funzione con tipo *dataOra* perchè è un sottotipo.  
Ad esempio:  

Ho un oggetto **ANIMALE**, ha dei sottotipi che sono ad esempio **MAMMIFERI** e **RETTILI**, nei mammiferi possiamo trovare ad esempio le **Giraffe**, e quindi possiamo dire che una **giraffa** è un **Mammifero** e un **Animale**.  

**Giraffa -> Mammifero -> Animale**  

Possiamo quindi dire che il più basso livello (*Giraffa*) è anche i livelli precedenti (*Mammifero* e *Animale*), ma non possiamo dire che un'**animale** è anche una **giraffa**.  

Subtyping per puntatori e riferimenti:  

__D*=>B*__  
__D& => B&__  

Questi puntatori e riferimenti vengono detti polimorfi, ossia un puntatore o riferimento ad un oggetto di un tipo, può puntare o riferire anche ai sottotipi.  

Vediamo un esempio dove si va a memorizzare anche il giorno della settimana oltre a dataora.  

```cpp
enum giorno {lun, mar, mer, gio, ven, sab, dom};

class dataOraSett : public dataora {
public:
    giorno GiornoSettimana() const;
private:
    giorno giornosettimana;
}
```

Così facendo abbiamo definito una semplice gerarchia di 3 classi:  
**orario -> dataora -> dataOraSett**  

Data una classe **B**, per ogni suo sottotipo (indiretto) **D** valgono 3 conversioni implicite:  

**D => B**  
**D& => B&**  
__D* => B*__  

Grazie alla conversione implicita si può scrivere:  

```cpp
//Conversione dataora => orario

int F(orario o) {...}
dataora d;
int i = F(d);
//funziona perchè dataora è anche un orario per l'ereditarietà
```

**N.B:** Non vale il viceversa!  

```cpp
//NO: Conversione orario => dataora

int G(dataora d) {...}
orario o;
int i = G(o);       //ILLEGALE!
```

# CASI D'USO DI EREDITARIETÀ

Ci sono 4 casistiche in cui viene usata l'ereditarietà:  
- Estensione 
- Specializzazione
- Ridefinizione
- Riuso di codice (non è subtyping)

Il polimorfismo in C++ è supportato dai *puntatori*, dai *riferimenti*, ma NON dagli oggetti.  

Esempio: Sia **D** una sottoclasse di **B**  

```cpp
B b;        //base
D d;        //derivata
D* = pd = &d;
B* = pb = &b;
pb = pd;
// conversione D* => B*
```
Il puntatore **pb** è di tipo *statico*, mentre **pb** è di tipo *dinamico*.  

Quindi il tipo statico si riferisce al compilatore ed è fissato al momento della dichiarazione, il tipo dinamico in generale può variare a run-time ed è il tipo dell'oggetto a cui il puntatore punta, che per subtyping non è detto che coincida con quello statico.  

La sintassi per i riferimenti è analoga:  

```cpp
D d;
B b;
D& rd = d;
B& rb = d;      //conversione D& => B&
```

**N.B:** I campi privati della classe base, se non specificato NON sono accessibili neanche dalla classe derivata.  

Se si vuole rendere un campo dati accessibile alle classe derivate va dichiarato come ***protected***.  
Un membro **protected** non è accessibile dall'esterno.  
Ad esmepio:  

```cpp
dataora::set2k() {
    sec = 0;        //ERRORE: sec non accessibile
    giorno = 1;
    mese = 1;
    anno = 2000;
}
```

**N.B:** Nello specifico protetto significa ***accessibile mediante sottooggetto***.  
Quindi, se io ho una classe *base* **B** e una classe *derivata* **D** che eredita la parte *public* di **B**, se nella classe derivata ho un oggetto **B b;** e chiamo metodi/oggetti della classe **B** con **b.<nome_metodo>** NON funziona, mentre **d.<nome_metodo>** è il modo corretto per usare il protected perchè sto accedendo al metodo di **B** mediante il *sottooggetto* **D**.  

| CLASSE BASE | CLASSE DERIVATA CON DERIVAZIONE | | |  
|-|-|-|-|  
membro | **pubblica** | **protetta** | **privata** |
PRIVATO | *inaccessibile* | *inaccessibile* | *inaccessibile* |
PROTETTO | *protetto* | *protetto* | *privato* |
PUBBLICO | *pubblico* | *protetto* | *privato* |

**N.B:** Non bisogna abusare del *protected* per rispettare l'informatio hiding.  

```cpp
class Motore {
private:
    int numCilindri;
public:
    Motore(int nc) : numCilindri(nc) {}
    int getCilindri() const {
        return numCilindri;
    }
    void accendi const {
        cout << "Motore a " << getCilindri() << " cilindri acceso" << endl;
    }
}
```

### SOLUZIONE CON RELAZIONE HAS-A

```cpp
class Motore {
private:
    int numCilindri;
public:
    Motore(int nc) : numCilindri(nc) {}
    int getCilindri() const {
        return numCilindri;
    }
    void accendi const {
        cout << "Motore a " << getCilindri() << " cilindri acceso" << endl;
    }
}

class Auto {
private:
    Motore mot;
public:
    Auto(int nc = 4) : mot(4) {}
    void accendi const {
        mot.accendi();
        cout << "Motore a " << mot.getCilindri() << " cilindri acceso" << endl;
    }
}
```

### SOLUZIONE CON EREDITARIETÀ PRIVATA  

```cpp
class Motore {
private:
    int numCilindri;
public:
    Motore(int nc) : numCilindri(nc) {}
    int getCilindri() const {
        return numCilindri;
    }
    void accendi const {
        cout << "Motore a " << getCilindri() << " cilindri acceso" << endl;
    }
}

class Auto: private Motore {
public:
    Auto(int nc = 4) : Motore(nc) {}
    void accendi const {
        Motore::accendi();
        cout << "Motore a " << getCilindri() << " cilindri acceso" << endl;
    }
}
```

# DICHIARAZIONI DI AMICIZIA NELL'EREDITARIETÀ

Le dichiarazioni di amicizia non vengono mai ereditate di default, se ne ho bisogno devo dichiararlo esplicitamente.  

```cpp
class C {
private:
	int i;
public:
	C() : i(1) {}
	friend void print(C);
};

class D: public C {
	private:
		double z;
	public:
		D() : z(3.14) {}
};

void print(C x) {
	cout << x.i << endl;
	D d;
	cout << d.< << endl;	//ILLEGALE: "D::z is private within this context
}
```

**N.B:** Le conversioni implicite indotte dalla derivazione valgono solamente per la **derivazione pubblica** che quindi è l'unica tipologia di derivazione che supporta la relazione *"is-a"*.  
La derivazione protetta e la derivazione privata **NON** inducono alcuna conversione implicita.  

```cpp
class C {
private:
	int i;
protected:
	char c;
public:
	float f;
};

class D: private C { };		//derivazione privata
class E: protected C { };	//derivazione protetta

int main() {
	C c, *pc;
	D d, *pd;
	E e, *pe;

	c = d;			//1_ ILLEGALE
	c = e;			//2_ ILLEGALE
	pc = &d;		// ILLEGALE
	pc = &e;		// ILLEGALE
	C& rc = d;		// ILLEGALE
}
```

1_ Non ho il subtyping, **C** non è una base accessibile da **D**.  
2_ L'oggetto **e** è di tipo **E** che è un derivato protetto di **C**.  

Stesso ragionamento vale anche per i puntatori e per i riferimenti che allo stesso modo degli oggetti non *"tipano"*.  

# NAME HIDING RULE

```cpp
class B {				
    int f() const {
        cout << "B::f()\n";
        return 1;
    }
    int f(string) const {
        cout << "B::f(string)\n";
        return 2;
    }
};

class D : public B {	//n°1
    int f() const {
        cout << "D::f()\n";
        return 3;
    }
};

class E : public B {	//n°2
    void f() const {
        cout << "E::f()\n";
    }
};

class H : public B {	//n°3
public:
    int f(int) const {
        cout << "H::f()\n";
        return 4;
    }
};

int main() {
	string s;
	B b; D d; E e; H h;
	int x = d.f();	//stampa
	d.f(s);			//ILLEGALE
	x = e.f();		//ILLEGALE
	x = h.f();		//ILLEGALE
	x = h.f(1);		//stampa
}
```

***CLASSI***

Nel 1° caso, fa ridefinizione di f() con la stessa segnatura e lo stesso tipo di ritorno.  

Nel 2° caso, il tipo di ritorno è diverso (*void* rispetto a *int*) quindi non è una ridefinizione di funzione.  

Nel 3° caso, sto provando a ridefinire il nome di una funzione che non è disponibile nella base, perchè la base mette a disposizione **int f()** ma non **int f(int)**.  

***MAIN***

La prima operazione è *d.f( )*, l'oggetto di invocazione è un d, quindi il compilatore va dentro la classe **D** e cerca un match per la chiamata di funzione *d.f( )*, la trova e restituisce un int.  
Visto che dovevamo eseguire un'assegnazione *int x = d.f( )* i tipi matchano e quindi funziona.  

La seconda chiamata fa la stessa cosa ma cerca un *f(string*) dentro a **D**, non la trova e quindi restituisce un errore per la *Name Hiding Rule*.  

La terza chiamata cerca un match di *f( )* dentro **E**, la trova ed esegue la chiamata, ma *e.f( )* ha come tipo di ritorno *void* che non matcha con il tip *int* di x, restituisce un errore di tipo.  

La quarta chiamata cerca un match di *f( )* dentro ad **H**, non lo trova e restituisce un errore.  

La quinta chiamata a differenza della precedente prova un match fra la chiamata *h.f(1)* e quello che chiede la classe **H** quindi funziona.  


L'esempio appena visto mette in luce quale sia il problema della name hiding rule, ossia il compilatore alla chiamata di una funzione controlla solo all'interno della classe a cui riferisce e non controlla le classi da cui eredita.  
Se si volesse usare la *f( )* definita all'interno di **C** per un oggetto di tipo **D** ad esempio, dovremmo specificarlo con **C::f( )**.  

# RAPPRESENTAZIONE OGGETTI DERIVATI

Per costruire, distruggere e eseguire assegnazioni nelle classi derivata è necessario sapere come vengono rappresentati gli oggetti delle classi derivate.  
Nello specifico per un oggetto di tipo **D** derivato da un tipo **B**, viene lasciato dello spazio per il tipo di oggetto **B** e poi vengono allocati i campi dati della derivata.  
Ad esempio:  
Nell'esempio di classe *orario* la derivata è *dataOra*, per costruire un oggetto *dataOra* viene costruito prima il sottooggetto di tipo *orario*, e poi vengono costruiti i campi dati *giorno*, *mese*, *anno*.  

# COSTRUTTORI CLASSI DERIVATE

L'esecuzione di un costruttore di una classe derivata **D**, avviene nel seguente modo:  

- Viene invocato un costruttore della classe base **B** o esplicitamente, o implicitamente quello di default. 

- Viene eseguito il costruttore "proprio" di **D**, e vengono quindi costruiti i campi dati di **D**. 

- Viene eseguito il corpo del costruttore.  

# COSTRUTTORE STANDARD DI CLASSI DERIVATE

Se nella classe **D** viene omesso un costruttore, allora viene reso disponibile il costruttore di default standard di **D**.  
Quello che fa è:
- RIchiama il costruttore di default di **B**.
- Si comporta come il costruttore di default standard di **D**, ossi richiama i costruttori di default per tutti i campi di **D**.  

# DISTRUTTORE DI CLASSI DERIVATE

```cpp
class Z {
public:
    Z() { cout << "Z0 ";}
    Z(double d) { cout << "Z1 ";}
};

class C {
private:
    int x;
    Z w;
public:
    C() : w(6.28), x(8) {cout << x << " C0";}   //costruttore C default
    C(int z) : x(z) {cout << x << " C1";}       //costruttore C interi
};

class D : public C {
private:
    int y;
    Z z;
public:
    D() : y(0) {cout << "D0 ";}
    D(int a) : y(a), z(3.14), C(a) {cout << "D1 ";}
};

int main() {
    D d; cout << "UNO\n";
    D e(4); cout << "DUE\n";    
}

//stampa:
//Z1 8 C0 Z0 D0 UNO
//Z0 4 C1 Z1 D1 DUE
```

Nella prima chiamata per costruire un oggetto **D**, viene chiamato il costruttore di default per **D**, devo prima costruire il sottooggetto **C**, non essendo specificato un costruttore per **C** all'interno di **D( )** viene invocato il costruttore di default per **C**.  
Il costruttore di **C** richiede un oggetto **Z** come primo parametro.  
Si va quindi in **Z** e viene invocato il costruttore **Z(double d) { }**.  
Il corpo del costruttore di **Z** stampa ***Z1***.  
Poi il corpo del costruttore di **C** stampa il valore di x, che è ***8*** seguito da ***C0*** e finisce la chiamata per costruire il sottooggetto di **D**.  
A questo punto devono essere costruiti i campi dati di **D** e viene invocato il costruttore di default per **Z** che stampa ***Z0***.  
Si esce dal costruttore **D( )** stampando ***D0*** e infine ***"UNO\n"***.  

Per la seconda chiamata viene invocato il costruttore **D(int a) { }**.  
Devo costruire il sottoggetto **C** con il costruttore **C(int z) { }** in quanto specificato.  
All'interno di **C** vengono costruiti i campi dati, per **Z** viene invocato il costruttore di default che stampa ***Z0***.  
Viene quindi stampato il valore di *x* che è ***4*** e poi ***C1***.  
Viene invocato il costruttore **Z(double d) { }** che stampa ***Z1***.  
Viene eseguito il corpo del costruttore **D(int a) { }** che stampa ***D1*** e infine ***DUE***.  

# COSTRUTTORE DI COPIA NELLE CLASSI DERIVATE

```cpp
class Z {
public:
    Z() {cout << "Z0 ";}
    Z(const Z& x) { cout << "Zc ";}
};

class C {
private:
    Z w;
public:
    C() {cout << " C0 ";}   //costruttore C default
    C(const C& x) : w(x.w) {cout << "Cc ";}       //costruttore C interi
};

class D : public C {
private:
    Z z;
public:
    D() {cout << "D0 ";}
};

int main() {
    D d; cout << "UNO\n";
    D e = d; cout << "DUE\n";    
}

//stampa:
//Z0 C0 Z0 D0 UNO
//Zc Cc Zc DUE
```

Per quanto riguarda il primo oggetto il procedimento è uguale a quello visto per l'esercizio precedente, devo costruire un'oggetto **D**, costruisco prima i campi dati del sottooggetto **C**.  
Ho bisogno di creare un campo dati **Z** di default, nel farlo stampo ***Z0***, poi uso il costruttore **C( )** che stampa ***C0***, ritorna in **D** e deve costruire il campo dati che è di nuovo **Z** quindi stampo ***Z0*** e il corpo del costruttore **D( )** che stampa ***D0***, seguito da ***UNO***.  

Per il primo oggetto devo costruire un **D** copiandolo da un altro oggetto di tipo **D**, per farlo vado nella classe **D** che utilizza il costruttore di copia in versione standard, questa richiedere di costruire di copia il sottooggetto di tipo **C**.  
Per costruire di copia l'oggetto di **C** che è di tipo **Z** uso il costruttore di copia di **Z** che stampa ***Zc***.  
Uso quel campo dati per il comando **w(x.w)** e stampo ***Cc***.  
A questo punto devo costruire di copia il campo dati di **D**, che esegue quindi un'altra chiamata al costruttore di copia di **Z** e stampa ***Zc***.  
Concludo stampando ***DUE***.  

Questo è il ragionamento che segue il costruttore di copia in versione standard, se il costruttore di copia viene ridefinito il procedimento cambia.  

**N.B:** Quando ridefinisco il costruttore di copia, se non inserisco la **lista di inizializzazione** nella ridefinizione, le chiamate per la costruzione del sottooggetto e dei campi dati degli oggetti verrano eseguite di **DEFAULT** e non di **COPIA** e questo non va bene.  

# ASSEGNAZIONE PER CLASSI DERIVATE

Quando si vuole eseguire un'assegnazione di un oggetto di una classe **D** derivata da una classe **B**, bisogna stare molto attenti a come si ridefinisce l'operator=, il rischio è che non vengano assegnati correttamente i campi dati del sottooggetto.  

Per far si che l'operatore di assegnazione faccia quello che ci si aspetti, ossia che funzioni come nella sua versione standard, è necessario gestire i campi dati del sottooggetto, supponiamo di avere una classe base **B**, e una classe derivata **D**, quello che succede è il seguente:

```cpp
class B {
private:
    int x;
public:
    B& operator=(const B& a) {
        x = a.x;
    }
};

class D : public B {
private:
    int z;
public:
    D& operator=(const D& x) {
        this->B::operator=(x);
        z = x.z;
    }
}
```

# DISTRUTTORE STANDARD NELLE CLASSI DERIVATE

Analogamente a quanto succede con il distruttore standard, il distruttore per oggetti di classi derivate distrugge i campi in ordine inverso rispetto a quello di dichiarazione.  
Avendo il sottooggetto in prima poisizione al momento della dichiarazione, quando viene chiamato il distruttore prima vengono distrutti i campi dati della derivata e poi viene distrutto il sottooggetto.  
L'ordine per il distruttore è quindi il seguente:  
- Eseguo il corpo del distruttore della derivata **D** (se presente).  
- Distruggo i campi dati dell'oggetto derivato **D**.
- Eseguo il corpo del distruttore del sottooggetto della classe base **B** (se presente).
- Distruggo i campi dati del sottooggetto di classe base **B**.  

**N.B:** Come per le classi normali senza derivazioni, se non ci sono puntatori nella classe derivata, tipicamente NON serve ridefinire il distruttore, e va bene quello in versione standard.  

# LATE BINDING

Se ho bisogno di un metodo che indifferentemente dal tipo dell'oggetto chiamante faccia quello che ci si aspetta ho bisogno di utilizzare il alte binding.  
Se ad esempio volessimo usare un metodo **stampaInfo()** che funzioni sia per **orario** che per **dataOra** con il binding statico lasceremmo al compilatore il compito di capire se l'oggetto a cui si riferisce la stampa è un **orario** o un **dataOra** e il compilatore non ha modo di capire a quale tipo riferirsi quindi si riferirà sempre al tipo statico dei puntatori/riferimenti a quell'oggetto.  
.  
.  
.  
.  
.  
**LEZ 15-11-2022 h: 57:40**