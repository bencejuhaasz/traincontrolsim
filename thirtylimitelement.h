#ifndef THIRTYLIMITELEMENT_H
#define THIRTYLIMITELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"



class ThirtyLimitElement:public FieldElement
{
public:
    ThirtyLimitElement(Direction);
    ~ThirtyLimitElement();
private:
    std::string whatami() override;
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&t);
};

#endif // THIRTYLIMITELEMENT_H
