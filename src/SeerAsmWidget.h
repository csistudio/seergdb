#pragma once

#include "ui_SeerAsmWidget.h"

class SeerAsmWidget: public QWidget, protected Ui::SeerAsmWidgetForm {

    Q_OBJECT

    public:

        SeerAsmWidget(QWidget* parent = 0);
       ~SeerAsmWidget();

    signals:

    public slots:
        void                        setData                             (const QString& data);

    protected:

    protected slots:

    private:
};

