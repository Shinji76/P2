#ifndef VIEW_SEARCH_WIDGET_H
#define VIEW_SEARCH_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>

#include "../Engine/Query.h"

class SearchWidget: public QWidget {
Q_OBJECT
private:
	QLineEdit* name_filter;     //string
    QComboBox* mana_filter;     //int
    QComboBox* type_filter;     //string/enum
    QComboBox* sorting_type;    //int
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
