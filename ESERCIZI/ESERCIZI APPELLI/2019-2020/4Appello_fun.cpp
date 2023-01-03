#include <vector>
#include <list>
using std::vector;
using std::list;

class B {
private:
	vector<bool>* ptr;
	virtual void m() = 0;
};

class D: public B {
private: 
	int x;
};

class E: public D {
private:
	list<int*> l;
	int& ref;
	double*p;
public: 
	void m(){}
	//ridefinire costruttore di copia
	E(const E& ec) : D(ec), l(ec.l), ref(ec.ref), p(ec.p) {}
};

