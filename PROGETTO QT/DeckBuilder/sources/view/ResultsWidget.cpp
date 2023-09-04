#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

ResultsWidget::ResultsWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    hbox->addStretch();     //forse da rimuovere

    previous_page = new QPushButton(
        QIcon(QPixmap(":/Assets/Icons/left_arrow.svg")),
        ""
    );
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(
        QIcon(QPixmap(":/Assets/Icons/right_arrow.svg")),
        ""
    );
    next_page->setEnabled(false);
    hbox->addWidget(next_page);

    hbox->addStretch();

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);

    connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
    connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);
}

void ResultsWidget::showResults(Query query, ResultSet results) {
    unsigned int index = 0;
    // Clears previous data
    while (!boxes.isEmpty()) {
        const BoxWidget* info = boxes.takeLast();
        delete info;
    }
    if(results.getTotal() == 0) {
        results_total->setText("No results for \"" + QString::fromStdString(query.getName()) + "\".");
    }
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getResult().size() == 9);

    // Rinomino figli
    for(auto it = results.getResult().begin(); it != results.getResult().end(); it++) {
        BoxWidget* new_box = new BoxWidget(this);
        new_box->setCard(**it);
        boxes.push_back(new_box);
        grid->addWidget(new_box, index / 3, index % 3); 
        index++;
    }
}

const QVector<const BoxWidget*>& ResultsWidget::getBoxes() const {
    return boxes;
}
