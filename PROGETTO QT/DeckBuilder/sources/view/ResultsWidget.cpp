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

    previous_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/left_arrow.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/right_arrow.svg")), "");
    next_page->setEnabled(false);
    hbox->addWidget(next_page);

    hbox->addStretch();

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);

    // Connects signals
    connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
    connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);
}

void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results) {
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    } 
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getItems().size() == query.getSize());
    renderer->render(grid, results, &lookup);

    // Connects signals
    for (auto cit = lookup.begin(); cit != lookup.end(); cit++) {
        if (cit->getAddButton()) {
            connect(cit->getAddButton(), &QPushButton::clicked, std::bind(&addCard, this, cit->getCard()));
        }
        if (cit->getRemoveButton()) {
            connect(cit->getRemoveButton(), &QPushButton::clicked, std::bind(&removeCard, this, cit->getCard()));
        }
    }
}