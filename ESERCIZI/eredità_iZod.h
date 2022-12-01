/* Si consideri il seguente modello di realtà concernente i file audio memorizzati in un riproduttore audiodigitale iZod.
(A) Definire la seguente gerarchia di classi.
	1. Definire una classe base polimorfa astratta FileAudio i cui oggetti rappresentano un file audio memorizzabile in un iZod. Ogni FileAudio  caratterizzato dal titolo (una stringa) e dalla propria dimensionein MB.
	La classe è astratta in quanto prevede i seguenti metodi virtuali puri:
		• un metodo di “clonazione”: FileAudio* clone().
		• un metodo bool qualita() con il seguente contratto: f->qualita() ritorna true se il file audio *f èconsiderato diqualità, altrimenti ritorna false.
	2. Definire una classe concreta Mp3 derivata da FileAudio i cui oggetti rappresentano un file audio in formato mp3.
	Ogni oggetto Mp3 è caratterizzato dal proprio bitrate espresso in Kbit/s. La classe Mp3 implementa i metodi virtuali puri di FileAudio come segue:
		• per ogni puntatore p a Mp3, p->clone() ritorna un puntatore ad un oggetto Mp3 che è una copia di *p.
		• per ogni puntatore p a Mp3, p->qualita() ritorna true se il bitrate di *p è ≥ 192 Kbit/s, altrimentiritorna false.
	3. Definire una classe concreta WAV derivata da FileAudio i cui oggetti rappresentano un file audio informato WAV.
	Ogni oggetto WAV è caratterizzato dalla propria frequenza di campionamento espressa in kHz e dall’essere lossless oppure no (cioè con compressione senza perdita oppure con perdita). La classe WAVimplementa i metodi virtuali puri di FileAudio come segue:
		• per ogni puntatore p a WAV, p->clone() ritorna un puntatore ad un oggetto WAV che è una copia di *p.
		• per ogni puntatore p a WAV, p->qualita() ritorna true se la frequenza di campionamento di *p è ≥ 96 kHz,altrimentiritorna false.
(B) Definire una classe iZod i cui oggetti rappresentano i brani memorizzati in un iZod.
	La classe iZod deve soddisfare le seguenti specifiche:
	1. E definita una classe annidata Brano i cui oggetti rappresentano un brano memorizzato nell’iZod.
	Ogni oggetto Brano èrappresentato da un puntatore polimorfo ad un FileAudio.
		• La classe Brano deve essere dotata di un opportuno costruttore Brano(FileAudio*) con il seguente comportamento:Brano(p) costruisce un oggetto Brano il cui puntatore polimorfo punta ad una copia dell’oggetto *p.
		• La classe Brano ridefinisce costruttore di copia profonda, assegnazione profonda e distruttore profondo.
	2. Un oggetto di iZod è quindi caratterizzato da un vector di oggetti di tipo Brano che contiene tutti i brani memorizzati nell’iZod.
	3. La classe iZod rende disponibili i seguenti metodi:
		• Un metodo vector<Mp3> mp3(double, int) con il seguente comportamento: una invocazione iz.mp3(dim,br)ritorna un vector di oggetti Mp3 contenente tutti e soli i file audio in formato mp3 memorizzati nell’iZod iz che:
			(i) hanno una dimensione ≥ dim e 
			(ii) hanno un bitrate ≥ br.
		• Un metodo vector<FileAudio*> braniQual() con il seguente comportamento: una invocazione iz.braniQual()ritorna il vector dei puntatori ai FileAudio memorizzati nell’iZod iz che:
			(i) sono considerati di qualità e
			(ii) se sono dei file audio WAV allora devono essere lossless.
		• Un metodo void insert(Mp3*) con il seguente comportamento: una invocazione iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani memorizzati nell’iZod iz se il file audio mp3 *p non è già memorizzatoin iz, mentre se il file audio *p risulta già memorizzato non provoca alcun effetto.*/

#include<iostream>
#include<vector>

class FileAudio {
private:
	std::string titolo;
	double dim;
public:
	virtual FileAudio* clone() const =0;
	virtual bool qualita() const =0;
	virtual ~FileAudio() {}
    double getSize() const {
        return dim;
    }
	virtual bool operator==(const FileAudio& f) const {
		return titolo == f.titolo && dim==f.dim;
	}
};

class Mp3 : public FileAudio {
private:
	unsigned int bitRate;
	static unsigned int QualityBitRate;
public:
	Mp3* clone() const override {
		return new Mp3(*this);
	}

	bool qualita() const override {
		return bitRate >= QualityBitRate;
	}
    unsigned int getBitRate() const {
        return bitRate;
    }
	bool operator==(const FileAudio* f) const override {
		return typeid(f) == typeid(*this) && FileAudio::operator==(f) && bitRate == static_cast<const Mp3&>(f).bitRate;
	}

};

class WAV : public FileAudio {
private:
	unsigned int freq;
	static unsigned int QualityFreq;
	bool LossLess;
public:
	WAV* clone() const override {
		return new WAV(*this);
	}

	bool qualita() const override {
		return freq >= QualityFreq;
	}
	bool isLossLess() const {
		return LossLess;
	}
};

class iZod {
private:
	class Brano {
	public:
		FileAudio* p;
		Brano(FileAudio* q) : p(q->clone()) {}
		Brano(const Brano& b) : p(b.p->clone()) {}
		Brano& operator=(const Brano& b);
		~Brano();
		FileAudio* operator->() const {
			return p;
		}
		FileAudio& operator*() const {
			return *p;
		}
	};
	std::vector<Brano> v;
public:
    std::vector<Mp3> mp3(double, int) const;
	std::vector<FileAudio*> braniQual() const;
	void insert(Mp3*);
};

iZod::Brano::~Brano() {
	if(p)
		delete p;
}

iZod::Brano& iZod::Brano::operator=(const Brano& b) {
	if(this != &b) {
        if(p)
    		delete p;
		p = b.p->clone();
	}
	return *this;
}

std::vector<Mp3> iZod::mp3(double dim, int br) const {
	std::vector<Mp3> aux;
	std::vector<Brano>::const_iterator cit = v.begin();
	for(cit; cit != v.end(); ++cit) {
		Mp3* tmp = dynamic_cast<Mp3*> (cit->p);
		if(tmp && tmp->getBitRate() >= br && tmp->getSize() >= dim)
			aux.push_back(*tmp);
	}
	return aux;
}

std::vector<FileAudio*> iZod::braniQual() const {
	std::vector<FileAudio*> aux;
	std::vector<Brano>::const_iterator cit = v.begin();
	for(cit; cit != v.end(); ++cit) {
		if((*cit)->qualita() && (!(dynamic_cast<WAV*> (cit->p))) || (static_cast<WAV*> (cit->p))->isLossLess())
			aux.push_back(cit->p);
	}
	return aux;
}

/* Un metodo void insert(Mp3*) con il seguente comportamento: 
una invocazione iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani memorizzati nell’iZod iz se il file audio mp3 *p non è già memorizzato in iz, mentre se il file audio *p risulta già memorizzato non provoca alcun effetto.*/
void iZod::insert(Mp3* q) {
	auto it = v.begin();
	for(it; it != v.end() && !(*(it->p) == *q); ++it) {
		
	}
}

unsigned int Mp3::QualityBitRate = 192;
unsigned int WAV::QualityFreq = 96;