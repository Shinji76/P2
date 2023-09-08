#include "RecapWidget.h"

#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>

RecapWidget::RecapWidget(QWidget* parent) : QWidget(parent) {
    tableWidget = new QTableWidget(0, 5, this);

    QLabel* card_amount = new QLabel;
    
    // Aggiunta della tabella al layout
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(tableWidget);

    // Impostazione delle intestazioni delle colonne
    QTableWidgetItem* nome = new QTableWidgetItem("Nome");
    QTableWidgetItem* copie = new QTableWidgetItem("#");
    QTableWidgetItem* minus = new QTableWidgetItem("-");
    QTableWidgetItem* plus = new QTableWidgetItem("+");
    QTableWidgetItem* mana = new QTableWidgetItem(QIcon(QPixmap(":/Assets/Icons/mana.svg")), "");

    QHeaderView* header = new QHeaderView(Qt::Horizontal, tableWidget);
    tableWidget->setHorizontalHeader(header);
    tableWidget->setHorizontalHeaderItem(0, nome);
    tableWidget->setHorizontalHeaderItem(1, copie);
    tableWidget->setHorizontalHeaderItem(2, mana);
    tableWidget->setHorizontalHeaderItem(3, minus);
    tableWidget->setHorizontalHeaderItem(4, plus);

    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    // Impostazione delle dimensioni delle colonne
    header->setSectionResizeMode(0, QHeaderView::Stretch);
    header->setSectionResizeMode(1, QHeaderView::Fixed);
    header->setSectionResizeMode(2, QHeaderView::Fixed);
    header->setSectionResizeMode(3, QHeaderView::Fixed);
    header->setSectionResizeMode(4, QHeaderView::Fixed);
    
    header->resizeSection(0, 100);
    header->resizeSection(1, 35);
    header->resizeSection(2, 35); 
    header->resizeSection(3, 25); 
    header->resizeSection(4, 25); 
}

// Aggiunge una nuova riga alla tabella
void RecapWidget::addRow(const AbstractCard* card, unsigned int copies) {
    tableWidget->insertRow(tableWidget->rowCount());

    QTableWidgetItem* item_name = new QTableWidgetItem(QString::fromStdString(card->getNome()));
    tableWidget->setItem(tableWidget->rowCount()-1, 0, item_name);

    QTableWidgetItem* item_copy = new QTableWidgetItem(copies);
    tableWidget->setItem(tableWidget->rowCount()-1, 1, item_copy);
    
    QTableWidgetItem* item_mana = new QTableWidgetItem(card->getManaCost());
    tableWidget->setItem(tableWidget->rowCount()-1, 2, item_mana);

    QPushButton* item_minus = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")),"");
    item_minus->setObjectName(QString::number(card->getID()) + '-');
    tableWidget->setCellWidget(tableWidget->rowCount()-1, 3, item_minus);

    QPushButton* item_plus = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")),"");
    item_plus->setObjectName(QString::number(card->getID()) + '+');
    tableWidget->setCellWidget(tableWidget->rowCount()-1, 4, item_plus);
}

void RecapWidget::updateRow(const QString& name, unsigned int copies) {
    for(int i = 0; i < tableWidget->rowCount(); i++) {
        if(tableWidget->item(i, 0)->text() == name) {
            tableWidget->item(i, 1)->setText(QString::number(copies));
        }
    }
}

// Rimuove una riga dalla tabella
void RecapWidget::deleteRow(const QString& name) {
    for(int i = 0; i < tableWidget->rowCount(); i++) {
        if(tableWidget->item(i, 0)->text() == name) {
            tableWidget->removeRow(i);
        }
    }
}
