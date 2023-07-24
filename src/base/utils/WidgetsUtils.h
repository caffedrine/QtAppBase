#ifdef QT_WIDGETS_ENABLED

#ifndef _WIDGETSUTILS_H_
#define _WIDGETSUTILS_H_

#include <QPushButton>

namespace utils { namespace widgets
{
DLL_DECL_SPEC void Utils_PushButtonStartLoading(QPushButton *button);
DLL_DECL_SPEC void Utils_PushButtonEndLoading(QPushButton *button);
}} // Namespaces

#endif //_WIDGETSUTILS_H_

#endif