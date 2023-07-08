#ifndef VIEW_RESULTS_WIDGET_H
#define VIEW_RESULTS_WIDGET_H

#include <QVector>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "../Engine/Query.h"
#include "../Engine/ResultSet.h"
#include "ResultLayout/IResultLayoutStrategy.h"
#include "LookupWidget.h"

class ResultsWidget: public QWidget {
Q_OBJECT
private:
    QLabel* results_total;
	QPushButton* previous_page;
	QPushButton* next_page;
    QVector<LookupWidget> lookup;
	QGridLayout* grid;

public:
	explicit ResultsWidget(QWidget* parent = 0);

signals:
	void refreshResults();
	void previousPage();
	void nextPage();
	void addCard(const int mana);
	void removeCard(const int mana);
    void enableLoookupAdd();
    void disableLoookupAdd();
    void enableLoookupRemove();
    void disableLoookupRemove();

public slots:
	void showResults(Query query, ResultSet results);
};

#endif
