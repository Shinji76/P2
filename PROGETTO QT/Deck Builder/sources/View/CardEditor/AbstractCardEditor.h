#ifndef ABSTRACT_CARD_EDITOR_H
#define ABSTRACT_CARD_EDITOR_H

#include <QWidget>
#include <QString>

#include "../Cards/AbstractCard.h"

class AbstractCardEditor: public QWidget {
Q_OBJECT
public:
	AbstractCardEditor(QWidget* parent = 0);
	virtual ~AbstractCardEditor();
	
	virtual AbstractCard* create(
		const unsigned int identifier,
		const QString& name,
		const QString& description,
		const QString& image_path
	) const = 0;
};

#endif