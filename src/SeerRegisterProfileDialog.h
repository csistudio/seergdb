#pragma once

#include <QtWidgets/QDialog>
#include <QString>
#include <QVector>

#include "ui_SeerRegisterProfileDialog.h"

class SeerRegisterProfileDialog : public QDialog, protected Ui::SeerRegisterProfileDialogForm {

    Q_OBJECT

    public:
        explicit SeerRegisterProfileDialog (QWidget* parent = 0);
       ~SeerRegisterProfileDialog ();

        void                        setRegisters                (const QStringList& registerNames, const QVector<bool>& registerEnabled);
        QStringList                 registerNames               () const;
        QVector<bool>               registerEnabled             () const;

        void                        setProfileName              (const QString& profileName);
        QString                     profileName                 () const;

    public slots:
         void                       accept                      ();

    private slots:
        void                        handleEnableSelected        ();
        void                        handleDisableSelected       ();
        void                        handleImportFile            ();
        void                        handleExportFile            ();

    protected:
        void                        writeSettings               ();
        void                        readSettings                ();
        void                        resizeEvent                 (QResizeEvent* event);

    private:
};

