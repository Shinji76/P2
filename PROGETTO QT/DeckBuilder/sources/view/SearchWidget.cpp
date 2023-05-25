#include "SearchWidget.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

SearchWidget::SearchWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* title_label = new QLabel("Deck Builder");
    title_label->setObjectName("title");
    title_label->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(title_label);

    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    name_filter = new QLineEdit();
    form->addRow("Nome", name_filter);

    mana_filter = new QComboBox();
    mana_filter->addItem("Tutti");
    mana_filter->addItem("0");
    mana_filter->addItem("1");
    mana_filter->addItem("2");
    mana_filter->addItem("3");
    mana_filter->addItem("4");
    mana_filter->addItem("5");
    mana_filter->addItem("6");
    mana_filter->addItem("7+");

    mana_filter->setCurrentText("Tutti");
    form->addRow("Costo Mana", mana_filter);


    type_filter = new QComboBox();
    type_filter->addItem("Tutti");
    type_filter->addItem("Mostro");
    type_filter->addItem("Magia");
    type_filter->addItem("Segreto");

    type_filter->setCurrentText("Tutti");
    form->addRow("Tipo Carta", type_filter);


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

    connect(search_input, &QPushButton::clicked, this, &SearchWidget::search);
}

//TODO: capire come sistemare search widget con la query corretta
void SearchWidget::search() {
    Query query(
        name_fiter->text().toStdString(),
        mana_filter->value(),
        type_filter->value(),           //può essere sbagliato rispetto a ìlle enum
        (page_input->value() - 1) * 9
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