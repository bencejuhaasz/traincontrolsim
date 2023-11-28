#ifndef SWITCHELEMENT_H
#define SWITCHELEMENT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class SwitchElement:public FieldElement
{
public:
    SwitchElement(Direction);
    ~SwitchElement();
private:
    std::string whatami() override;
};

#endif // SWITCHELEMENT_H
