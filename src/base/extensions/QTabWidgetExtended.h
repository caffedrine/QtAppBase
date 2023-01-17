#ifndef _QTABWIDGETEXTENDED_H_
#define _QTABWIDGETEXTENDED_H_

#include <QTabWidget>

#include "base/LibCfg.h"

class DLL_DECL_SPEC QTabWidgetExtended: public QTabWidget
{
    Q_OBJECT
public:
    explicit QTabWidgetExtended(QWidget *parent = nullptr);

signals:
    void NewTabRequested();
};


#endif //_QTABWIDGETEXTENDED_H_
