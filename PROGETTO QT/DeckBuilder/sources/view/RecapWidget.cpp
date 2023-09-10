#include "RecapWidget.h"

#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>

RecapWidget::RecapWidget(QWidget* parent) : QWidget(parent) {
    tableWidget = new QTableWidget(0, 5, this);

    nome_label = new QLabel();    
    total_label = new QLabel();

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->addWidget(nome_label);
    nome_label->setAlignment(Qt::AlignCenter);
    nome_label->setText(" awdadw ");
    nome_label->setStyleSheet("font-size : 20px");
    
    vbox->addWidget(total_label);
    total_label->setText("Numero Carte: ");
    total_label->setAlignment(Qt::AlignCenter);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(tableWidget);
    vbox->addLayout(layout);
    
    setLayout(vbox);
    
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

    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

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

void RecapWidget::addRow(const AbstractCard* card, unsigned int copies) {
    tableWidget->insertRow(tableWidget->rowCount());

    QTableWidgetItem* item_name = new QTableWidgetItem(QString::fromStdString(card->getNome()));
    item_name->setFlags(item_name->flags() ^ Qt::ItemIsEditable);
    tableWidget->setItem(tableWidget->rowCount()-1, 0, item_name);

    QTableWidgetItem* item_copy = new QTableWidgetItem(QString::number(copies));
    item_copy->setFlags(item_copy->flags() ^ Qt::ItemIsEditable);
    tableWidget->setItem(tableWidget->rowCount()-1, 1, item_copy);
    
    QTableWidgetItem* item_mana = new QTableWidgetItem(QString::number(card->getManaCost()));
    item_mana->setFlags(item_mana->flags() ^ Qt::ItemIsEditable);
    tableWidget->setItem(tableWidget->rowCount()-1, 2, item_mana);

    QPushButton* item_minus = new QPushButton(QIcon(QPixmap(":/Assets/Icons/minus.svg")),"");
    item_minus->setObjectName(QString::number(card->getID()) + '-');
    tableWidget->setCellWidget(tableWidget->rowCount()-1, 3, item_minus);

    QPushButton* item_plus = new QPushButton(QIcon(QPixmap(":/Assets/Icons/plus.svg")),"");
    item_plus->setObjectName(QString::number(card->getID()) + '+');
    tableWidget->setCellWidget(tableWidget->rowCount()-1, 4, item_plus);

    connect(item_plus, SIGNAL(clicked()), this, SLOT(AddClick()));
    connect(item_minus, SIGNAL(clicked()), this, SLOT(RemoveClick()));
    connect(this, SIGNAL(addEmitterRecap(QString)), parentWidget()->parentWidget()->parentWidget(), SLOT(addCardRecap(QString)), Qt::UniqueConnection);
    connect(this, SIGNAL(removeEmitterRecap(QString)), parentWidget()->parentWidget()->parentWidget(), SLOT(removeCardRecap(QString)), Qt::UniqueConnection);
}

void RecapWidget::updateRow(const QString& name, unsigned int copies) {
    for(int i = 0; i < tableWidget->rowCount(); i++) {
        if(tableWidget->item(i, 0)->text() == name) {
            tableWidget->item(i, 1)->setText(QString::number(copies));
        }
    }
}

void RecapWidget::deleteRow(const QString& name) {
    for(int i = 0; i < tableWidget->rowCount(); i++) {
        if(tableWidget->item(i, 0)->text() == name) {
            tableWidget->removeRow(i);
        }
    }
}

void RecapWidget::AddClick() {
    emit addEmitterRecap(qobject_cast<QPushButton*>(QObject::sender())->objectName());
}

void RecapWidget::RemoveClick() {
    emit removeEmitterRecap(qobject_cast<QPushButton*>(QObject::sender())->objectName());
}

void RecapWidget::clearTable() {
    disconnect(tableWidget, 0, 0, 0);
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
}

void RecapWidget::InsertTitle(QString title) {
    nome_label->setText(title);
}

void RecapWidget::UpdateTotal(const unsigned int total) {
    QString counter = QString::number(total);
    total_label->setText("Numero carte: " + counter + "/20");
}
