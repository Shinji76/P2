#include "carta.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    carta w;
    w.show();
    return a.exec();
}
