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
#include "WidgetLookup.h"

class ResultsWidget: public QWidget {
Q_OBJECT
private:
	QLabel* results_total;
	QPushButton* previous_page;
	QPushButton* next_page;
	QVector<WidgetLookup> lookup;
	QGridLayout* grid;
	ResultRenderer::IResultRendererStrategy* renderer;

public:
	explicit ResultsWidget(QWidget* parent = 0);
  
signals:
	void refreshResults();
	void previousPage();
	void nextPage();
	void addCard(const AbstractCard* card);
	void removeCard(const AbstractCard* card);

public slots:
	void showResults(Query query, ResultSet results);
};

#endif