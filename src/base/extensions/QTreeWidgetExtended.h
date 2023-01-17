#ifndef _QTREEWIDGETEXTENDED_H_
#define _QTREEWIDGETEXTENDED_H_

#include <QTreeWidget>

#include "base/LibCfg.h"

class DLL_DECL_SPEC QTreeWidgetExtended: public QTreeWidget
{
Q_OBJECT

public:
    QTreeWidgetExtended(QWidget* parent = nullptr);

protected:
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // _QTREEWIDGETEXTENDED_H_
