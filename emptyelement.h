#ifndef EMPTYELEMENT_H
#define EMPTYELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class EmptyElement: public FieldElement
{
public:
    EmptyElement();
    ~EmptyElement();
private:
    std::string whatami() override;
};

#endif // EMPTYELEMENT_H
