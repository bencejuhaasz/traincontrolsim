#ifndef RAILELEMENT_H
#define RAILELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class RailElement: public FieldElement
{
public:
    RailElement();
    ~RailElement();
};

#endif // RAILELEMENT_H
