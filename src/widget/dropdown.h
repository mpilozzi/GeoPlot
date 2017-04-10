#ifndef DROPDOWN_H
#define DROPDOWN_H

#include <QMenu>
#include "src/widget/targets/target.h"

class Dropdown : public QMenu
{
    Q_OBJECT

    public:
        Dropdown(Target *tar);
};

#endif // DROPDOWN_H
