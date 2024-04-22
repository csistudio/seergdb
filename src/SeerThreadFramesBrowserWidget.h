#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include "ui_SeerThreadFramesBrowserWidget.h"

class SeerThreadFramesBrowserWidget : public QWidget, protected Ui::SeerThreadFramesBrowserWidgetForm {

    Q_OBJECT

    public:
        explicit SeerThreadFramesBrowserWidget (QWidget* parent = 0);
       ~SeerThreadFramesBrowserWidget ();

    public slots:
        void                handleText                      (const QString& text);
        void                handleStoppingPointReached      ();
        void                refresh                         ();

    protected slots:
        void                handleItemClicked               (QTreeWidgetItem* item, int column);
        void                handleItemEntered               (QTreeWidgetItem* item, int column);
        void                handleGdbNextToolButton         ();
        void                handleGdbStepToolButton         ();
        void                handleGdbFinishToolButton       ();
        void                handleGdbContinueToolButton     ();
        void                handleGdbInterruptToolButton    ();

    signals:
        void                refreshThreadFrames             ();
        void                refreshThreadIds                ();
        void                selectedFile                    (QString file, QString fullname, int lineno);
        void                selectedFrame                   (int frameno);
        void                selectedThread                  (int threadid);
        void                nextThreadId                    (int threadid);
        void                stepThreadId                    (int threadid);
        void                finishThreadId                  (int threadid);
        void                continueThreadId                (int threadid);
        void                interruptThreadId               (int threadid);

    protected:
        void                showEvent                       (QShowEvent* event);

    private:
};

