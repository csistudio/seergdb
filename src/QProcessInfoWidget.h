#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include "ui_QProcessInfoWidget.h"

class QProcessInfoWidget : public QWidget, protected Ui::QProcessInfoWidget {

    Q_OBJECT

    public:
        explicit QProcessInfoWidget (QWidget* parent = 0);
       ~QProcessInfoWidget ();

        int                 selectedPid                     () const;
        QString             selectedUsername                () const;
        QString             selectedName                    () const;
        QString             selectedFullname                () const;
        QString             selectedCommandLine             () const;

    signals:
        void                pidSelected                     (int pid);

    public slots:

    protected slots:
        void                refreshList                     ();
        void                refreshView                     ();
        void                handleDoubleClicked             ();

    protected:
    private:
};

