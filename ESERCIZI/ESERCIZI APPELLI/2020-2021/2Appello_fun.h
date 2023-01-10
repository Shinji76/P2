using std::string;
#include <string>

class QWidget {
public:
    virtual int heightDefault() const;
};

class QFrame: public QWidget {
public:
    void setLineWidth(int) {} 
};

class QLabel : public QFrame {
public:
    int heightDefault() const override;
    void setWordWrap(bool) {}
};

class QSplitter: public QFrame {
public:
};

class QLCDNumber: public QFrame {
public:
    void setDigitCount(int) {}
};