#ifndef _QTABBAREXTENDED_H_
#define _QTABBAREXTENDED_H_

#include <QTabBar>
#include <QTabWidget>
#include <QLineEdit>
#include <QEvent>
#include <QKeyEvent>
#include <utility>

#include "base/LibCfg.h"

class DLL_DECL_SPEC CancelEditFilter : public QObject
{
Q_OBJECT

public:
    explicit CancelEditFilter(QLineEdit* lineEdit, QString previousText) : QObject(lineEdit), m_lineEdit(lineEdit), m_previousText(std::move(previousText))
    {
    }

protected:
    bool eventFilter(QObject* object, QEvent* event) override
    {
        bool CancelRequested = false;

        // Cancel editing when 'ESC' is pressed
        if (event->type() == QEvent::KeyPress)
        {
            auto keyEvent = dynamic_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                CancelRequested = true;
            }
        }

        // Cancel editing if requested
        if( CancelRequested )
        {
            m_lineEdit->setText(m_previousText);
            m_lineEdit->clearFocus();
            m_lineEdit->close();
            return true;
        }

        return QObject::eventFilter(object, event);
    }

private:
    QLineEdit* m_lineEdit;
    QString m_previousText;
};


class DLL_DECL_SPEC QTabBarExtended: public QTabBar
{
Q_OBJECT

public:
    explicit QTabBarExtended(QTabWidget *parent = nullptr);

signals:
    void NewTabRequested();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

protected slots:

private:
    QTabWidget *parentTabWidget;
    QLineEdit *currTabEdit;
    QString currTabEditInitialText;
    int currTabEditIndex;
};


#endif //_QTABBAREXTENDED_H_
