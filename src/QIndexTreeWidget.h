#pragma once

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QItemDelegate>
#include <QString>

class QIndexTreeWidget : public QTreeWidget {

    public:
        QIndexTreeWidget(QWidget* parent = nullptr);
       ~QIndexTreeWidget();

        QTreeWidgetItem*        getItemFromIndex            (const QModelIndex& index) const;
};

