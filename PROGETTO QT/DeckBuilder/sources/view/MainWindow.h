#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../Cards/DataMapper/JsonFile.h"
#include "../Cards/DataMapper/JsonFileAlbum.h"
#include "../Engine/Query.h"
#include "../Engine/Memory.h"

#include "HomeWidget.h"
#include "ClassSelectionWidget.h"
#include "SearchWidget.h"
#include "ResultsWidget.h"
#include "RecapWidget.h"

#include <QSplitter>
#include <QMainWindow>
#include <QStackedWidget>

class MainWindow: public QMainWindow {
    Q_OBJECT
private:
    bool has_unsaved_changes;
    QAction* create_deck;
    Memory engine;
    Mazzo mazzo;
    JsonFile* deck_repository;
    JsonFileAlbum* album_repository;
    QStackedWidget* stacked_widget;
    QSplitter* splitter;
    QWidget* container;
    HomeWidget* home_widget;
    ClassSelectionWidget* class_selection_widget;
    ResultsWidget* results_widget;
    SearchWidget* search_widget;
    RecapWidget* recap_widget;
    void clearStack();
    
public:
    explicit MainWindow(Memory& engine, QWidget *parent = 0);
    JsonFile* getDeckRepository();
    JsonFileAlbum* getAlbumRepository();
    Memory& getEngine();
    SearchWidget* getSearchWidget();

signals:
    void addCardRecapEmitter(const AbstractCard* card);
    void removeCardRecapEmitter(const AbstractCard* card);
    void updateTotalDeck(const unsigned int total);

public slots:
    //ricevitore segnali
    void setClass(AbstractCard::Classe classe);
    void addCard(const AbstractCard* card);
    void removeCard(const AbstractCard* card);
    void addCardRecap(QString button_name);     //implementare cpp 
    void removeCardRecap(QString button_name);
    void createTable();

    void newDeck();
    void openDeck();
    void saveDeck();
    void saveDeckAs();
    void search(Query query);
    void close();
};

#endif