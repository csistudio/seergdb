#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include "ui_SeerAdaTasksBrowserWidget.h"

class SeerAdaTasksBrowserWidget : public QWidget, protected Ui::SeerAdaTasksBrowserWidgetForm {

    Q_OBJECT

    public:
        explicit SeerAdaTasksBrowserWidget (QWidget* parent = 0);
       ~SeerAdaTasksBrowserWidget ();

    public slots:
        void                handleText                      (const QString& text);
        void                handleStoppingPointReached      ();
        void                refresh                         ();

    protected slots:
        void                handleItemClicked               (QTreeWidgetItem* item, int column);

    signals:
        void                refreshAdaTasks                 ();
        void                selectedThread                  (int threadid);

    protected:
        void                showEvent                       (QShowEvent* event);

    private:
};

