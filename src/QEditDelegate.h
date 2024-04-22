#pragma once

#include <QtWidgets/QItemDelegate>
#include <QtWidgets/QStyledItemDelegate>
#include <QModelIndex>

class QAllowEditDelegate : public QStyledItemDelegate {

    Q_OBJECT

    public:
        QAllowEditDelegate(QObject* parent = nullptr);

        virtual void        setModelData            (QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

    signals:
        void                editingStarted          (const QModelIndex& index) const;
        void                editingFinished         (const QModelIndex& index) const;
};

class QNoEditDelegate : public QStyledItemDelegate {

    public:
        QNoEditDelegate(QObject* parent = nullptr);

        virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};

