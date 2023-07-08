#ifndef RECAPWIDGET_H
#define RECAPWIDGET_H

#include "lookupwidget.h" 

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <vector>

class RecapWidget : public QWidget {
    Q_OBJECT

private:
    QTableView* tableView;
    std::vector<LookupWidget> cells;

public:
    RecapWidget(QWidget* parent = nullptr);

    void addCell(LookupWidget* lookpup);
    void removeCell(int index);

};

#endif // RECAPWIDGET_H
