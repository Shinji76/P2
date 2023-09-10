#ifndef RECAP_WIDGET_H
#define RECAP_WIDGET_H

#include "CardLayout/BoxWidget.h"

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>

class RecapWidget : public QWidget {
    Q_OBJECT

private:
    QLabel* total_label;
    QTableWidget* tableWidget;

public:
    RecapWidget(QWidget* parent = nullptr);

    void clearTable();
    void deleteRow(const QString& name);
    void addRow(const AbstractCard* card, unsigned int copies);
    void updateRow(const QString& name, unsigned int copies);

signals:
    void addEmitterRecap(QString);
    void removeEmitterRecap(QString);

public slots:
    void AddClick();
    void RemoveClick();
    void UpdateTotal(const unsigned int total);
};

#endif // RECAPWIDGET_H
