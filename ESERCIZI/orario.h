class orario {
private:
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