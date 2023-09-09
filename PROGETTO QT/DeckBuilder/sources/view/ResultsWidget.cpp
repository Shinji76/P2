#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

ResultsWidget::ResultsWidget(QWidget* parent) : QWidget(parent) {

    QVBoxLayout* main_layout = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();
    grid = new QGridLayout();

    previous_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/left_arrow.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/right_arrow.svg")), "");
    next_page->setEnabled(false);
    hbox->addWidget(next_page);
    
    main_layout->addLayout(hbox);
    main_layout->addLayout(grid);
    
    setLayout(main_layout);

    connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
    connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);
}

void ResultsWidget::createBoxes(std::vector<const AbstractCard*> cards) {
    for(auto it = cards.begin(); it != cards.end(); it++) {
        BoxWidget* new_box = new BoxWidget(*it, this);
        new_box->setStyleSheet("border: 1px solid black;");
        new_box->hide();
        boxes.push_back(new_box);
    }
    showInitialResults();
}

void ResultsWidget::showInitialResults() {
    unsigned int index = 0;

    for(auto it = boxes.begin(); index < 9; it++) {
        (*it)->show();
        grid->addWidget(*it, index / 3, index % 3);
        index++;
    }
    previous_page->setEnabled(false);
    next_page->setEnabled(true);
}

void ResultsWidget::showResults(Query query, ResultSet results) {
    unsigned int index = 0;
    
    for(auto it = boxes.begin(); it != boxes.end(); it++) {
        (*it)->hide();
    }
    if(results.getTotal() == 0) {
        results_total->setText("No results for \"" + QString::fromStdString(query.getName()) + "\".");
    }
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getTotal() == 9);

    for(auto it = boxes.begin(); it != boxes.end(); it++) {
        grid->addWidget(*it, index / 3, index % 3);
        (*it)->show();
        index++;
    }
}

const QVector<BoxWidget*>& ResultsWidget::getBoxes() const {
    return boxes;
}
