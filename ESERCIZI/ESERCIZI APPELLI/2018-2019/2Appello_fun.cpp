/*
Si consideri il seguente modello concernente il servizio di file hosting QooqleDrive®.
(A) Definire la seguente gerarchia di classi.

	1. Definire una classe File i cui oggetti rappresentano un generico file memorizzabile in un account QooqleDrive®.
	Ogni File è caratterizzato dalla sua dimensione (in MB) e dall'essere pubblicamente accessibile o meno.
	Dotare la classe File di opportuno/i costruttore/i.
	
	2. Definire una classe Audio derivata da File i cui oggetti rappresentano un file audio.
	Ogni file audio è caratterizzato dall'essere lossy (cioè compresso con perdita di informazione) oppure no.
	Dotare la classe Audio di opportuno/i costruttore/i.
	
	3. Definire una classe Mp3 derivata da Audio i cui oggetti rappresentano un file audio in formato mp3.
	Tutti i file audio in formato mp3 sono lossy.
	Dotare la classe Mp3 di opportuno/i costruttore/i.
	
	4. Definire una classe Video derivata da File i cui oggetti rappresentano un file video.
	Ogni Video è caratterizzato dal suo framerate, cioè un numero intero positivo che rappresenta la frequenza in hertz.
	Dotare la classe Video di opportuno/i costruttore/i.

(B) Definire una classe QoogleDrive i cui oggetti rappresentano un account Qoogledrive®.
Più precisamente, un oggetto QoogleDrive caratterizzato da tutti i file correntemente memorizzati dall'account, che devono essere rappresentati mediante un contenitore di puntatoti al tipo File costante, e dalla capacità massima di memorizzazione 
(in MB) dell'account.
Devono essere definite le seguenti funzionalità: 

	5. Un metodo di istanza Audio uploadFile(File&) con il seguente comportamento:
	una invocazione qd.uploadFile(f) provoca l'upload del file f nell'account qd quando:
		(I) f è un file audio pubblicamente accessibile.
		(II) la memoria libera dell'account qd consente l'upload: se l'upload di f va a buon fine allora viene ritornata una copia del file audio f, altrimenti viene sollevata una eccezione di tipo Exc, un tipo di cui è richiesta la definizione.
	
	6. Un metodo di istanza list<Audio*> audioCopy() con il seguente comportamento
	una invocazione qd.audioCopy() ritorna una lista (possibilmente vuota) contenente tutti e soli i puntatori ai file audio memorizzati nell'account qd che:
		(I) sono dei file audio non lossy.
		(II) sono dei file audio in formato mp3.
	
	7. Un metodo di istanza Video* minVideo(unsigned int) con il seguente comportamento:
	una invocazione qd.minVideo(fr) ritorna un puntatore sempre non nullo ad un video memorizzato nell'account qd che:
		(I) abbia un framerate maggiore di fr.
		(II) abbia dimensione minima tra tutti i video memorizzati nell'account qd, se un tale video non dovesse essere trovato tra i file memorizzati nell'account qd allora viene sollevata una eccezione di tipo Exc.
*/

#include <iostream>
#include <vector>
#include <list>
using std::list;
using std::vector;


class File {
private:
	double sizeMB;
	bool isAccessible;
public:
	virtual ~File() {}
	double getSizeMB() const {return sizeMB;}
	bool getIsAccessible() const {return isAccessible;}
	File(double sMB = 0, bool iA = false) : sizeMB(sMB), isAccessible(iA) {}
};

class Audio : public File {
private:
	bool isLossy;
public:
	bool getIsLossy() const {return isLossy;}
	Audio(bool iL = false) : isLossy(iL) {}
};

class Mp3 : public Audio {
public:
	Mp3(Audio a = true) {}
};

class Video : public File {
private:
	unsigned int frameRate;
public:
	unsigned int getFrameRate() const {return frameRate;}
};

class QoogleDrive {
private:
	vector<const File*> v;
	unsigned int maxCapacityMB;
	double usedMemory(vector<const File*>) {
		double totalSize = 0;
		for(auto cit = v.begin(); cit != v.end(); cit++) {
			totalSize = totalSize + (*cit)->getSizeMB();
		}
		return totalSize;
	}
public:	
	Audio uploadFile(File& f) {
		Audio copy = dynamic_cast<Audio&>(f);
		if(copy.getIsAccessible() && usedMemory(v) + copy.getSizeMB() < maxCapacityMB) {
			v.push_back(&f);
			return copy;
		}
		throw Exc();
	}

	list<Audio*> audioCopy() {
		list<Audio*> aux;
		const Audio* temp = nullptr;
		for(auto cit = v.begin(); cit != v.end(); cit++) {
			temp = dynamic_cast<const Audio*>(*cit);
			if( !(temp->getIsLossy()) ) {
				aux.push_back(const_cast<Audio*>(temp));
			}
			if(dynamic_cast<const Mp3*>(temp)) {
				aux.push_back(const_cast<Audio*>(temp));
			}
		}
		return aux;
	}

	Video* minVideo(unsigned int fr) {
		unsigned int minSize = v[0]->getSizeMB();
		Video* temp = nullptr;
		for(auto cit = v.begin(); cit != v.end(); cit++) {
			if(dynamic_cast<const Video*>(*cit)->getFrameRate() > fr) {
				if((*cit)->getSizeMB() <= minSize) {
					minSize = (*cit)->getSizeMB();
					temp = static_cast<Video*>(const_cast<File*>(*cit));
				}
			}
		}
		if(temp)
			return temp;
		throw Exc();
	}
};

class Exc {
private:
	int err;
public:
	Exc(int e = 0) : err(e) {
		std::cout << "ERRORE";
	}
};