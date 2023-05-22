#ifndef VIEW_SEARCH_WIDGET_H
#define VIEW_SEARCH_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>

#include "../Engine/Query.h"

class SearchWidget: public QWidget {
Q_OBJECT
private:
	QLineEdit* name_filter;
    QspinBox* mana_filter;
    QComboBox* type_filter;
	QSpinBox* page_input;

public:
	explicit SearchWidget(QWidget* parent = 0);

signals:
	void search_event(Query query);

public slots:
	void search();
	void previousPage();
	void nextPage();
};

#endif