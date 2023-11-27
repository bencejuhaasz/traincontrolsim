#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class LightElement: public FieldElement
{
public:
    LightElement();
    ~LightElement();
};

#endif // LIGHTELEMENT_H
