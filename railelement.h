#ifndef RAILELEMENT_H
#define RAILELEMENT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class RailElement: public FieldElement
{
public:
    RailElement(Direction);
    ~RailElement();
private:
    std::string whatami() override;
};

#endif // RAILELEMENT_H
