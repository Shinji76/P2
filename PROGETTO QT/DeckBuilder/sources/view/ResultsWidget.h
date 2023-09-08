#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QVector>
#include <QObject>
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
    QVector<BoxWidget*> boxes;
	QGridLayout* grid;

public:
	explicit ResultsWidget(QWidget* parent = 0);

    const QVector<BoxWidget*>& getBoxes() const;

signals:
	void previousPage();
	void nextPage();

public slots:
    void showInitialResults();
    void createBoxes(std::vector<const AbstractCard*> cards);
	void showResults(Query query, ResultSet results);
};

#endif
