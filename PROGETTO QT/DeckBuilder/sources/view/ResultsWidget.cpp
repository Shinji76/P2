#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

ResultsWidget::ResultsWidget(QWidget* parent) : QWidget(parent) {

    QVBoxLayout* main_layout = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();
    grid = new QGridLayout();
    grid->setSpacing(1);

    previous_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/left_arrow.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap(":/Assets/Icons/right_arrow.svg")), "");
    next_page->setEnabled(false);
    hbox->addWidget(next_page);
    
    main_layout->addLayout(hbox);
    main_layout->addLayout(grid);
    
    setLayout(main_layout);

    connect(next_page, SIGNAL(clicked()), this, SLOT(showNextPage()));
    connect(previous_page, SIGNAL(clicked()), this, SLOT(showPreviousPage()));    
}

void ResultsWidget::createBoxes(std::vector<const AbstractCard*> cards) {
    for(auto it = cards.begin(); it != cards.end(); it++) {
        BoxWidget* new_box = new BoxWidget(*it, this);
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
    page_index = 1;
    previous_page->setEnabled(false);
    next_page->setEnabled(true);
}

void ResultsWidget::showNextPage() {
    unsigned int index = 0;

    for(auto it = boxes.begin(); it != boxes.end(); it++) {
        (*it)->hide();
    }

    for(auto it = boxes.begin() + page_index*9; index < 9; it++) {
        if(it != boxes.end()) {
            (*it)->show();
            grid->addWidget(*it, index / 3, index % 3);
        }
        else {
            for(; index < 9; index++) {
            QSpacerItem* emptySpace = new QSpacerItem(150, 150);
            grid->addItem(emptySpace, index / 3, index % 3);
            }
        }
        index++;
    }

    page_index++;
    if( (boxes.size() - page_index*9) > 0) {
        next_page->setEnabled(true);
    } else {
        next_page->setEnabled(false);
    }
    previous_page->setEnabled(true);
}

void ResultsWidget::showPreviousPage() {
    int index = 0;
    page_index = page_index-2;

    for(auto it = boxes.begin(); it != boxes.end(); it++) {
        (*it)->hide();
    }
    for(auto it = boxes.begin() + page_index*9; index < 9; it++) {
        if(*it) {
            (*it)->show();
            grid->addWidget(*it, index / 3, index % 3);
        }
        index++;
    }

    if(page_index == 0) {
        previous_page->setEnabled(false);
    }
    page_index++;
    next_page->setEnabled(true);
}

void ResultsWidget::clear() {
    for (BoxWidget* box : boxes) {
        disconnect(box->getRemoveButton(), 0, 0, 0);
        disconnect(box->getAddButton(), 0, 0, 0);

        delete box;
    }

    boxes.clear();
}

const QVector<BoxWidget*>& ResultsWidget::getBoxes() const {
    return boxes;
}
