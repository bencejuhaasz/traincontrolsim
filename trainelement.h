#ifndef TRAINELEMENT_H
#define TRAINELEMENT_H


#include "direction.h"
#include "fieldelement.h"



class TrainElement : public FieldElement {
public:
    TrainElement(Direction);
    ~TrainElement();
private:
    int speed;
    std::string whatami() override;
    int moveTrainTo() override;
    friend class SwitchElement;
    friend class ThirtyLimitElement;
    friend class SixtyLimitElement;
    friend class HundredAndThirtyLimit;
    friend class RailElement;
};

#endif // TRAINELEMENT_H
