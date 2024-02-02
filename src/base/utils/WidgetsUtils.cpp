#include "WidgetsUtils.h"

#ifdef QT_WIDGETS_ENABLED

#include <QMovie>

namespace utils { namespace widgets
{
static QMovie *movieLoadingIcon = nullptr;
void Utils_PushButtonStartLoading(QPushButton *button)
{
    if( movieLoadingIcon == nullptr )
    {
        movieLoadingIcon = new QMovie();
        movieLoadingIcon->setFileName(":/img/loading.gif");
        movieLoadingIcon->start();
    }

    button->setEnabled(false);
    QObject::connect(movieLoadingIcon, &QMovie::frameChanged, button, [button]
    {
        button->setIcon(movieLoadingIcon->currentPixmap());
    });
}

void Utils_PushButtonEndLoading(QPushButton *button)
{
    button->setIcon(QIcon());
    button->setEnabled(true);

    QObject::disconnect(movieLoadingIcon, &QMovie::frameChanged, button, nullptr);
}
}} // Namespaces
#endif