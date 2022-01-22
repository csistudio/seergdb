#pragma once

#include "SeerCppSourceHighlighter.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtGui/QPaintEvent>
#include <QtGui/QResizeEvent>
#include <QtGui/QPixmap>
#include <QtGui/QTextCursor>
#include <QtCore/QSize>
#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QVector>

class SeerEditorWidgetLineNumberArea;
class SeerEditorWidgetBreakPointArea;
class SeerEditorWidgetMiniMapArea;

class SeerEditorWidgetSourceArea : public QPlainTextEdit {

    Q_OBJECT

    public:
        SeerEditorWidgetSourceArea (QWidget* parent = 0);

        void                            enableLineNumberArea                (bool flag);
        bool                            lineNumberAreaEnabled               () const;

        void                            enableBreakPointArea                (bool flag);
        bool                            breakPointAreaEnabled               () const;

        void                            enableMiniMapArea                   (bool flag);
        bool                            miniMapAreaEnabled                  () const;

        void                            lineNumberAreaPaintEvent            (QPaintEvent* event);
        int                             lineNumberAreaWidth                 ();

        void                            breakPointAreaPaintEvent            (QPaintEvent* event);
        int                             breakPointAreaWidth                 ();

        void                            miniMapAreaPaintEvent               (QPaintEvent* event);
        int                             miniMapAreaWidth                    ();

        bool                            isOpen                              () const;
        void                            open                                (const QString& fullname, const QString& file, const QString& alternateDirectory="");
        void                            openText                            (const QString& text,     const QString& file);
        const QString&                  fullname                            () const;
        const QString&                  file                                () const;
        void                            close                               ();
        void                            setAlternateDirectory               (const QString& alternateDirectory);
        const QString&                  alternateDirectory                  () const;

        void                            setCurrentLine                      (int lineno);
        void                            scrollToLine                        (int lineno);

        void                            clearCurrentLines                   ();
        void                            addCurrentLine                      (int lineno);

        void                            clearBreakpoints                    ();
        void                            addBreakpoint                       (int number, int lineno, bool enabled);
        bool                            hasBreakpointNumber                 (int number) const;
        bool                            hasBreakpointLine                   (int lineno) const;
        const QVector<int>&             breakpointNumbers                   () const;
        const QVector<int>&             breakpointLines                     () const;
        const QVector<bool>&            breakpointEnableds                  () const;
        int                             breakpointLineToNumber              (int lineno) const;
        bool                            breakpointLineEnabled               (int lineno) const;

        void                            showContextMenu                     (QMouseEvent* event);
        void                            showContextMenu                     (QContextMenuEvent* event);
        void                            showContextMenu                     (const QPoint& pos, const QPoint& globalPos);
        void                            setQuickBreakpoint                  (QMouseEvent* event);

        void                            clearExpression                     ();

        void                            setHighlighterSettings              (const SeerHighlighterSettings& settings);
        const SeerHighlighterSettings&  highlighterSettings                 () const;
        void                            setHighlighterEnabled               (bool flag);
        bool                            highlighterEnabled                  () const;

    signals:
        void                            insertBreakpoint                    (QString breakpoint);
        void                            deleteBreakpoints                   (QString breakpoints);
        void                            enableBreakpoints                   (QString breakpoints);
        void                            disableBreakpoints                  (QString breakpoints);
        void                            runToLine                           (QString fullname, int lineno);
        void                            addVariableLoggerExpression         (QString expression);
        void                            addVariableTrackerExpression        (QString expression);
        void                            refreshVariableTrackerValues        ();
        void                            evaluateVariableExpression          (int expressionid, QString expression);
        void                            addMemoryVisualize                  (QString expression);
        void                            showSearchBar                       (bool flag);
        void                            showAlternateBar                    (bool flag);
        void                            highlighterSettingsChanged          ();

    public slots:
        void                            handleText                          (const QString& text);
        void                            handleHighlighterSettingsChanged    ();


    protected:
        void                            resizeEvent                         (QResizeEvent* event);
        void                            contextMenuEvent                    (QContextMenuEvent* event);
        void                            keyPressEvent                       (QKeyEvent* event);
        void                            mouseReleaseEvent                   (QMouseEvent* event);
        bool                            event                               (QEvent* event);

    private slots:
        void                            highlightCurrentLines               ();
        void                            highlightCurrentLine                ();
        void                            unhighlightCurrentLine              ();

        void                            updateMarginAreasWidth              (int newBlockCount);
        void                            updateLineNumberArea                (const QRect& rect, int dy);
        void                            updateBreakPointArea                (const QRect& rect, int dy);
        void                            updateMiniMapArea                   (const QRect& rect, int dy);

    private:
        QString                         _fullname;
        QString                         _file;
        QString                         _alternateDirectory;

        bool                            _enableLineNumberArea;
        bool                            _enableBreakPointArea;
        bool                            _enableMiniMapArea;
        QVector<int>                    _breakpointsNumbers;
        QVector<int>                    _breakpointsLineNumbers;
        QVector<bool>                   _breakpointsEnableds;
        QVector<QTextCursor>            _currentLineCursors;

        QTextCursor                     _selectedExpressionCursor;
        int                             _selectedExpressionId;
        QString                         _selectedExpressionName;
        QString                         _selectedExpressionValue;
        bool                            _ctrlKeyPressed;

        SeerEditorWidgetLineNumberArea* _lineNumberArea;
        SeerEditorWidgetBreakPointArea* _breakPointArea;
        SeerEditorWidgetMiniMapArea*    _miniMapArea;

        QPixmap*                        _miniMapPixmap;
        SeerCppSourceHighlighter*       _sourceHighlighter;
        SeerHighlighterSettings         _sourceHighlighterSettings;
        bool                            _sourceHighlighterEnabled;
};

class SeerEditorWidgetLineNumberArea : public QWidget {

    Q_OBJECT

    public:
        SeerEditorWidgetLineNumberArea (SeerEditorWidgetSourceArea* editorWidget);

        QSize                           sizeHint                            () const override;

    protected:
        void                            paintEvent                          (QPaintEvent* event) override;
        void                            mouseDoubleClickEvent               (QMouseEvent* event) override;
        void                            mouseMoveEvent                      (QMouseEvent* event) override;
        void                            mousePressEvent                     (QMouseEvent* event) override;
        void                            mouseReleaseEvent                   (QMouseEvent* event) override;

    private:
        SeerEditorWidgetSourceArea*     _editorWidget;
};

class SeerEditorWidgetBreakPointArea : public QWidget {

    Q_OBJECT

    public:
        SeerEditorWidgetBreakPointArea (SeerEditorWidgetSourceArea* editorWidget);

        QSize                           sizeHint                            () const override;

    protected:
        void                            paintEvent                          (QPaintEvent* event) override;
        void                            mouseDoubleClickEvent               (QMouseEvent* event) override;
        void                            mouseMoveEvent                      (QMouseEvent* event) override;
        void                            mousePressEvent                     (QMouseEvent* event) override;
        void                            mouseReleaseEvent                   (QMouseEvent* event) override;

    private:
        SeerEditorWidgetSourceArea*     _editorWidget;
};

class SeerEditorWidgetMiniMapArea : public QWidget {

    Q_OBJECT

    public:
        SeerEditorWidgetMiniMapArea (SeerEditorWidgetSourceArea* editorWidget);

        QSize                           sizeHint                            () const override;

    protected:
        void                            paintEvent                          (QPaintEvent* event) override;
        void                            mouseDoubleClickEvent               (QMouseEvent* event) override;
        void                            mouseMoveEvent                      (QMouseEvent* event) override;
        void                            mousePressEvent                     (QMouseEvent* event) override;
        void                            mouseReleaseEvent                   (QMouseEvent* event) override;

    private:
        SeerEditorWidgetSourceArea*     _editorWidget;
};

#include "ui_SeerEditorWidget.h"

class SeerEditorWidget : public QWidget, protected Ui::SeerEditorWidgetForm {

    Q_OBJECT

    public:
        explicit SeerEditorWidget (QWidget* parent = 0);
       ~SeerEditorWidget ();

        SeerEditorWidgetSourceArea*             sourceArea                          ();

        void                                    handleSearchLineNumberLineEdit      ();
        void                                    handleSearchTextLineEdit            ();
        void                                    handleSearchDownToolButton          ();
        void                                    handleSearchUpToolButton            ();
        void                                    handleSearchCloseToolButton         ();
        void                                    handleAlternateCloseToolButton      ();
        void                                    handleAlternateFileOpenToolButton   ();
        void                                    handleAlternateAcceptToolButton     ();

    public slots:
        void                                    showSearchBar                       (bool flag);
        bool                                    isSearchBarShown                    () const;
        void                                    showAlternateBar                    (bool flag);
        bool                                    isAlternateBarShown                 () const;
};

