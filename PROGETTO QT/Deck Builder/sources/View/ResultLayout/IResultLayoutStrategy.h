#ifndef I_RESULT_LAYOUT_STRATEGY_H
#define I_RESULT_LAYOUT_STRATEGY_H

#include <QGridLayout>

#include "../../Engine/ResultSet.h"
#include "../WidgetLookup.h"

class IResultLayoutStrategy {
public:
	virtual ~IResultLayoutStrategy() = default;
	virtual void render(QGridLayout* grid, ResultSet& result, QVector<WidgetLookup>* lookup) = 0;
};

#endif	//I_RESULT_LAYOUT_STRATEGY_H