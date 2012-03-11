#ifndef EDITORS_GLOBAL_H
#define EDITORS_GLOBAL_H

#include "../plugins/ifaces.h"

struct EditedFile {
    QFileInfo fi;
    QWidget *widget;
    IEditors *editorInterface;
};

#endif // EDITORS_GLOBAL_H
