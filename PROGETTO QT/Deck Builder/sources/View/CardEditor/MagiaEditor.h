#ifndef MAGIA_EDITOR_SIMPLE_H
#define MAGIA_EDITOR_SIMPLE_H

#include "AbstractCardEditor.h"

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class SimpleEditor: public AbstractCardEditor {
private:
    QLineEdit* sku_input;
    QSpinBox* availability_input;
    QDoubleSpinBox* price_input;

public:
    SimpleEditor(QWidget* parent = 0);
    virtual ~SimpleEditor();
    virtual AbstractCard* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const override;

    void setValues(const Magia& simple);
};

#endif