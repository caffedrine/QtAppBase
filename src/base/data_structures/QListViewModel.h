#ifndef _QLISTVIEWMODEL_H_
#define _QLISTVIEWMODEL_H_

#include <QAbstractListModel>
#include <QListView>
#include <QStringList>

#include "base/LibCfg.h"

// Subclass QAbstractListModel to represent the text data
class DLL_DECL_SPEC QListViewModel : public QAbstractListModel
{
public:
    QListViewModel(const QStringList &lines, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    QStringList mLines;
};


#endif //_QLISTVIEWMODEL_H_
