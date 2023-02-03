#include <string>
using std::string;

class QString {
private:
    string str;
public:
    QString(const string s) : str(s) {}
};

class QPaintDevice {
public:
	int width() const {}
    virtual ~QPaintDevice();
};

class QWidget: public QPaintDevice {
public:
	bool hasFocus() const {}
	void clearFocus() {}
};

class QAbstractButton: public QWidget {
public:
    void setText(const string&) {}
};