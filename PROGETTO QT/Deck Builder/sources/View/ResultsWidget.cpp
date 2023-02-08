#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "ResultRenderer/List.h"
#include "ResultRenderer/Grid.h"

ResultsWidget::ResultsWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    results_total = new QLabel();
    hbox->addWidget(results_total);

    hbox->addStretch();

    previous_page = new QPushButton(QIcon(QPixmap(":/assets/icons/left_arrow.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap(":/assets/icons/right_arrow.svg")), "");
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

    renderer = new ResultRenderer::List();

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

    // Shows new data
    if (results.getTotal() > 0) {
        results_total->setText(QString::number(results.getTotal()) + " results for \"" + QString::fromStdString(query.getText()) + "\":");
    }
    else {
        results_total->setText("No results for \"" + QString::fromStdString(query.getText()) + "\".");
    }    
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getItems().size() == query.getSize());
    renderer->render(grid, results, &lookup);

    // Connects signals
    for (auto cit = lookup.begin(); it != lookup.end(); it++) {
        if (cit->getAddButton()) {
            connect(cit->getAddButton(), &QPushButton::clicked, std::bind(&addCard, this, cit->getCard()));
        }
        if (cit->getRemoveButton()) {
            connect(cit->getRemoveButton(), &QPushButton::clicked, std::bind(&removeCard, this, cit->getCard()));
        }
    }
}
