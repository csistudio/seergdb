#pragma once

#include <QtWidgets/QWidget>
#include <QTextCursor>
#include <QResizeEvent>
#include <QString>
#include <QSocketNotifier>
#include "ui_SeerConsoleWidget.h"

class SeerConsoleWidget : public QWidget, protected Ui::SeerConsoleWidgetForm {

    Q_OBJECT

    public:
        explicit SeerConsoleWidget (QWidget* parent = 0);
       ~SeerConsoleWidget ();

        const QString&      ttyDeviceName               () const;
        void                connectConsole              ();
        void                disconnectConsole           ();

        void                setScrollLines              (int count);
        int                 scrollLines                 () const;

        void                setMode                     (const QString& mode);
        QString             mode                        () const;

    public slots:
        void                handleChangeWindowTitle     (QString title);

    protected slots:
        void                handleClearButton           ();
        void                handlePrintButton           ();
        void                handleSaveButton            ();
        void                handleFontButton            ();
        void                handleWrapTextCheckBox      ();
        void                handleStdinLineEdit         ();
        void                handleConsoleOutput         (int socketfd);

    protected:
        void                handleText                  (const char* buffer, int count);
        void                createConsole               ();
        void                deleteConsole               ();
        void                writeSettings               ();
        void                readSettings                ();
        void                resizeEvent                 (QResizeEvent* event);

    private:
        QString             _mode;
        QTextCursor         _cursor;
        QString             _ttyDeviceName;
        int                 _ptsFD;
        QSocketNotifier*    _ptsListener;
};

