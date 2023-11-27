#ifndef SWITCHELEMENT_H
#define SWITCHELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class SwitchElement:public FieldElement
{
public:
    SwitchElement();
    ~SwitchElement();
};

#endif // SWITCHELEMENT_H
