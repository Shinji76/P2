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
    chart->legend()->hide(); // hide the legend

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create the tooltip label
    QLabel *tooltip = new QLabel(chartView);
    tooltip->setFixedSize(20, 20);
    tooltip->setAlignment(Qt::AlignCenter);
    tooltip->setStyleSheet("QLabel { background-color : white; color : black; }");


    // Set fixed font for labels inside bars
    QFont font;
    font.setPixelSize(12);
    font.setBold(false);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelsFont(font);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->hide();

    // Connect the hovered signal to a slot that updates the tooltip label
    QObject::connect(barSet, &QBarSet::hovered, [=](bool status, int index) {
        if (status) {
            tooltip->setText(QString::number(barSet->at(index)));
            QPoint p = chartView->mapFromGlobal(QCursor::pos());
            QPointF point = chart->mapToValue(chartView->mapToScene(p));
            qreal x = chart->plotArea().x() + chart->plotArea().width() * ((qreal)index + 0.5) / barSet->count();
            qreal y = point.y();
            tooltip->move(x - tooltip->width() / 2, y + 5);
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
