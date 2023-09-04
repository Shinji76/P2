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

#include "../Cards/Album.h"
#include "../Cards/DataMapper/JsonFile.h"
#include "../Cards/JSONConverter/Reader.h"
#include "../Cards/JSONConverter/JsonAlbum.h"

//Sistemare IEngine&
MainWindow::MainWindow(Memory& engine, QWidget *parent)
    : QMainWindow(parent), has_unsaved_changes(false), engine(engine), deck_repository(nullptr) {
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
    splitter = new QSplitter(this);
    setCentralWidget(splitter);

    QStackedWidget* stacked_widget = new QStackedWidget(this);
    splitter->addWidget(stacked_widget);
    
    home_widget = new HomeWidget(this);
    stacked_widget->addWidget(home_widget);

    class_selection_widget = new ClassSelectionWidget(this);
    stacked_widget->addWidget(class_selection_widget);

    search_widget = new SearchWidget(this);
    splitter->addWidget(search_widget);
    search_widget->hide();

    recap_widget = new RecapWidget(this);
    splitter->addWidget(recap_widget);
    recap_widget->hide();

    results_widget = new ResultsWidget(this);
    splitter->addWidget(results_widget);
    results_widget->hide();


    splitter->setSizes(QList<int>() << 3000 << 0);
    
    // Connects signals
    connect(create, &QAction::triggered, this, &MainWindow::newDeck);
    connect(open, &QAction::triggered, this, &MainWindow::openDeck);
    connect(save, &QAction::triggered, this, &MainWindow::saveDeck);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveDeckAs);
    connect(close, &QAction::triggered, this, &MainWindow::close);
    //connect(home_widget, &HomeWidget::createDeck, this, &MainWindow::newDeck);
    //connect(home_widget, &HomeWidget::openDeck, this, &MainWindow::openDeck);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(results_widget, &ResultsWidget::refreshResults, search_widget, &SearchWidget::search);      //valutare se mantenere refresh o al massimo cambiarlo
    connect(results_widget, &ResultsWidget::previousPage, search_widget, &SearchWidget::previousPage);
    connect(results_widget, &ResultsWidget::nextPage, search_widget, &SearchWidget::nextPage);
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
}

void MainWindow::addCard(AbstractCard* card) {
    //aggiungo carta a mazzo attraverso id
    mazzo.addCard(card->getID());

    //aggiungere riga a tabella RecapWidget
    if(mazzo.getNumCopie()[card->getID()] == 0) {
        recap_widget->addRow(card, mazzo.getNumCopie()[card->getID()]);
    } else {
        recap_widget->updateRow(QString::fromStdString(card->getNome()), mazzo.getNumCopie()[card->getID()]);
    }   

    //abilito bottone remove card
    results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(true);
    recap_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(true);

    //controllo mazzo, se pieno blocco tutti plus
    if(mazzo.getCounter() == 20) {
        //emit segnale disabilita tutti i plus
        for(auto it = results_widget->getBoxes().begin(); it != results_widget->getBoxes().end(); it++) {
            (*it)->getRemoveButton()->setEnabled(false);
        }
    }

    //controllo carta eventualmente blocco plus e abilito meno
    else if( (card->getRarita() == 3) || (card->getRarita() != 3 && mazzo.getNumCopie()[card->getID()] == 2) ) {     // Rarita 3 = Leggendaria
        //emit segnale disabilita plus per card
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(false);
        recap_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(false);
    }
}

void MainWindow::removeCard(AbstractCard* card) {
    //default removeButton bloccati
    mazzo.removeCard(card->getID());
    if(mazzo.getNumCopie()[card->getID()] == 0) {
        //emit segnale disabilita remove e abilito add, elimino riga recapWidget
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '-')->setEnabled(false);
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(true);
        recap_widget->deleteRow(QString::fromStdString(card->getNome()));
    } else {
        results_widget->findChild<QPushButton*>(QString::number(card->getID()) + '+')->setEnabled(true);
        recap_widget->updateRow(QString::fromStdString(card->getNome()), mazzo.getNumCopie()[card->getID()]);
    }
}

void MainWindow::newDeck() {
    QString path = QFileDialog::getSaveFileName (
        this,
        "Creates new Deck",  
        "./",
        "JSON files *.json"     
    );
    if (path.isEmpty()) {
        return;
    }
    if(home_widget) {
        delete home_widget;
    }
    if (deck_repository != nullptr) {
        delete deck_repository;      //se ho degli elementi nel deck_repository cancello il deck_repository
    }

    //creazione del mazzo
    deck_repository = new JsonFile(path.toStdString());

    // apertura album filtrato
    Reader reader_album;
    JsonAlbum converter_album(reader_album);
    album_repository = new JsonFileAlbum(path.toStdString(), converter_album);

    AbstractCard::Classe classe;
    setClass(classe);
    mazzo.setClasse(classe);
    album_repository->loadClass(classe); //restituito da classSelection
    
    if(!class_selection_widget) {   
        results_widget->show();
        search_widget->show();
        recap_widget->show();
    }

    splitter->setSizes(QList<int>() << 3000 << 1000);
}

void MainWindow::openDeck() {
    QString path = QFileDialog::getOpenFileName (
        this,
        "Open existing Deck",
        "./",
        "JSON files *.json"
    );  
    if (path.isEmpty()) {
        return;
    }
    if (deck_repository != nullptr) {
        delete deck_repository;
    }
    //engine.clear();
    //apertura mazzo
    deck_repository = new JsonFile(path.toStdString());
    mazzo = deck_repository->load();

    //apertura album filtrato
    Reader reader_album;
    JsonAlbum converter_album(reader_album);
    JsonFileAlbum json_album(path.toStdString(), converter_album);
    engine = json_album.loadClass(mazzo.getClasse());
    
}

void MainWindow::saveDeck() {
    if (deck_repository == nullptr) {
        return;
    }
    deck_repository->store(mazzo);    //passare mazzo 
    has_unsaved_changes = false;
}

void MainWindow::saveDeckAs() {
    QString path = QFileDialog::getSaveFileName(
        this,
        "Creates new Deck",
        "./",
        "JSON files *.json"
    );
    if (path.isEmpty() || deck_repository == nullptr) {
        return;
    }
    mazzo.setNomeMazzo(path.toStdString());
    deck_repository->setPath(path.toStdString()).store(mazzo);    //mazzo
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
