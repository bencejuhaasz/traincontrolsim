#include "trainelement.h"


TrainElement::TrainElement(Direction d):FieldElement(d)
{
    speed=1;
    containsTrain=true;
}


TrainElement::~TrainElement()
{

}

std::string TrainElement::whatami()
{
    return "TrainElement";
}

int TrainElement::moveTrainTo()
{
    return -1;
}
