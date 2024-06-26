#pragma once

#include <QtWidgets/QDialog>
#include <QString>

#include "ui_SeerSlashProcDialog.h"

class SeerSlashProcDialog : public QDialog, protected Ui::SeerSlashProcDialogForm {

    Q_OBJECT

    public:
        explicit SeerSlashProcDialog (QWidget* parent = 0);
       ~SeerSlashProcDialog ();

        int                 selectedPid                 () const;
        QString             selectedName                () const;
        QString             selectedFullname            () const;
        QString             selectedCommandLine         () const;

    public slots:
    private slots:
        void                handlePidSelected           ();

    private:
};

