#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include "../Cards/DataMapper/JsonFile.h"
#include "../Cards/DataMapper/JsonFileAlbum.h"
#include "../Engine/Query.h"
#include "../Engine/Memory.h"

#include "HomeWidget.h"
#include "ClassSelectionWidget.h"
#include "SearchWidget.h"
#include "ResultsWidget.h"
#include "RecapWidget.h"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow: public QMainWindow {
    Q_OBJECT
private:
    bool has_unsaved_changes;
    QAction* create_deck;
    Memory engine;
    JsonFile* repository;
    JsonFileAlbum* album_repository;
    SearchWidget* search_widget;
    RecapWidget* recap_widget;
    QStackedWidget* stacked_widget;
    ResultsWidget* results_widget;
    HomeWidget* home_widget;
    ClassSelectionWidget* class_selection_widget;
    void clearStack();

public:
    explicit MainWindow(Memory& engine, QWidget *parent = 0);
    JsonFile* getRepository();
    JsonFileAlbum* getAlbumRepository();
    Memory& getEngine();
    SearchWidget* getSearchWidget();

public slots:
    void setClass(AbstractCard::Classe classe);
    void newDeck();
    void openDeck();
    void saveDeck();
    void saveDeckAs();
    void search(Query query);
    void close();
};

#endif