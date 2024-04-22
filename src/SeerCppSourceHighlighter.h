#pragma once

#include "SeerHighlighterSettings.h"

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QString>
#include <QRegularExpression>
#include <QVector>

class SeerCppSourceHighlighter : public QSyntaxHighlighter {

    Q_OBJECT

    public:
        SeerCppSourceHighlighter (QTextDocument* parent = 0);

        const SeerHighlighterSettings&  highlighterSettings             ();
        void                            setHighlighterSettings          (const SeerHighlighterSettings& settings);

    protected:
        void                            highlightBlock                  (const QString& text) override;

    private:
        struct HighlightingRule {
            QRegularExpression pattern;
            QTextCharFormat    format;
        };

        QVector<HighlightingRule>       _highlightingRules;

        QRegularExpression              _commentStartExpression;
        QRegularExpression              _commentEndExpression;

        SeerHighlighterSettings         _highlighterSettings;
        QTextCharFormat                 _keywordFormat;
        QTextCharFormat                 _classFormat;
        QTextCharFormat                 _singleLineCommentFormat;
        QTextCharFormat                 _multiLineCommentFormat;
        QTextCharFormat                 _quotationFormat;
        QTextCharFormat                 _functionFormat;
};

