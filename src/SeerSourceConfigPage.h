#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include <QStringList>

#include "ui_SeerSourceConfigPage.h"

class SeerSourceConfigPage : public QWidget, public Ui::SeerSourceConfigPage {

    Q_OBJECT

    public:
        explicit SeerSourceConfigPage (QWidget* parent = 0);
       ~SeerSourceConfigPage ();

        void                                setAlternateDirectories                 (const QStringList& alternateDirectories);
        QStringList                         alternateDirectories                    () const;

        void                                setIgnoreFilePatterns                   (const QStringList& filePatterns);
        QStringList                         ignoreFilePatterns                      () const;

        void                                setMiscFilePatterns                     (const QStringList& filePatterns);
        QStringList                         miscFilePatterns                        () const;

        void                                setSourceFilePatterns                   (const QStringList& filePatterns);
        QStringList                         sourceFilePatterns                      () const;

        void                                setHeaderFilePatterns                   (const QStringList& filePatterns);
        QStringList                         headerFilePatterns                      () const;

        void                                reset                                   ();

    protected slots:
        void                                handleAddAlternateButtonClicked         ();
        void                                handleUpAlternateButtonClicked          ();
        void                                handleDownAlternateButtonClicked        ();
        void                                handleDeleteAlternateButtonClicked      ();

        void                                handleAddIgnorePatternButtonClicked     ();
        void                                handleDeleteIgnorePatternButtonClicked  ();
        void                                handleAddMiscPatternButtonClicked       ();
        void                                handleDeleteMiscPatternButtonClicked    ();
        void                                handleAddSourcePatternButtonClicked     ();
        void                                handleDeleteSourcePatternButtonClicked  ();
        void                                handleAddHeaderPatternButtonClicked     ();
        void                                handleDeleteHeaderPatternButtonClicked  ();

    private:
};

