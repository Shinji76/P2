#include <QApplication>
#include <QFile>

#include "Engine/Memory.h"
#include "view/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":Assets/Icons/card_icon.svg"));

/*
    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));
*/

    Memory engine;
    MainWindow window(engine);
    window.resize(1024, 576);
    window.show();

    return app.exec();
}
