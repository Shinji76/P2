#include "HistogramWidget.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>

    QBarSet *set0 = new QBarSet("0");
    QBarSet *set1 = new QBarSet("1");
    QBarSet *set2 = new QBarSet("2");
    QBarSet *set3 = new QBarSet("3");
    QBarSet *set4 = new QBarSet("4");
    QBarSet *set5 = new QBarSet("5");
    QBarSet *set6 = new QBarSet("6");
    QBarSet *set7 = new QBarSet("7+");

    QColor *blue = new QColor(38, 118, 237);
    QColor *black = new QColor(0, 0, 0);

    set1->setColor(*blue);
    set2->setColor(*blue);
    set0->setColor(*blue);
    set3->setColor(*blue);
    set4->setColor(*blue);
    set5->setColor(*blue);
    set6->setColor(*blue);
    set7->setColor(*blue);

    set0->setBorderColor(*black);

    *set0 << 1;
    *set1 << 3;
    *set2;
    *set3 << 3;
    *set4 << 4;
    *set5 << 7;
    *set6 << 2;
    *set7 << 3;

    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);
    series -> append(set2);
    series -> append(set3);
    series -> append(set4);
    series -> append(set5);
    series -> append(set6);
    series -> append(set7);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();

    QStringList mana_costs;
    mana_costs << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7+";

    QPalette pal = qApp -> palette();
    pal.setColor(QPalette::Window, QRgb(0x858585));
    pal.setColor(QPalette::WindowText, QRgb(0x505050));
    qApp -> setPalette(pal);

    QChartView *chartView = new QChartView(chart);
    chartView ->setRenderHint(QPainter::Antialiasing);

    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
    return a.exec();