#pragma once

#include "SeerEditorWidgetSource.h"
#include <QString>
#include <QMap>
#include <QVector>

struct SeerEditorManagerEntry {
    QString                   fullname;
    QString                   file;
    SeerEditorWidgetSource*   widget;
};

typedef QMap<QString,SeerEditorManagerEntry> SeerEditorManagerEntries;

struct SeerEditorManagerFile {
    QString             fullname;
    QString             file;
};

typedef QVector<SeerEditorManagerFile> SeerEditorManagerFiles;

