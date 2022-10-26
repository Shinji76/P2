class Raz {
private:
    int num, den; //den != 0, invariante per ogni istanza
public:
    Raz(int n = 0, int d = 1);
    Raz Inverso() const;
    operator double() const;
    Raz operator++ (int);   //++ postfisso
    Raz& operator++ ();      //++ prefisso
    static Raz unTerzo();
    Raz operator+ (const Raz& r) const;
    Raz operator* (const Raz& r) const;
    bool operator== (const Raz& r) const;
};