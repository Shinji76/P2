class orario {
private:
    int sec;
public:
    orario();
    orario(int, int);
    orario(int, int, int);
    int Ore();
    int Minuti();
    int Secondi();
    orario UnOraPiuTardi();
    void AvanzaUnOra();
    void StampaSecondi() const;

};