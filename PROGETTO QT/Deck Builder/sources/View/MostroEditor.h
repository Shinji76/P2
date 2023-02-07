#ifndef MOSTRO_EDITOR_SIMPLE_H
#define MOSTRO_EDITOR_SIMPLE_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

#include "AbstractCardEditor.h"

class MostroEditor: public AbstractCardEditor {
private:
	QLineEdit* sku_input;
    QSpinBox* availability_input;
    QDoubleSpinBox* price_input;

public:
    MostroEditor(QWidget* parent = 0);
    virtual ~MostroEditor();
    virtual AbstractCard* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const override;

    void setValues(const Mostro& mostro);
};

#endif