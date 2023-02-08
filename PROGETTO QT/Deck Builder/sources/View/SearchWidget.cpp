#include "SearchWidget.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

SearchWidget::SearchWidget(QWidget* parent) : QWidget(parent) {
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* title_label = new QLabel("Deck Builder");
    title_label->setObjectName("title");
    title_label->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(title_label);

    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    query_input = new QLineEdit();
    form->addRow("Filtro ricerca", query_input);

    numeric_filter_input = new QSpinBox();
    numeric_filter_input->setMinimum(0);
    numeric_filter_input->setSingleStep(1);
    numeric_filter_input->setMaximum(10);
    form->addRow("Costo Mana", page_input);

    page_input = new QSpinBox();
    page_input->setMinimum(1);
    page_input->setSingleStep(1);
    page_input->setValue(1);
    form->addRow("Pagina", page_input);

    QPushButton* search_input = new QPushButton(
        QIcon(QPixmap((":/Assets/Icons/search.svg"))),
        "Avvia ricerca"
    );
    vbox->addWidget(search_input);

    // Connects signals
    connect(search_input, &QPushButton::clicked, this, &SearchWidget::search);
}

void SearchWidget::search() {
    Query query(
        query_input->text().toStdString(),
        filter_input->text().toStdString(),
        numeric_filter_input->value(),
        (page_input->value() - 1) * page_size->value(),
        page_size->value()
    );
    emit search_event(query);
}

void SearchWidget::previousPage() {
    if (page_input->value() > 1) {
        page_input->setValue(page_input->value() - 1);
        search();
    }
}

void SearchWidget::nextPage() {
    page_input->setValue(page_input->value() + 1);
    search();
}
