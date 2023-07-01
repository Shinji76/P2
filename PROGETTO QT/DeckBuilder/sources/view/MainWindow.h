#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include "../Cards/Repository/JsonRepository.h"
#include "../Cards/Repository/JsonAlbumRepository.h"
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
    JsonRepository* repository;
    JsonAlbumRepository* album_repository;
    SearchWidget* search_widget;
    RecapWidget* recap_widget;
    QStackedWidget* stacked_widget;
    ResultsWidget* results_widget;
    HomeWidget* home_widget;
    ClassSelectionWidget* class_selection_widget;
    void clearStack();

public:
    explicit MainWindow(Memory& engine, QWidget *parent = 0);
    JsonRepository* getRepository();
    JsonAlbumRepository* getAlbumRepository();
    Memory& getEngine();
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();

public slots:
    void newDeck();
    void openDeck();
    void saveDeck();
    void saveDeckAs();
    void search(Query query);
    void close();
};

#endif