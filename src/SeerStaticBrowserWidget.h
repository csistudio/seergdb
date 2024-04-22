#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include "ui_SeerStaticBrowserWidget.h"

class SeerStaticBrowserWidget : public QWidget, protected Ui::SeerStaticBrowserWidgetForm {

    Q_OBJECT

    public:
        explicit SeerStaticBrowserWidget (QWidget* parent = 0);
       ~SeerStaticBrowserWidget ();

    public slots:
        void                handleText                  (const QString& text);
        void                refresh                     ();

    protected slots:
        void                handleSearchLineEdit        ();
        void                handleItemDoubleClicked     (QTreeWidgetItem* item, int column);
        void                handleItemEntered           (QTreeWidgetItem* item, int column);

    signals:
        void                refreshVariableList         (int id, const QString& staticNameRegex, const QString& staticTypeRegex);
        void                selectedFile                (QString file, QString fullname, int lineno);

    protected:
    private:
        int                 _id;
};

