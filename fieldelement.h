#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include "direction.h"
#include <string>


class FieldElement {
public:
    FieldElement(Direction);
    ~FieldElement();
protected:
    Direction d;
    bool containsTrain=false; //2 yes, 1 yes in last cycle
    virtual int click();
    virtual std::string whatami();
    virtual int moveTrainTo(); // -1 if crash, 0 ok
    int addTrain();
    int removeTrain();



    friend class Field;
};

#endif // FIELDELEMENT_H
