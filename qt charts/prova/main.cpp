#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QValueAxis>


#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QBarSet *barSet = new QBarSet("Bar Set");

    for (int i = 0; i < 8; ++i) {
        *barSet << rand() % 100;
    }

    QBarSeries *series = new QBarSeries();
    series->append(barSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    //chart->legend()->hide(); // hide the legend

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create the tooltip label
    QLabel *tooltip = new QLabel(chartView);
    tooltip->setFixedSize(20, 20);
    tooltip->setAlignment(Qt::AlignCenter);
    tooltip->setStyleSheet("QLabel {font : 15; font : bold; color : gold;}");



    QObject::connect(barSet, &QBarSet::hovered, [=](bool hovered, int index) {
        if (hovered) {
            tooltip->setText(QString::number(barSet->at(index)));
            qreal x = chart->plotArea().x() + chart->plotArea().width() * ((qreal)index + 0.5) / barSet->count();
            qreal y = chart->plotArea().y() + chart->plotArea().height();
            tooltip->move(x - tooltip->width() / 2, y - tooltip->height() * 1.2);
            tooltip->show();
        } else {
            tooltip->hide();
        }
    }
    );

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return app.exec();
}
