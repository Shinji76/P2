#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include "../Cards/Repository/JsonRepository.h"
#include "../Engine/Query.h"
#include "../Engine/Memory.h"
#include "SearchWidget.h"
#include "ResultsWidget.h"
#include "RecapWidget.h"
#include "CardRenderer/Full.h"

#include <QMainWindow>
#include <QStackedWidget>

namespace View {

class MainWindow: public QMainWindow {
    Q_OBJECT
private:
    bool has_unsaved_changes;
    QAction* create_deck;
    Memory engine;
    JsonRepository* repository;
    SearchWidget* search_widget;
    RecapWidget* recap_widget;
    QStackedWidget* stacked_widget;
    ResultsWidget* results_widget;
    ItemRenderer::Full full_renderer;
  
public:
    explicit MainWindow(Memory& engine, QWidget *parent = 0);
    JsonRepository* getRepository();
    Memory& getEngine();
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();
  
private:
    void clearStack();

 public slots:
    void newDataset();
    void openDataset();
    void saveDataset();
    void saveAsDataset();
    void showStatus(QString message);
    void search(Query query);
    void addCard(const AbstractCard* card);
    void removeCard(const AbstractCard* card);
    void showCard(const AbstractCard* card) const;
    void close();
};

}

#endif