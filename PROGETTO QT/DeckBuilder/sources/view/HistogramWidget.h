#ifndef HISTOGRAM_WIDGET_H
#define HISTOGRAM_WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QValueAxis>

class HistogramWidget : public QWidget {
Q_OBJECT
private:
    QWidget* widget;
    QPushButton* save_button;
    QPushButton* delete_button;

public:
    explicit HistogramWidget(QWidget *parent = nullptr);

signals:
    void saveDeck();
    void deleteDeck();

public slots:
    void SaveClick();
    void DeleteClick();
};

#endif // HISTOGRAM_WIDGET_H
