#pragma once

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QIcon>
#include <QString>
#include "ui_SeerMessagesDialog.h"

class SeerMessagesDialog : public QDialog, protected Ui::SeerMessagesDialog {

    Q_OBJECT

    public:
        explicit SeerMessagesDialog (QWidget* parent = 0);
       ~SeerMessagesDialog ();

    signals:

    public slots:
        void                addMessage                      (const QString& message, QMessageBox::Icon messageType);
        void                clearMessages                   ();
        void                showMessages                    ();

    protected slots:

    protected:
        void                writeSettings                   ();
        void                readSettings                    ();
        void                resizeEvent                     (QResizeEvent* event);
        void                resetDefaultButton              ();

    private:
        QIcon               _noIcon;
        QIcon               _informationIcon;
        QIcon               _warningIcon;
        QIcon               _criticalIcon;
        QIcon               _questionIcon;
        QPushButton*        _closePushButton;
        QPushButton*        _clearPushButton;
};

