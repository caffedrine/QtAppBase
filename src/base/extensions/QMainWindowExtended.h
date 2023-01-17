#ifndef _QMAINWINDOWEXTENDED_H_
#define _QMAINWINDOWEXTENDED_H_

#include <QMainWindow>
#include <QEventLoop>
#include <QWidget>

#include "base/LibCfg.h"

class DLL_DECL_SPEC QMainWindowExtended: public QMainWindow
{
    Q_OBJECT
public:
    QMainWindowExtended(QWidget *parent = nullptr);
    ~QMainWindowExtended();

    void exec();

protected:

private:

};

#endif // _QMAINWINDOWEXTENDED_H_