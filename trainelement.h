#ifndef TRAINELEMENT_H
#define TRAINELEMENT_H

#include "direction.h"
#include "fieldelement.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class TrainElement : public FieldElement {
public:
    TrainElement(Direction);
    ~TrainElement();
private:
    std::string whatami() override;
};

#endif // TRAINELEMENT_H
