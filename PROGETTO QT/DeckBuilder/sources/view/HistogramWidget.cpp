#include "HistogramWidget.h"

HistogramWidget::HistogramWidget(QWidget* parent) : QWidget(parent) {
    QHBoxLayout * hbox = new QHBoxLayout(this);

    save_button = new QPushButton("Salva", this);
    hbox->addWidget(save_button);
    
    delete_button = new QPushButton("Elimina", this);
    hbox->addWidget(delete_button);

    QBarSet *set0 = new QBarSet("0");
    QBarSet *set1 = new QBarSet("1");
    QBarSet *set2 = new QBarSet("2");
    QBarSet *set3 = new QBarSet("3");
    QBarSet *set4 = new QBarSet("4");
    QBarSet *set5 = new QBarSet("5");
    QBarSet *set6 = new QBarSet("6");
    QBarSet *set7 = new QBarSet("7+");

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
    //chart->legend()->hide();

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
}

void HistogramWidget::SaveClick() {

}

void HistogramWidget::DeleteClick() {

}