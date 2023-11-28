#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class LightElement: public FieldElement
{
public:
    LightElement(Direction);
    ~LightElement();
private:
    std::string whatami() override;
};

#endif // LIGHTELEMENT_H
