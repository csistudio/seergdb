#pragma once

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QString>
#include <QRegularExpression>
#include <QVector>

class SeerCxxSourceHighlighter : public QSyntaxHighlighter {

    Q_OBJECT

    public:
        SeerCxxSourceHighlighter (QTextDocument* parent = 0);

    protected:
        void            highlightBlock                  (const QString& text) override;
        int             highlight                       (const QString& text, int state);

        static bool     isCppKeyword                    (const QString& word);
};

