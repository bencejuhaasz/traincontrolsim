#ifndef TRAINELEMENT_H
#define TRAINELEMENT_H

#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class TrainElement : public FieldElement {
public:
    TrainElement();
    ~TrainElement();
};

#endif // TRAINELEMENT_H
