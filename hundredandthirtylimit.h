#ifndef HUNDREDANDTHIRTYLIMIT_H
#define HUNDREDANDTHIRTYLIMIT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class HundredAndThirtyLimit: public FieldElement
{
public:
    HundredAndThirtyLimit(Direction);
    ~HundredAndThirtyLimit();
private:
    std::string whatami() override;
};

#endif // HUNDREDANDTHIRTYLIMIT_H
