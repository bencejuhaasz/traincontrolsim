#include "thirtylimitelement.h"


ThirtyLimitElement::ThirtyLimitElement(Direction d):FieldElement(d)
{

}


ThirtyLimitElement::~ThirtyLimitElement()
{

}

std::string ThirtyLimitElement::whatami()
{
    return "ThirtyLimitElement";
}

int ThirtyLimitElement::moveTrainTo()
{
    return -1;
}

int ThirtyLimitElement::moveTrainTo(TrainElement& t){
    t.speed=30;
    return 0;
}
