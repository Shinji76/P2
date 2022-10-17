class C {
private:
    int x;
public:
    C(int n = 0);
    C F(C);
    C G(C) const;
    C H(C&);
    C I(const C&);
    C J(const C&) const;
};
