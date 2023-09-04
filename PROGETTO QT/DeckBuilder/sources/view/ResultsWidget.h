#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QVector>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "../Engine/Query.h"
#include "../Engine/ResultSet.h"
#include "CardLayout/BoxWidget.h"

class BoxWidget;

class ResultsWidget: public QWidget {
Q_OBJECT
private:
    QLabel* results_total;
	QPushButton* previous_page;
	QPushButton* next_page;
    QVector<const BoxWidget*> boxes;
	QGridLayout* grid;

public:
	explicit ResultsWidget(QWidget* parent = 0);

    const QVector<const BoxWidget*>& getBoxes() const;

signals:
	void refreshResults();
	void previousPage();
	void nextPage();

public slots:
	void showResults(Query query, ResultSet results);
};

#endif
