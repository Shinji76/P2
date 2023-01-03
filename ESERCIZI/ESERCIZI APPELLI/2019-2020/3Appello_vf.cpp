class A {
public:
	virtual ~A() {}
};

class B: public A {
public: 
	virtual bool m() const =0;
};

class C: public B {
public:
	bool m() const {return true;}
};

class D: virtual public A {
protected:
	D() {}
};

class E: public D {
public:
	E& operator=(const E& x) {
		D::operator=(x);
		return*this;
	}
};

/*
Si consideri il codice sopra. Selezionare quali delle seguente affermazioni sono VERE:                                   
1. A è una classe base polimorfa																						//R: V	
2. Il costruttore di copia di A non è pubblicamente disponibile															//R: F	
3. A è una classe base astratta;																						//R: V	ERRORE
4. Il costruttore senza parametri di A è polimorfo																		//R: F	
5. B è una classe derivata astratta																						//R: V	
6. B è una classe polimorfa																								//R: V	
7. L assegnazione di B è virtuale pura																					//R: F	
8. B è una classe virtuale pura																							//R: V	ERRORE
9. C è una sottoclasse concreta di B																					//R: V	
10. C é una classe polimorfa																							//R: F	ERRORE
11. C è una classe che non permette la costruzione pubblica dei suoi oggetti											//R: F	
12. Nella classe C il metodo m() è overloaded																			//R: F	
13. D è una classe che non permette di costruire pubblicamente i suoi oggetti											//R: V	
14. D è una classe che permette la costruzione di oggetti di D che siano sottooggetti di altri oggetti					//R: V	
15. Se d è un oggetto di tipo D allora in un main() la chiamata d->m(); non compila										//R: V	
16. D ha il costruttore di copia protetto																				//R: F	
17. E è una classe derivata indirettamente da D																			//R: F	
18. L assegnazione ridefinita di E ha comportamento identico a quello dell assegnazione standard di E					//R: V	
19. Se c è un oggetto di tipo C allora in un main lo statement E e(c); compila correttamente							//R: F	
20. E è una classe derivata indirettamente da D																			//R: 	
21. Se d è un oggetto di tipo D e c è un oggetto di tipo C allora in un main lo statement c=e; compila correttamente	//R: F	ERRORE
*/

// RISULTATO: 16/20
