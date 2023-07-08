#include "RecapWidget.h"

#include <QHBoxLayout>
#include <QHeaderView>

RecapWidget::RecapWidget(QWidget* parent) : QWidget(parent) {
    tableWidget = new QTableWidget(0, 2, this);
    tableWidget->setColumnCount(2);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Aggiunta della tabella al layout
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(tableWidget);

    // Impostazione delle intestazioni delle colonne
    QStringList headers;
    headers << "Pulsante" << "Stringa";
    tableWidget->setHorizontalHeaderLabels(headers);

    // Impostazione delle dimensioni delle colonne
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}

// Aggiunge una nuova cella alla tabella
void RecapWidget::addCell(LookupWidget* lookup) {
    cells.push_back(*lookup);
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);
    tableWidget->setItem(row, 1, new QTableWidgetItem(text));
}

// Rimuove una cella dalla tabella
void RecapWidget::removeCell(int index) {
    if (index >= 0 && index < cells.size()) {
        cells.erase(cells.begin() + index);
        tableWidget->removeRow(index);
    }
}
