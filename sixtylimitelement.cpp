#include "sixtylimitelement.h"


SixtyLimitElement::SixtyLimitElement(Direction d):FieldElement(d)
{

}

SixtyLimitElement::~SixtyLimitElement()
{

}

std::string SixtyLimitElement::whatami()
{
    return "SixtyLimitElement";
}

int SixtyLimitElement::moveTrainTo()
{
    return -1;
}

int SixtyLimitElement::moveTrainTo(TrainElement&t){
    t.speed=60;
    return 0;
}
