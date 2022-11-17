
class orario {
protected:
    int sec;
public:
    orario();
    orario(int, int);
    orario(int, int, int);
    int Ore() const;
    int Minuti() const;
    int Secondi() const;
    orario UnOraPiuTardi();
    void AvanzaUnOra();
    void StampaSecondi() const;
    orario operator+(orario) const; 
    orario operator-(orario) const; 
    bool operator==(const orario&) const;
};

std::ostream& operator <<(std::ostream&, const orario&);

class dataOra : public orario {
private:
	int giorno;
	int mese;
	int anno;
public:
	int Giorno() const;
	int Mese() const;
	int Anno() const;
	void AvanzaUnGiorno(); 
	int GiorniDelMese();
	dataOra operator+(const orario& o) const;
};

class dataOraSett : public dataOra {
public:
	enum giorno {lun, mar, mer, gio, ven, sab, dom};
	giorno GiornoSettimana() const;
private:
	giorno giornosettimana;
};

void dataOra::AvanzaUnGiorno() {
	if (giorno < GiorniDelMese())
		giorno++;
	else if(mese < 12) {
		giorno = 1;
		mese++;
	} else {
		giorno = 1;
		mese = 1;
		anno++;
	}
}

dataOra dataOra::operator+(const orario& o) const {
	dataOra aux = *this;
	aux.sec = sec + 3600*o.Ore() + 60*o.Minuti() + 60*o.Secondi();
	if(aux.sec >= 86400) {
		aux.sec = aux.sec - 86400;
		aux.AvanzaUnGiorno();
	}
	return aux;
}

