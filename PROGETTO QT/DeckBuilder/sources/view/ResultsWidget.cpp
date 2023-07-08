#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "ResultLayout/Grid.h"

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
    // Clears previous data
    while (!lookup.isEmpty()) {
        LookupWidget info = lookup.takeLast();
        delete info.getWidget();
    }
    if(results.getTotal() == 0) {
        results_total->setText("No results for \"" + QString::fromStdString(query.getName()) + "\".");
    }
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getResult().size() == 9);

    // Connects signals
    for (auto cit = lookup.begin(); cit != lookup.end(); cit++) {
        cit->disableRemoveButton();
        cit->enableAddButton();
        if (cit->getAddButton()) {
            connect(cit->getAddButton(), &QPushButton::clicked, std::bind(&ResultsWidget::addCard, this, cit->getCard()));
        }
        if (cit->getRemoveButton()) {
            connect(cit->getRemoveButton(), &QPushButton::clicked, std::bind(&ResultsWidget::removeCard, this, cit->getCard()));
        }
    }
}
