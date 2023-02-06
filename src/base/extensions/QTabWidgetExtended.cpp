#include "QTabWidgetExtended.h"
#include "QTabBarExtended.h"
#include <QMouseEvent>
#include <QFile>

QTabWidgetExtended::QTabWidgetExtended(QWidget *parent) : QTabWidget(parent)
{
    // Set a custom bar
    this->setTabBar(new QTabBarExtended(this));

    QObject::connect(this->tabBar(), SIGNAL(NewTabRequested()), this, SIGNAL(NewTabRequested()));

    this->setTabsClosable(true);

    // Load custom style for this QTabWidget
    QFile file(QStringLiteral(":/extensions/styles/QTabWidgetExtendedStyle.qss"));
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        this->setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }
    this->ensurePolished();
}

void QTabWidgetExtended::RequestNewTab()
{
    emit this->NewTabRequested();
}
