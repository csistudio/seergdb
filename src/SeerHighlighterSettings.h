#pragma once

#include <QTextCharFormat>
#include <QList>
#include <QStringList>
#include <QString>

class SeerHighlighterSettings {

    public:
        SeerHighlighterSettings ();
        SeerHighlighterSettings (const SeerHighlighterSettings& other);
       ~SeerHighlighterSettings ();

        SeerHighlighterSettings& operator= (const SeerHighlighterSettings& rhs);

        QStringList                             keys                    () const;
        bool                                    has                     (const QString& name) const;
        QTextCharFormat                         get                     (const QString& name) const;
        void                                    add                     (const QString& name, QTextCharFormat& format);
        int                                     count                   () const;
        void                                    setSourceSuffixes       (const QString& suffixes);
        const QString&                          sourceSuffixes          ();

        static QStringList                      themeNames              ();
        static SeerHighlighterSettings          populateForCPP          (const QString& themeName);
        static SeerHighlighterSettings          populateForCPP_light    ();
        static SeerHighlighterSettings          populateForCPP_dark     ();

    private:
        QList<QString>                          _keys;
        QList<QTextCharFormat>                  _formats;
        QString                                 _sourceSuffixes;
};

