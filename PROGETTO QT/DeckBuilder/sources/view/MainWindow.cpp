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
#include "../Cards/JSONConverter/JsonAlbum.h"

//Sistemare IEngine&
MainWindow::MainWindow(Memory& engine, QWidget *parent)
    : QMainWindow(parent), has_unsaved_changes(false), engine(engine), deck_repository(nullptr) {
    // Actions
    QAction* create = new QAction("New Deck"); 
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    QAction* open = new QAction("Open Deck");
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    QAction* save = new QAction("Save");
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    QAction* save_as = new QAction("Save As");
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

    QAction* close = new QAction("Close");
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
    stacked_widget = new QStackedWidget(this);
    setCentralWidget(stacked_widget);
    
    home_widget = new HomeWidget(this);
    stacked_widget->addWidget(home_widget);

    class_selection_widget = new ClassSelectionWidget(this);
    stacked_widget->addWidget(class_selection_widget);

    container = new QWidget(this);
    QHBoxLayout* hbox = new QHBoxLayout(container);
    
    results_widget = new ResultsWidget(container);
    results_widget->setMinimumWidth(700);
    hbox->addWidget(results_widget);
    
    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    search_widget = new SearchWidget(this);
    search_widget->setMaximumWidth(400);
    vbox->addWidget(search_widget);

    recap_widget = new RecapWidget(this);
    recap_widget->setMaximumWidth(400);
    vbox->addWidget(recap_widget);

    stacked_widget->addWidget(container);
    
    // Connects signals
    connect(create, &QAction::triggered, this, &MainWindow::newDeck);
    connect(open, &QAction::triggered, this, &MainWindow::openDeck);
    connect(save, &QAction::triggered, this, &MainWindow::saveDeck);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveDeckAs);
    connect(close, &QAction::triggered, this, &MainWindow::close);
    connect(home_widget, &HomeWidget::createDeck, this, &MainWindow::newDeck);
    connect(home_widget, &HomeWidget::openDeck, this, &MainWindow::openDeck);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(results_widget, &ResultsWidget::previousPage, search_widget, &SearchWidget::previousPage);
    connect(results_widget, &ResultsWidget::nextPage, search_widget, &SearchWidget::nextPage);
    connect(this, SIGNAL(addCardRecapEmitter(const AbstractCard*)), this, SLOT(addCard(const AbstractCard*)), Qt::UniqueConnection);
    connect(this, SIGNAL(removeCardRecapEmitter(const AbstractCard*)), this, SLOT(removeCard(const AbstractCard*)), Qt::UniqueConnection);
    connect(this, SIGNAL(updateTotalDeck(const unsigned int)), recap_widget, SLOT(UpdateTotal(const unsigned int)), Qt::UniqueConnection);
}

JsonFile* MainWindow::getDeckRepository() {
    return deck_repository;
}

JsonFileAlbum* MainWindow::getAlbumRepository() {
    return album_repository;
}

Memory& MainWindow::getEngine() {
    return engine;
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

void MainWindow::setClass(AbstractCard::Classe classe) {
    mazzo.setClasse(classe);
    // apertura album filtrato
    Reader reader_album;
    JsonAlbum converter_album(reader_album);
    album_repository = new JsonFileAlbum((":/Assets/Album.json"), converter_album);
    engine = album_repository->loadClass(mazzo.getClasse()); //std::vector con classe filtrata
    results_widget->createBoxes(engine.getMemory());

    stacked_widget->setCurrentWidget(container);
}

void MainWindow::addCard(const AbstractCard* card) {
    if(mazzo.getNumCopie()[card->getID()] == 0) {
        mazzo.addCard(card->getID());
        recap_widget->addRow(card, mazzo.getNumCopie()[card->getID()]);
    } else {
        mazzo.addCard(card->getID());
        recap_widget->updateRow(QString::fromStdString(card->getNome()), mazzo.getNumCopie()[card->getID()]);
    }   

    //abilito bottone remove card
    results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(true);
    recap_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(true);

    if(mazzo.getCounter() == 20) {
        for(auto it = results_widget->getBoxes().begin(); it != results_widget->getBoxes().end(); it++) {
            (*it)->getAddButton()->setEnabled(false);
        }
        
        for(int i = 0; i < mazzo.getNumCopie().getSize(); i++) {
            if(mazzo.getNumCopie()[i] != 0) {
                recap_widget->findChild<QPushButton*>(QString::number(i) + '+')->setEnabled(false);
            }
        }
    }

    if( (card->getRarita() == 3) || (mazzo.getNumCopie()[card->getID()] == 2) ) {     // Rarita 3 = Leggendaria
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(false);
        recap_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(false);
    }
    emit updateTotalDeck(mazzo.getCounter());
    has_unsaved_changes = true;
}

void MainWindow::removeCard(const AbstractCard* card) {
    mazzo.removeCard(card->getID());

//    if(mazzo.getCounter() == 19) {
//        for()
//    }
    
    if(mazzo.getNumCopie()[card->getID()] == 0) {
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(false);
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(true);
        recap_widget->deleteRow(QString::fromStdString(card->getNome()));
    } else {
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(true);
        recap_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(true);
        recap_widget->updateRow(QString::fromStdString(card->getNome()), mazzo.getNumCopie()[card->getID()]);
    }
    emit updateTotalDeck(mazzo.getCounter());
    has_unsaved_changes = true;
}

void MainWindow::addCardRecap(QString button_name) {
    button_name.chop(1);
    int tmp_id = button_name.toInt();
    emit addCardRecapEmitter(engine.getCardFromID(tmp_id));
}

void MainWindow::removeCardRecap(QString button_name) {
    button_name.chop(1);
    int tmp_id = button_name.toInt();
    emit removeCardRecapEmitter(engine.getCardFromID(tmp_id));
}

void MainWindow::newDeck() {
    QString path = QFileDialog::getSaveFileName(this, "Creates new Deck", "./", "JSON files *.json");
    if (path.isEmpty()) {
        return;
    }
    if(home_widget) {
        stacked_widget->removeWidget(home_widget);
        delete home_widget;
    }
    if (deck_repository != nullptr) {
        delete deck_repository;
    }

    stacked_widget->setCurrentWidget(class_selection_widget);    

    deck_repository = new JsonFile(path.toStdString());
}

void MainWindow::openDeck() {
    QString path = QFileDialog::getOpenFileName(this, "Open existing Deck", "./", "JSON files *.json");  
    if (path.isEmpty()) {
        return;
    }
    if(home_widget) {
        stacked_widget->removeWidget(home_widget);
        delete home_widget;
    }
    if (deck_repository != nullptr) {
        delete deck_repository;
    }

    stacked_widget->setCurrentWidget(container);

    deck_repository = new JsonFile(path.toStdString());
    mazzo = deck_repository->load();

    Reader reader_album;
    JsonAlbum converter_album(reader_album);
    album_repository = new JsonFileAlbum((":/Assets/Album.json"), converter_album);
    engine = album_repository->loadClass(mazzo.getClasse());
    results_widget->createBoxes(engine.getMemory());
    createTable();
}

void MainWindow::createTable() {
    for(int i = 0; i < mazzo.getNumCopie().getSize(); i++) {

        if(mazzo.getNumCopie()[i] != 0) {    
            const AbstractCard *tmp_card = engine.getCardFromID(i);
            recap_widget->addRow(tmp_card, mazzo.getNumCopie()[i]);
            
            // Rarita 3 = Leggendaria
            if( (tmp_card->getRarita() == 3) || (mazzo.getNumCopie()[i] == 2) ) {     
                recap_widget->findChild<QPushButton*>(QString::number(i) + '+')->setEnabled(false);
                recap_widget->findChild<QPushButton*>(QString::number(i) + '-')->setEnabled(true);
            }
            else {
                recap_widget->findChild<QPushButton*>(QString::number(i) + '+')->setEnabled(true);
                recap_widget->findChild<QPushButton*>(QString::number(i) + '-')->setEnabled(true);
            }
        }
    }
}

void MainWindow::saveDeck() {
    if (deck_repository == nullptr) {
        return;
    }
    deck_repository->store(mazzo);
    has_unsaved_changes = false;
}

void MainWindow::saveDeckAs() {
    QString path = QFileDialog::getSaveFileName(this, "Creates new Deck", "./", "JSON files *.json");
    if (path.isEmpty() || deck_repository == nullptr) {
        return;
    }
    deck_repository->setPath(path.toStdString()).store(mazzo);
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
