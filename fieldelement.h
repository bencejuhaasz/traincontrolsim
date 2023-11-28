#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include "direction.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>


class FieldElement {
public:
    FieldElement(Direction);
    ~FieldElement();
protected:
    Direction d;
    int containsTrain=0; //2 yes, 1 yes in last cycle
    int click();
    virtual std::string whatami();
    virtual int moveTrainTo(); // -1 if crash, 0 ok
    virtual int removeTrain(); //decrements containsTrain



    friend class Field;
};

#endif // FIELDELEMENT_H
