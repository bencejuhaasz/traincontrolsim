#ifndef THIRTYLIMITELEMENT_H
#define THIRTYLIMITELEMENT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class ThirtyLimitElement:public FieldElement
{
public:
    ThirtyLimitElement(Direction);
    ~ThirtyLimitElement();
private:
    std::string whatami() override;
};

#endif // THIRTYLIMITELEMENT_H
