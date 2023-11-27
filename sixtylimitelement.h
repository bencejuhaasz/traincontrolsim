#ifndef SIXTYLIMITELEMENT_H
#define SIXTYLIMITELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class SixtyLimitElement: public FieldElement
{
public:
    SixtyLimitElement();
    ~SixtyLimitElement();
private:
    std::string whatami() override;
};

#endif // SIXTYLIMITELEMENT_H
