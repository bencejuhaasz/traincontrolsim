#ifndef SIXTYLIMITELEMENT_H
#define SIXTYLIMITELEMENT_H

#include "trainelement.h"
#include "direction.h"
#include "fieldelement.h"



class SixtyLimitElement: public FieldElement
{
public:
    SixtyLimitElement(Direction);
    ~SixtyLimitElement();
private:
    std::string whatami() override;
    int moveTrainTo() override;
    int moveTrainTo(TrainElement&);
};

#endif // SIXTYLIMITELEMENT_H
