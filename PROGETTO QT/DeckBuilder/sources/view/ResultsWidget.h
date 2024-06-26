#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QVector>
#include <QObject>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "../Engine/ResultSet.h"
#include "CardLayout/BoxWidget.h"

class ResultsWidget: public QWidget {
Q_OBJECT
private:
    int page_index;
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
    void clear();
    void showInitialResults();
    void showNextPage();
    void showPreviousPage();
    void createBoxes(std::vector<const AbstractCard*> cards);

};
#endif
