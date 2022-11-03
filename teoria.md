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

- Void conersion

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
- Istanziazione implicita

``` cpp
k = min(i, j);
t = min(r, s);
```

- Istanziazione esplicita

``` cpp
k = min<int>(i, j);
t = min<orario>(r, s);
```

I template possono accettare sia ***parametri di tipo*** che ***parametri valore*** di qualche tipo.  

Quando viene usata l'istanziazione implicita del template il tipo di ritorno dell'istanza del template non viene considerato nella *deduzione degli argomenti*.  

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