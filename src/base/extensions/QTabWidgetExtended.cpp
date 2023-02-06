#include "QTabWidgetExtended.h"
#include "QTabBarExtended.h"
#include <QMouseEvent>

QTabWidgetExtended::QTabWidgetExtended(QWidget *parent) : QTabWidget(parent)
{
    // Set a custom bar
    this->setTabBar(new QTabBarExtended(this));

    QObject::connect(this->tabBar(), SIGNAL(NewTabRequested()), this, SIGNAL(NewTabRequested()));

    this->setTabsClosable(true);
}

void QTabWidgetExtended::RequestNewTab()
{
    emit this->NewTabRequested();
}
