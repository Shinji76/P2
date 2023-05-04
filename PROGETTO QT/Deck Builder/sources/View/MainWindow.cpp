#include "MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QSplitter>
#include <QFileDialog>
#include <QStackedWidget>
#include <QScrollArea>

#include "../Cards/DataMapper/JsonFile.h"
#include "../Cards/JSONConverter/Reader.h"
#include "../Cards/JSONConverter/Json.h"

//Sistemare IEngine&
MainWindow::MainWindow(Memory& engine, QWidget *parent)
    : QMainWindow(parent), has_unsaved_changes(false), engine(engine), repository(nullptr) {
    // Actions
    QAction* create = new QAction(
        QIcon(QPixmap((":/Assets/Icons/new.svg"))),
        "New Deck"
    ); 
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    QAction* open = new QAction(
        QIcon(QPixmap((":/Assets/Icons/open.svg"))),
        "Open Deck"
    );
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    QAction* save = new QAction(
        QIcon(QPixmap((":/Assets/Icons/save.svg"))),
        "Save"
    );
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    QAction* save_as = new QAction(
        QIcon(QPixmap((":/Assets/Icons/save_as.svg"))),
        "Save As"
    );
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

    QAction* close = new QAction(
        QIcon(QPixmap((":/Assets/Icons/close.svg"))),
        "Close"
    );
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));

    // Sets menu bar
    QMenu* file = menuBar()->addMenu("&File");
    file->addAction(create);
    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addSeparator();
    file->addAction(close);

    // Sets main panel
    QSplitter* splitter = new QSplitter(this);
    setCentralWidget(splitter);

    search_widget = new SearchWidget();
    splitter->addWidget(search_widget);

    stacked_widget = new QStackedWidget(this);
    splitter->addWidget(stacked_widget);

    results_widget = new ResultsWidget();
    stacked_widget->addWidget(results_widget);

    splitter->setSizes(QList<int>() << 1000 << 3000);

    // Connects signals
    connect(create, &QAction::triggered, this, &MainWindow::newDeck);
    connect(open, &QAction::triggered, this, &MainWindow::openDeck);
    connect(save, &QAction::triggered, this, &MainWindow::saveDeck);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveDeckAs);
    connect(close, &QAction::triggered, this, &MainWindow::close);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(results_widget, &ResultsWidget::refreshResults, search_widget, &SearchWidget::search);
    connect(results_widget, &ResultsWidget::previousPage, search_widget, &SearchWidget::previousPage);
    connect(results_widget, &ResultsWidget::nextPage, search_widget, &SearchWidget::nextPage);
    connect(results_widget, &ResultsWidget::addCard, this, &MainWindow::addCard);
    connect(results_widget, &ResultsWidget::removeCard, this, &MainWindow::removeCard);

    // Status bar
    showStatus("Ready.");
}

Item::Repository::JsonRepository* MainWindow::getRepository() {
    return repository;
}

Engine::IEngine& MainWindow::getEngine() {
    return engine;
}

MainWindow& MainWindow::reloadData() {
    engine.clear();
    std::vector<AbstractCard*> cards(repository->readAll());
    for (auto cit = cards.begin(); cit != cards.end(); cit++) {
        engine.add(*cit);
    }
    return *this;
}

SearchWidget* MainWindow::getSearchWidget() {
    return search_widget;
}

void MainWindow::clearStack() {
    QWidget* widget = stacked_widget->widget(1);
    while (widget) {
        stacked_widget->removeWidget(widget);
        delete widget;
        widget = stacked_widget->widget(1);
    }
}


void MainWindow::newDeck() {
    QString path = QFileDialog::getSaveFileName (
        this,
        "Creates new Deck",  
        "./",
        "JSON files *.json"     //tipo file salvataggio
    );
    if (path.isEmpty()) {
        return;
    }
    if (repository != nullptr) {
        delete repository;
    }
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path.toStdString(), converter);
    repository = new JsonRepository(data_mapper);
    engine.clear();
}

void MainWindow::openDeck() {
    QString path = QFileDialog::getOpenFileName (
        this,
        "Creates new Deck",
        "./",
        "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }
    if (repository != nullptr) {
        delete repository;
    }
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path.toStdString(), converter);
    repository = new JsonRepository(data_mapper);
    reloadData();
    create_item->setEnabled(true);
}

void MainWindow::saveDeck() {
    if (repository == nullptr) {
        return;
    }
    repository->store();
    has_unsaved_changes = false;
}

void MainWindow::saveAsDeck() {
    QString path = QFileDialog::getSaveFileName(
        this,
        "Creates new Deck",
        "./",
        "JSON files *.json"
    );
    if (path.isEmpty() || repository == nullptr) {
        return;
    }
    repository->setPath(path.toStdString()).store();
    has_unsaved_changes = false;
}

void MainWindow::search(Query query) {
    results_widget->showResults(query, engine.search(query));
    stacked_widget->setCurrentIndex(0);
    clearStack();
}

void MainWindow::close() {
    if (has_unsaved_changes) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
            this, "Quit?", "There are unsaved changes.\nDo you really want to quit?",
            QMessageBox::Yes | QMessageBox::No
        );
        if (confirmation == QMessageBox::Yes) {
            QApplication::quit();
        }
    }
    else {
        QApplication::quit();
    }
}
