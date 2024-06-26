#pragma once

#include <QFileSystemModel>
#include <QSortFilterProxyModel>
#include <QDebug>

class SeerDirectoryFilterProxyModel : public QSortFilterProxyModel {

    bool filterAcceptsRow (int sourceRow, const QModelIndex& sourceParent) const {

        QFileSystemModel* fileModel = qobject_cast<QFileSystemModel*>(sourceModel());

        QFileInfo file(fileModel->filePath(sourceModel()->index(sourceRow, 0, sourceParent)));

        if (file.isDir() == true || file.isHidden()) {
            return true;
        }else{
            return false;
        }
    }
};

