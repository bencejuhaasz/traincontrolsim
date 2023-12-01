#ifndef HUNDREDANDTHIRTYLIMIT_H
#define HUNDREDANDTHIRTYLIMIT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"



class HundredAndThirtyLimit: public FieldElement
{
public:
    HundredAndThirtyLimit(Direction);
    ~HundredAndThirtyLimit();
private:
    std::string whatami() override;
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&);
};

#endif // HUNDREDANDTHIRTYLIMIT_H
